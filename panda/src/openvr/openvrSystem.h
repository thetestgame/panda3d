/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file OpenVRSystem.h
 * @author thetestgame
 * @date 2018-03-09
 */

#ifndef OPENVR_MANAGER_H
#define OPENVR_MANAGER_H

#include "config_openvr.h"
#include "typedReferenceCount.h"
#include "genericAsyncTask.h"
#include "openvrHmd.h"

class EXPCL_OPENVR OpenVRSystem : public TypedReferenceCount {

PUBLISHED:

  ~OpenVRSystem();

  // Pointer Managment
  static OpenVRSystem* get_global_ptr();

  vr::EVRInitError init();
  void update();
  void shutdown();

  void reset_seated_zone_pose();

public:

  INLINE bool get_vr_initialized() const;

  vr::IVRSystem* vr_system;
  OpenVRDevice *openvr_devices[vr::k_unMaxTrackedDeviceCount] = {nullptr};
  vr::TrackedDevicePose_t tracked_device_positions[vr::k_unMaxTrackedDeviceCount];

PUBLISHED:

  MAKE_PROPERTY(initialized, get_vr_initialized);

private:
  static OpenVRSystem* _global_ptr;
  OpenVRSystem();

  bool _vr_initialized;

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

#include "openvrSystem.I"
#endif