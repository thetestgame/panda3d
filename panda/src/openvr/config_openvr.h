/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_openvr.h
 * @author thetestgame
 * @date 2018-03-09
 */

#ifndef CONFIG_OPENVR_H
#define CONFIG_OPENVR_H

#include "pandabase.h"
#include "notifyCategoryProxy.h"

NotifyCategoryDecl(openvr, EXPCL_OPENVR, EXPTP_OPENVR);

extern EXPCL_OPENVR void init_openvr();

#endif