/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrBaseStation.cxx
 * @author thetestgame
 * @date 2018-03-12
 */

#include "openvrBaseStation.h"

TypeHandle OpenVRBaseStation::_type_handle;

OpenVRBaseStation::OpenVRBaseStation(const string &name) 
    : OpenVRDevice(name, DC_generic_tracker, vr::TrackedDeviceClass_TrackingReference) {}


OpenVRBaseStation::~OpenVRBaseStation() {}