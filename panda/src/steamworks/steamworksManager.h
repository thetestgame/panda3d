/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file steamworksManager.h
 * @author thetestgame
 * @date 2018-3-1
 */

#ifndef STEAMWORKS_MANAGER_H
#define STEAMWORKS_MANAGER_H

#include "config_steamworks.h"
#include "typedReferenceCount.h"
#include "steam_api.h"

class EXPCL_STEAMWORKS SteamworksManager : public TypedReferenceCount {

PUBLISHED:

    enum InitResponse {
        SUCCESS = 1,
        NO_CLIENT = 2,
        NO_CONNECTION = 3,
        RESTART_REQUIRED = 4,
    };

    ~SteamworksManager();

    // Pointer Managment
    static SteamworksManager* get_global_ptr();

    // Initializes the SteamAPI. 
    int steam_init();
    // Returns true if the Steam client is currently running
    bool is_steam_running();

    // Returns the current api initialize state.
    bool steam_initialized() const {
        return _api_initialized;
    }
    MAKE_PROPERTY(initialized, steam_initialized);

    // Processes Steamworks Callbacks
    void run_callbacks();  

    // Overlay Notification management
    enum SteamNotificationPosition {
        NOTIFICATION_TopLeft = 0,
        NOTIFICATION_TopRight = 1,
        NOTIFICATION_BottomLeft = 2,
        NOTIFICATION_BottomRight = 3
    };
    void set_overlay_notification_position(SteamNotificationPosition position);
    void set_overlay_notification_inset(int horizontalInset, verticalInset);


    //Steam Apps
    /*
    int app_subscribed(int appId);
    int get_dlc_count();
    bool dlc_installed(int dlcId);
    void request_app_proof_of_pruchase_key(int appId);
    bool app_installed(int appId);
    */
    //const char* get_current_game_language();

    // Performs repeating tasks relating to Steamworks
    void update();

public:
    // Pointer Managment
    static void shutdown();

private:
    static SteamworksManager* _global_ptr;
    SteamworksManager();

    bool _api_initialized;

public:
    static TypeHandle get_class_type() {
        return _type_handle;
    }
    static void init_type() {
        TypedReferenceCount::init_type();
        register_type(_type_handle, "SteamworksManager",
                    TypedReferenceCount::get_class_type());
    }
    virtual TypeHandle get_type() const {
        return get_class_type();
    }
    virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
    static TypeHandle _type_handle;
};
#endif