/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrBaseStation.h
 * @author thetestgame
 * @date 2018-03-12
 */
#ifndef OPENVR_BASE_STATION_H
#define OPENVR_BASE_STATION_H

#include "openvrDevice.h"

class EXPCL_OPENVR OpenVRBaseStation : public OpenVRDevice {

PUBLISHED:
  ~OpenVRBaseStation();

public:
  OpenVRBaseStation(const string &name);

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