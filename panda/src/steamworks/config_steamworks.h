/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_steamworks.h
 * @author thetestgame
 * @date 2018-2-28
 */

#ifndef CONFIG_STEAMWORKS_H
#define CONFIG_STEAMWORKS_H

#include "pandabase.h"
#include "notifyCategoryProxy.h"
#include "configVariableInt.h"
#include "steamworksManager.h"

NotifyCategoryDecl(steamworks, EXPCL_STEAMWORKS, EXPTP_STEAMWORKS);

extern EXPCL_STEAMWORKS ConfigVariableInt steamworks_app_id;

extern EXPCL_STEAMWORKS void init_steamworks();

#endif