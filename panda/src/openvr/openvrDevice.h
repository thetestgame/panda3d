/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrDevice.h
 * @author thetestgame
 * @date 2018-03-11
 */
#ifndef OPENVR_DEVICE_H
#define OPENVR_DEVICE_H

#include "config_openvr.h"
#include "inputDevice.h"
#include "nodepath.h"

#include "openvr.h"

class EXPCL_OPENVR OpenVRDevice : public InputDevice {

PUBLISHED:

    /**
     * Describes what kind of object is being tracked at a given ID
     */
    enum PVRTrackedDeviceClass
    {
        PVR_TrackedDeviceClass_Invalid = 0,				// the ID was not valid.
        PVR_TrackedDeviceClass_HMD = 1,					// Head-Mounted Displays
        PVR_TrackedDeviceClass_Controller = 2,			// Tracked controllers
        PVR_TrackedDeviceClass_GenericTracker = 3,		// Generic trackers, similar to controllers
        PVR_TrackedDeviceClass_TrackingReference = 4,	// Camera and base stations that serve as tracking reference points
        PVR_TrackedDeviceClass_DisplayRedirect = 5,		// Accessories that aren't necessarily tracked themselves, but may redirect video output from other tracked devices
    };

    /**
     * Each entry in this enum represents a property that can be retrieved about a
     * tracked device. Many fields are only valid for one ETrackedDeviceClass.
     */
    enum PVRTrackedDeviceProperty
    {
        PVR_Prop_Invalid								= 0,

        // general properties that apply to all device classes
        PVR_Prop_TrackingSystemName_String				= 1000,
        PVR_Prop_ModelNumber_String						= 1001,
        PVR_Prop_SerialNumber_String					= 1002,
        PVR_Prop_RenderModelName_String					= 1003,
        PVR_Prop_WillDriftInYaw_Bool					= 1004,
        PVR_Prop_ManufacturerName_String				= 1005,
        PVR_Prop_TrackingFirmwareVersion_String			= 1006,
        PVR_Prop_HardwareRevision_String				= 1007,
        PVR_Prop_AllWirelessDongleDescriptions_String	= 1008,
        PVR_Prop_ConnectedWirelessDongle_String			= 1009,
        PVR_Prop_DeviceIsWireless_Bool					= 1010,
        PVR_Prop_DeviceIsCharging_Bool					= 1011,
        PVR_Prop_DeviceBatteryPercentage_Float			= 1012, // 0 is empty, 1 is full
        PVR_Prop_StatusDisplayTransform_Matrix34		= 1013,
        PVR_Prop_Firmware_UpdateAvailable_Bool			= 1014,
        PVR_Prop_Firmware_ManualUpdate_Bool				= 1015,
        PVR_Prop_Firmware_ManualUpdateURL_String		= 1016,
        PVR_Prop_HardwareRevision_Uint64				= 1017,
        PVR_Prop_FirmwareVersion_Uint64					= 1018,
        PVR_Prop_FPGAVersion_Uint64						= 1019,
        PVR_Prop_VRCVersion_Uint64						= 1020,
        PVR_Prop_RadioVersion_Uint64					= 1021,
        PVR_Prop_DongleVersion_Uint64					= 1022,
        PVR_Prop_BlockServerShutdown_Bool				= 1023,
        PVR_Prop_CanUnifyCoordinateSystemWithHmd_Bool	= 1024,
        PVR_Prop_ContainsProximitySensor_Bool			= 1025,
        PVR_Prop_DeviceProvidesBatteryStatus_Bool		= 1026,
        PVR_Prop_DeviceCanPowerOff_Bool					= 1027,
        PVR_Prop_Firmware_ProgrammingTarget_String		= 1028,
        PVR_Prop_DeviceClass_Int32						= 1029,
        PVR_Prop_HasCamera_Bool							= 1030,
        PVR_Prop_DriverVersion_String                   = 1031,
        PVR_Prop_Firmware_ForceUpdateRequired_Bool      = 1032,
        PVR_Prop_ViveSystemButtonFixRequired_Bool		= 1033,
        PVR_Prop_ParentDriver_Uint64					= 1034,
        PVR_Prop_ResourceRoot_String					= 1035,

        // Properties that are unique to TrackedDeviceClass_HMD
        PVR_Prop_ReportsTimeSinceVSync_Bool				= 2000,
        PVR_Prop_SecondsFromVsyncToPhotons_Float		= 2001,
        PVR_Prop_DisplayFrequency_Float					= 2002,
        PVR_Prop_UserIpdMeters_Float					= 2003,
        PVR_Prop_CurrentUniverseId_Uint64				= 2004,
        PVR_Prop_PreviousUniverseId_Uint64				= 2005,
        PVR_Prop_DisplayFirmwareVersion_Uint64			= 2006,
        PVR_Prop_IsOnDesktop_Bool						= 2007,
        PVR_Prop_DisplayMCType_Int32					= 2008,
        PVR_Prop_DisplayMCOffset_Float					= 2009,
        PVR_Prop_DisplayMCScale_Float					= 2010,
        PVR_Prop_EdidVendorID_Int32						= 2011,
        PVR_Prop_DisplayMCImageLeft_String              = 2012,
        PVR_Prop_DisplayMCImageRight_String             = 2013,
        PVR_Prop_DisplayGCBlackClamp_Float				= 2014,
        PVR_Prop_EdidProductID_Int32					= 2015,
        PVR_Prop_CameraToHeadTransform_Matrix34			= 2016,
        PVR_Prop_DisplayGCType_Int32					= 2017,
        PVR_Prop_DisplayGCOffset_Float					= 2018,
        PVR_Prop_DisplayGCScale_Float					= 2019,
        PVR_Prop_DisplayGCPrescale_Float				= 2020,
        PVR_Prop_DisplayGCImage_String					= 2021,
        PVR_Prop_LensCenterLeftU_Float					= 2022,
        PVR_Prop_LensCenterLeftV_Float					= 2023,
        PVR_Prop_LensCenterRightU_Float					= 2024,
        PVR_Prop_LensCenterRightV_Float					= 2025,
        PVR_Prop_UserHeadToEyeDepthMeters_Float			= 2026,
        PVR_Prop_CameraFirmwareVersion_Uint64			= 2027,
        PVR_Prop_CameraFirmwareDescription_String		= 2028,
        PVR_Prop_DisplayFPGAVersion_Uint64				= 2029,
        PVR_Prop_DisplayBootloaderVersion_Uint64		= 2030,
        PVR_Prop_DisplayHardwareVersion_Uint64			= 2031,
        PVR_Prop_AudioFirmwareVersion_Uint64			= 2032,
        PVR_Prop_CameraCompatibilityMode_Int32			= 2033,
        PVR_Prop_ScreenshotHorizontalFieldOfViewDegrees_Float = 2034,
        PVR_Prop_ScreenshotVerticalFieldOfViewDegrees_Float = 2035,
        PVR_Prop_DisplaySuppressed_Bool					= 2036,
        PVR_Prop_DisplayAllowNightMode_Bool				= 2037,
        PVR_Prop_DisplayMCImageWidth_Int32				= 2038,
        PVR_Prop_DisplayMCImageHeight_Int32				= 2039,
        PVR_Prop_DisplayMCImageNumChannels_Int32		= 2040,
        PVR_Prop_DisplayMCImageData_Binary				= 2041,
        PVR_Prop_SecondsFromPhotonsToVblank_Float		= 2042,
        PVR_Prop_DriverDirectModeSendsVsyncEvents_Bool	= 2043,
        PVR_Prop_DisplayDebugMode_Bool					= 2044,
        PVR_Prop_GraphicsAdapterLuid_Uint64				= 2045,
        PVR_Prop_DriverProvidedChaperonePath_String		= 2048,

        // Properties that are unique to TrackedDeviceClass_Controller
        PVR_Prop_AttachedDeviceId_String				= 3000,
        PVR_Prop_SupportedButtons_Uint64				= 3001,
        PVR_Prop_Axis0Type_Int32						= 3002, // Return value is of type EVRControllerAxisType
        PVR_Prop_Axis1Type_Int32						= 3003, // Return value is of type EVRControllerAxisType
        PVR_Prop_Axis2Type_Int32						= 3004, // Return value is of type EVRControllerAxisType
        PVR_Prop_Axis3Type_Int32						= 3005, // Return value is of type EVRControllerAxisType
        PVR_Prop_Axis4Type_Int32						= 3006, // Return value is of type EVRControllerAxisType
        PVR_Prop_ControllerRoleHint_Int32				= 3007, // Return value is of type ETrackedControllerRole

        // Properties that are unique to TrackedDeviceClass_TrackingReference
        PVR_Prop_FieldOfViewLeftDegrees_Float			= 4000,
        PVR_Prop_FieldOfViewRightDegrees_Float			= 4001,
        PVR_Prop_FieldOfViewTopDegrees_Float			= 4002,
        PVR_Prop_FieldOfViewBottomDegrees_Float			= 4003,
        PVR_Prop_TrackingRangeMinimumMeters_Float		= 4004,
        PVR_Prop_TrackingRangeMaximumMeters_Float		= 4005,
        PVR_Prop_ModeLabel_String						= 4006,

        // Properties that are used for user interface like icons names
        PVR_Prop_IconPathName_String						= 5000, // DEPRECATED. Value not referenced. Now expected to be part of icon path properties.
        PVR_Prop_NamedIconPathDeviceOff_String				= 5001, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceSearching_String		= 5002, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceSearchingAlert_String	= 5003, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceReady_String			= 5004, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceReadyAlert_String		= 5005, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceNotReady_String			= 5006, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceStandby_String			= 5007, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
        PVR_Prop_NamedIconPathDeviceAlertLow_String			= 5008, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others

        // Properties that are used by helpers, but are opaque to applications
        PVR_Prop_DisplayHiddenArea_Binary_Start				= 5100,
        PVR_Prop_DisplayHiddenArea_Binary_End				= 5150,

        // Properties that are unique to drivers
        PVR_Prop_UserConfigPath_String					= 6000,
        PVR_Prop_InstallPath_String						= 6001,
        PVR_Prop_HasDisplayComponent_Bool				= 6002,
        PVR_Prop_HasControllerComponent_Bool			= 6003,
        PVR_Prop_HasCameraComponent_Bool				= 6004,
        PVR_Prop_HasDriverDirectModeComponent_Bool		= 6005,
        PVR_Prop_HasVirtualDisplayComponent_Bool		= 6006,

        // Vendors are free to expose private debug data in this reserved region
        PVR_Prop_VendorSpecific_Reserved_Start			= 10000,
        PVR_Prop_VendorSpecific_Reserved_End			= 10999,
    };

    int device_index = -1;
    virtual void do_poll();

    string get_device_property(PVRTrackedDeviceProperty prop);

public:
    OpenVRDevice(const string &name, DeviceClass dev_class, vr::ETrackedDeviceClass openvr_class);
    ~OpenVRDevice();

    string get_device_property(vr::ETrackedDeviceProperty prop);
    INLINE string get_system_name();
    INLINE string get_serial_number();
    INLINE string get_model_name();

    PVRTrackedDeviceClass openvr_device_class;

PUBLISHED:
    MAKE_PROPERTY(system_name, get_system_name);
    MAKE_PROPERTY(serial_number, get_serial_number);
    MAKE_PROPERTY(model_name, get_model_name);

protected:
    void process_tracking();

    friend class OpenVRSystem;
public:
    static TypeHandle get_class_type() {
        return _type_handle;
    }
    static void init_type() {
        InputDevice::init_type();
        register_type(_type_handle, "OpenVRDevice",
                      InputDevice::get_class_type());
    }
    virtual TypeHandle get_type() const {
        return get_class_type();
    }
    virtual TypeHandle force_init_type() {
        init_type();
        return get_class_type();
    }
private:
    static TypeHandle _type_handle;
};

#include "openvrDevice.I"

#endif