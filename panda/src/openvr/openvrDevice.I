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

INLINE string OpenVRDevice::get_system_name() {
    return get_device_property(vr::Prop_TrackingSystemName_String);
}

INLINE string OpenVRDevice::get_serial_number() {
    return get_device_property(vr::Prop_SerialNumber_String);
};

INLINE string OpenVRDevice::get_model_name() {
    return get_device_property(vr::Prop_RenderModelName_String);
}
