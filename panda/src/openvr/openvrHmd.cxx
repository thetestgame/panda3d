/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrHmd.cxx
 * @author thetestgame
 * @date 2018-03-11
 */
#include "openvrHmd.h"
#include "openvr.h"

TypeHandle OpenVRHmd::_type_handle;

/**
 *
 */
OpenVRHmd::OpenVRHmd()
    : OpenVRDevice("OpenVR HMD", DC_hmd, vr::TrackedDeviceClass_HMD) {
    _flags |= IDF_has_tracker;
    device_index = vr::k_unTrackedDeviceIndex_Hmd;
}

/**
 *
 */
OpenVRHmd::~OpenVRHmd() {}