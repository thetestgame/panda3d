/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_openvr.cxx
 * @author thetestgame
 * @date 2018-03-09
 */

#include "config_openvr.h"
#include "pandaSystem.h"
#include "dconfig.h"

#include "openvrDevice.h"
#include "openvrController.h"
#include "openvrHmd.h"
#include "openvrBaseStation.h"
#include "openvrSystem.h"

Configure(config_openvr);
NotifyCategoryDef(openvr, "");

ConfigureFn(config_openvr) {
    init_openvr();
}

/**
 * Initializes the library.  This must be called at least once before any of
 * the functions or classes in this library can be used.  Normally it will be
 * called by the static initializers and need not be called explicitly, but
 * special cases exist.
 */
void init_openvr() {
    static bool initialized = false;
    if (initialized) {
        return;
    }
    initialized = true;

    OpenVRDevice::init_type();
    OpenVRController::init_type();
    OpenVRHmd::init_type();
    OpenVRBaseStation::init_type();
    OpenVRSystem::init_type();
}