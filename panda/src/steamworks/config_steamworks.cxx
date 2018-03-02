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

#include "config_steamworks.h"
#include "dconfig.h"

#include "steamworksManager.h"

Configure(config_steamworks);
NotifyCategoryDef(steamworks, "");

ConfigureFn(config_steamworks) {
  init_steamworks();
}

ConfigVariableInt steamworks_app_id 
("steamworks-app-id", 480,
 PRC_DESC("Defines the steam app id used by this application. This is used"
          "to interact with Steam services through Steamworks"));

/**
 * Initializes the library.  This must be called at least once before any of
 * the functions or classes in this library can be used.  Normally it will be
 * called by the static initializers and need not be called explicitly, but
 * special cases exist.
 */
void
init_steamworks() {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;

  SteamworksManager::init_type();
}