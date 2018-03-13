/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file OpenVRSystem.cxx
 * @author thetestgame
 * @date 2018-03-09
 */

#include "OpenVRSystem.h"
#include "inputDeviceManager.h"
#include "asyncTaskManager.h"
#include "eventParameter.h"
#include "throw_event.h"
#include "openvr.h"

OpenVRSystem* OpenVRSystem::_global_ptr;
TypeHandle OpenVRSystem::_type_handle;

/**
 * Retrieves the OpenVRSystem global pointer
 */
OpenVRSystem* OpenVRSystem::get_global_ptr() {
    if (_global_ptr == NULL) {
        // A instance has not yet been set. Create one
        _global_ptr = new OpenVRSystem();
    }

    return _global_ptr;
}

/**
 *
 */
OpenVRSystem::OpenVRSystem() {}

/**
 *
 */
OpenVRSystem::~OpenVRSystem() {
    openvr_cat.info() << "Shutting down openvr" << std::endl;
    if (_vr_initialized) {
        vr::VR_Shutdown();
        _vr_initialized = false;
    }
}

/**
 * 
 */
void OpenVRSystem::update() {

    if (!_vr_initialized) {
        // Virtual Reality not ready. Do nothing.
        return;
    }

    // Update connected OpenVR devices
    InputDeviceManager *inputMgr = InputDeviceManager::get_global_ptr();
    for (int device_index = 0; device_index < vr::k_unMaxTrackedDeviceCount; ++device_index)
	{
        if (vr_system->IsTrackedDeviceConnected(device_index) && openvr_devices[device_index] == nullptr) {
            vr::ETrackedDeviceClass device_class = vr_system->GetTrackedDeviceClass(device_index);
            OpenVRDevice* new_device = nullptr;
            switch(device_class) {
                case vr::TrackedDeviceClass_HMD:
                    new_device = new OpenVRHmd();
                    break;
                case vr::TrackedDeviceClass_Controller:
                    //TODO
                    new_device = new OpenVRController("OpenVR Left Controller", InputDevice::DeviceClass::DC_left_hand);
                    break;
                case vr::TrackedDeviceClass_TrackingReference:
                    new_device = new OpenVRBaseStation("Base Station");
                    break;
            }

            if (new_device != nullptr) {
                if (openvr_cat.is_debug())
                    openvr_cat.debug() << "Registering new OpenVR device (" << device_index << ")\n";

                new_device->device_index = device_index;
                inputMgr->add_device(new_device);
                openvr_devices[device_index] = new_device;
            }
        }


        OpenVRDevice* device = openvr_devices[device_index];
        if (device != nullptr) {
            
            //Check if the device is still connected
            if (!device->is_connected()) {

                if (openvr_cat.is_debug())
                    openvr_cat.debug() << "Removing OpenVR device (" << device_index << ")\n";

                inputMgr->remove_device(device);
                delete device;
                device = nullptr;

                openvr_devices[device_index] = nullptr;
            }
        }
    }

    // Update device positions
    vr::VRCompositor()->WaitGetPoses(tracked_device_positions, vr::k_unMaxTrackedDeviceCount, NULL, 0);

    // Process events
    vr::VREvent_t event;
    while (vr_system->PollNextEvent(&event, sizeof(event)))
        throw_event("vr-event", EventParameter(vr::EVREventType(event.eventType)));
}

/**
 * Initializes the OpenVR library
 */
vr::EVRInitError OpenVRSystem::init() {
        
    // Startup OpenVR
    vr::EVRInitError eError = vr::VRInitError_None;
    vr_system = vr::VR_Init(&eError, vr::VRApplication_Scene);

    if (eError != vr::VRInitError_None)
    {
        vr_system = nullptr;
        openvr_cat.error() << "Unable to init VR runtime: " << vr::VR_GetVRInitErrorAsEnglishDescription(eError) << "\n";
        return eError;
    }

    if (!vr::VR_GetGenericInterface(vr::IVRRenderModels_Version, &eError))
    {
        vr_system = nullptr;
        vr::VR_Shutdown();

        openvr_cat.error() <<  "Unable to get render model interface: " << vr::VR_GetVRInitErrorAsEnglishDescription(eError) << "\n";
        return eError;
    }

    // Register the HMD device with the InputDeviceManager
    if (!vr_system->IsTrackedDeviceConnected(vr::k_unTrackedDeviceIndex_Hmd)) {
        vr_system = nullptr;
        vr::VR_Shutdown();

        openvr_cat.error() << "Unable to retrieve HMD device; Device is not connected.\n";
        return vr::VRInitError_Init_HmdNotFound;
    }

    /*
    OpenVRHmd* hmd_device = new OpenVRHmd();
    InputDeviceManager *inputMgr = InputDeviceManager::get_global_ptr();
    inputMgr->add_device(hmd_device);
    openvr_devices[vr::k_unTrackedDeviceIndex_Hmd] = hmd_device;
    */

    _vr_initialized = true;
    return eError;
}

/**
 * Shuts down the openvr API and frees the global pointer
 */
void OpenVRSystem::shutdown() {
    // Remove the Pointer
    delete _global_ptr;
    _global_ptr = NULL;
}
