/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrController.h
 * @author thetestgame
 * @date 2018-03-11
 */

#ifndef OPENVR_CONTROLLER_H
#define OPENVR_CONTROLLER_H

#include "openvrDevice.h"

class EXPCL_OPENVR OpenVRController : public OpenVRDevice {

PUBLISHED:
  virtual void do_poll();

  bool is_left_hand();
  bool is_right_hand();

public:
  OpenVRController(const string &name, DeviceClass dev_class);

private:
  uint32_t _last_input_packet_number = 0;

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

#endif