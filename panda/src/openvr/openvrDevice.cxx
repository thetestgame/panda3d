/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrDevice.cxx
 * @author thetestgame
 * @date 2018-03-11
 */
#include "openvrDevice.h"
#include "inputDeviceManager.h"
#include "geomTriangles.h"
#include "geomNode.h"
#include "texture.h"
#include "textureAttrib.h"
#include "geomVertexWriter.h"

TypeHandle OpenVRDevice::_type_handle;

/**
 * 
 */
OpenVRDevice::OpenVRDevice(const string &name, DeviceClass dev_class, vr::ETrackedDeviceClass openvr_class) 
    : InputDevice(name, dev_class, 0)  {
    ovr_device_class = openvr_class;

    _name = get_system_name();
    _serial_number = get_serial_number();

    _max_battery_level = 1;
}

/**
 * 
 */
OpenVRDevice::~OpenVRDevice() {}

/**
 * Polls the input device for new activity, to ensure it contains the latest
 * events.  This will only have any effect for some types of input devices;
 * others may be updated automatically, and this method will be a no-op.
 */
void OpenVRDevice::do_poll() {
    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();

    // Verify OpenVR is still running; Otherwise remove this device
    if (!vrMgr->get_vr_initialized() && _is_connected) {
        _is_connected = false;
    }

    // Check whether this device is still connected.
    bool connected = vrMgr->vr_system->IsTrackedDeviceConnected(device_index);
    if (connected != _is_connected) {
        if (!connected) {
            _is_connected = false;
        } else {
            _is_connected = true;
        }
    }

    if (!_is_connected) {
        return;
    }

    update_properties();
    process_tracking();
}

/**
 * 
 */
void OpenVRDevice::update_properties() {
    //TODO: Pull device properties into InputDevice
}

/**
 * Applies the tracked position to the InputDevice
 */
void OpenVRDevice::process_tracking() {
    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();

    if (!vrMgr->tracked_device_positions[device_index].bPoseIsValid) {
        // The device can not be seen by the sensors. Ignore tracking
        return;
    }

    vr::HmdMatrix34_t matrix = vrMgr->tracked_device_positions[device_index].mDeviceToAbsoluteTracking;
    LPoint3 pos(-matrix.m[0][3], matrix.m[2][3], matrix.m[1][3]);

    vr::HmdQuaternion_t q;
    q.w = sqrt(fmax(0, 1 + matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2])) / 2;
    q.x = sqrt(fmax(0, 1 + matrix.m[0][0] - matrix.m[1][1] - matrix.m[2][2])) / 2;
    q.y = sqrt(fmax(0, 1 - matrix.m[0][0] + matrix.m[1][1] - matrix.m[2][2])) / 2;
    q.z = sqrt(fmax(0, 1 - matrix.m[0][0] - matrix.m[1][1] + matrix.m[2][2])) / 2;
    q.x = copysign(q.x, matrix.m[2][1] - matrix.m[1][2]);
    q.y = copysign(q.y, matrix.m[0][2] - matrix.m[2][0]);
    q.z = copysign(q.z, matrix.m[1][0] - matrix.m[0][1]);
    LOrientation orient(q.w, q.x, -q.z, q.y);

    int real_time = ClockObject::get_global_clock()->get_real_time();
    set_tracker(pos, orient, real_time);
}

/**
 * Returns the requested device property using the openvr ETrackedDeviceProperty enum
 */
string OpenVRDevice::get_device_property(vr::ETrackedDeviceProperty prop) {
    PT(OpenVRSystem) manager = OpenVRSystem::get_global_ptr();
    char property[1024];
    manager->vr_system->GetStringTrackedDeviceProperty(device_index, prop, property, sizeof(property));

    return std::string(property);
}

