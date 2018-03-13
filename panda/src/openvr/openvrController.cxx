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

OpenVRController::OpenVRController(const string &name, DeviceClass dev_class) 
    : OpenVRDevice(name, dev_class, vr::TrackedDeviceClass_Controller) {

    // Set the mappings and initial state of the hand controllers.
    if (dev_class == DC_right_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration;
    } else if (dev_class == DC_left_hand) {
        _flags |= IDF_has_tracker | IDF_has_vibration;
    }
}