/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrController.cxx
 * @author thetestgame
 * @date 2018-03-11
 */

#include "openvrController.h"

TypeHandle OpenVRController::_type_handle;

/**
 * 
 */
OpenVRController::OpenVRController(const string &name, DeviceClass dev_class) 
    : OpenVRDevice(name, dev_class, vr::TrackedDeviceClass_Controller) {

    // Set the mappings and initial state of the hand controllers.
    if (dev_class == DC_right_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration;
    } else if (dev_class == DC_left_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration;
    }
}

/**
 * Polls the input device for new activity, to ensure it contains the latest
 * events.  This will only have any effect for some types of input devices;
 * others may be updated automatically, and this method will be a no-op.
 */
void OpenVRController::do_poll() {

    // Perform OpenVR device core loop tasks
    OpenVRDevice::do_poll();
}

/**
 * Triggers a single haptic pulse on a controller on a axis for a specified amount of time
 * 
 * Note: After this call the application may not trigger another haptic pulse on this controller 
 * and axis combination for 5ms.
 */
void OpenVRController::trigger_haptic_pulse(uint32_t axis_id, unsigned short duration_micro_sec) {

    if (!_is_connected) {
        // We are not connected. Do nothing
        return;
    }

    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();
    std::cerr << "Trigger haptic pulse on device: " << device_index << "\n";
    vrMgr->vr_system->TriggerHapticPulse(device_index, axis_id, duration_micro_sec);
}