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
    shutdown();
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
                    //TODO: write down information regarding which hand this controller is asigned to
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

    _vr_initialized = true;
    return eError;
}

/**
 * Shuts down the OpenVR library
 */
void OpenVRSystem::shutdown() {
    openvr_cat.info() << "Shutting down openvr" << std::endl;
    if (_vr_initialized) {
        vr::VR_Shutdown();
        _vr_initialized = false;
    }
}

/**
 * Sets the zero pose for the seated tracker coordinate system to the current position and yaw of the HMD.
 */
void OpenVRSystem::reset_seated_zone_pose() {

    if (!_vr_initialized) {
        return; //Not initialized. Nothing to do
    }

    vr_system->ResetSeatedZeroPose();
}

/**
 * Captures a Stereographic virtual reality screenshot 
 */
vr::EVRScreenshotError take_stereo_screenshot(const Filename &preview_file_path, const Filename &vr_file_path) {

    if (!_vr_initialized) {
        //Not initialized. Nothing to do
        return vr::EVRScreenshotError::VRScreenshotError_RequestFailed;; 
    }

    if (!vr::VRScreenshots()) {
        openvr_cat.error() << "Unable to retrieve interface for VRScreenshot API\n";
        return vr::EVRScreenshotError::VRScreenshotError_RequestFailed;
    }

    if (preview_file_path.empty() || vr_file_path.empty())
    {
        openvr_cat.error() << "File path is empty: preview (" <<
            preview_file_path.c_str() << ") VR (" << vr_file_path.c_str() << ")\n";
        return vr::EVRScreenshotError::VRScreenshotError_RequestFailed;
    }

     vr::ScreenshotHandle_t handle;
     vr::EVRScreenshotError err = vr::VRScreenshots()->TakeStereoScreenshot(
         &handle,
         preview_file_path.c_str(),
         vr_file_path.c_str());

    return err;
}