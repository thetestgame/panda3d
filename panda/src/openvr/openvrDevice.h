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

  int device_index = -1;
  virtual void do_poll();

public:
  OpenVRDevice(const string &name, DeviceClass dev_class, vr::ETrackedDeviceClass openvr_class);
  ~OpenVRDevice();

  vr::ETrackedDeviceClass ovr_device_class;

  string get_device_property(vr::ETrackedDeviceProperty prop);
  INLINE string get_system_name();
  INLINE string get_serial_number();
  INLINE string get_model_name();

PUBLISHED:
  MAKE_PROPERTY(system_name, get_system_name);
  MAKE_PROPERTY(serial_number, get_serial_number);
  MAKE_PROPERTY(model_name, get_model_name);

protected:

  void update_properties();
  void process_tracking();

  friend class OpenVRSystem;
public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    TypedReferenceCount::init_type();
    register_type(_type_handle, "OpenVRSystem",
        TypedReferenceCount::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
   static TypeHandle _type_handle;
};

#include "openvrDevice.I"

#endif