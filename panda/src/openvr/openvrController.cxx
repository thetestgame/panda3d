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
#include "gamepadButton.h"

TypeHandle OpenVRController::_type_handle;

/**
 * 
 */
OpenVRController::OpenVRController(const string &name, DeviceClass dev_class) 
    : OpenVRDevice(name, dev_class, vr::TrackedDeviceClass_Controller) {

    // Set the mappings and initial state of the hand controllers.
    _buttons.resize(3);
    if (dev_class == DC_right_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration | IDF_has_battery;

        _buttons[0].handle = GamepadButton::action_a();
        _buttons[1].handle = GamepadButton::action_b();
        _buttons[2].handle = GamepadButton::rstick();

        _controls.resize(3);
        _controls[0].axis = C_right_x;
        _controls[0].known = true;
        _controls[1].axis = C_right_y;
        _controls[1].known = true;
        _controls[2].axis = C_right_trigger;
        _controls[2].known = true;

    } else if (dev_class == DC_left_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration | IDF_has_battery;

        _buttons[0].handle = GamepadButton::action_x();
        _buttons[1].handle = GamepadButton::action_y();
        _buttons[2].handle = GamepadButton::lstick();

        _controls.resize(3);
        _controls[0].axis = C_left_x;
        _controls[0].known = true;
        _controls[1].axis = C_left_y;
        _controls[1].known = true;
        _controls[2].axis = C_left_trigger;
        _controls[2].known = true;
    }
}

/**
 * Polls the input device for new activity, to ensure it contains the latest
 * events.  This will only have any effect for some types of input devices;
 * others may be updated automatically, and this method will be a no-op.
 */
void OpenVRController::do_poll() {
    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();

    vr::VRControllerState_t state;
    if (vrMgr->vr_system->GetControllerState(device_index, &state, sizeof(vr::VRControllerState_t))) {

        //Check if the input has changed before modifying button states
        if (state.unPacketNum != _last_input_packet_number) {
            _last_input_packet_number = state.unPacketNum;

            if (openvr_cat.is_spam()) {
                openvr_cat.spam() << "Device (" << device_index 
                    << ") Button input changed:" << state.ulButtonPressed << "\n";
            }
            
            //TODO: Match these ids with enums from OpenVR? vr::EVRButtonId does not seem to match
            button_changed(0, ((state.ulButtonPressed & 2) == 2));
            button_changed(1, ((state.ulButtonPressed & 4) == 4));

            //TODO: Match these ids with enums from OpenVR? vr::EVRControllerAxisType does not match
            // Possibly manually match with pVRSystem->Get( nControllerDeviceIndex, Prop_Axis0Type_Int32 + n );?
            vr::VRControllerAxis_t joystick = state.rAxis[0];
            vr::VRControllerAxis_t trigger = state.rAxis[1];

            if (is_right_hand()) {
                set_control_state(C_right_x, joystick.x);
                set_control_state(C_right_y, joystick.y);
                set_control_state(C_right_trigger, trigger.x);
            } else {
                set_control_state(C_left_x, joystick.x);
                set_control_state(C_left_y, joystick.y);
                set_control_state(C_left_trigger, trigger.x);
            }
        }
        // Perform OpenVR device core loop tasks
        OpenVRDevice::do_poll();
    }
}

/**
 * Returns true if the controller is assigned to the left hand
 */
bool OpenVRController::is_left_hand() {
    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();
    int left_index = vrMgr->vr_system->GetTrackedDeviceIndexForControllerRole(vr::ETrackedControllerRole::TrackedControllerRole_LeftHand);
    return left_index == device_index;
}

/**
 * Returns true if the controller is assigned to the right hand
 */
bool OpenVRController::is_right_hand() {
    OpenVRSystem* vrMgr = OpenVRSystem::get_global_ptr();
    int right_index = vrMgr->vr_system->GetTrackedDeviceIndexForControllerRole(vr::ETrackedControllerRole::TrackedControllerRole_RightHand);
    return right_index == device_index;
}