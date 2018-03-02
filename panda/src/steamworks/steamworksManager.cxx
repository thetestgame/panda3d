/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file steamworksManager.cxx
 * @author thetestgame
 * @date 2018-3-1
 */
#include "steamworksManager.h"

SteamworksManager* SteamworksManager::_global_ptr;
TypeHandle SteamworksManager::_type_handle;

SteamworksManager* SteamworksManager::get_global_ptr() {
    if (_global_ptr == NULL) {
        // A instance has not yet been set. Create one
        _global_ptr = new SteamworksManager();
    }

    return _global_ptr;
}

SteamworksManager::SteamworksManager() {}

SteamworksManager::~SteamworksManager() {
    steamworks_cat.info() << "Shutting down Steamworks" << std::endl;
    if (_api_initialized) {
        SteamAPI_Shutdown();

       _api_initialized = false;
    }
}

/**
 * Shuts down the Steamworks API and frees the global pointer
 */
void SteamworksManager::shutdown() {
    // Remove the Pointer
    delete _global_ptr;
    _global_ptr = NULL;
}

/*
 * Initializes the SteamWorks SteamAPI
 */
int SteamworksManager::steam_init() {
    steamworks_cat.debug() << "Connecting to Steam" << std::endl;

    int init_response = 0;
    if (!_api_initialized) {

        if (SteamAPI_RestartAppIfNecessary(steamworks_app_id))
        {
            // if Steam is not running or the game wasn't started through Steam, SteamAPI_RestartAppIfNecessary starts the 
            // local Steam client and also launches this game again.
        
            return RESTART_REQUIRED;
        }

        // Initialize SteamAPI, this will also load the in-game steam overlay dll into your process.  That dll is normally
        // injected by steam when it launches games, but by calling this you cause it to always load,
        // even when not launched via steam.
        init_response = SteamAPI_Init();
        if (init_response != SUCCESS) {
            steamworks_cat.error() << "Steam must be running to play this game (SteamAPI_Init() failed)." << std::endl;
        } else {
            // Verify steam is currently running and that a user is currently logged in
            if (!is_steam_running()) {
                init_response = NO_CLIENT;
            } else if (!SteamUser()->BLoggedOn()) {
                init_response = NO_CONNECTION;
            }
        }

        if (init_response == SUCCESS && SteamUserStats() != nullptr) {
          	// Load stats and achievements automatically
		    SteamUserStats()->RequestCurrentStats();  
        }
    }

    if (init_response == SUCCESS) {
        _api_initialized = true;
    }

    return init_response;
}

/**
 * Returns true if the Steam client is currently running
 */
bool SteamworksManager::is_steam_running() {
    return SteamAPI_IsSteamRunning();
}

/**
 * Performs Steamworks callbacks
 */
void SteamworksManager::run_callbacks() {
    SteamAPI_RunCallbacks();
}

/**
 * Runs callbacks and performs repeating tasks relating to the steamworks integration
 */
void SteamworksManager::update() {
    run_callbacks();
}

