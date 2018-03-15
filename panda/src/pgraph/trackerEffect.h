/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.h
 * @author rdb
 * @date 2016-12-29
 */

#ifndef TRACKEREFFECT_H
#define TRACKEREFFECT_H

#include "pandabase.h"
#include "inputDevice.h"
#include "renderEffect.h"
#include "luse.h"
#include "nodePath.h"

/**
 * This binds the rotation and orientation of a particular node to the tracked
 * position of the indicated input device.
 *
 * This is generally a better idea than doing the same via a TrackerNode and
 * Transform2SG in the data graph, since this method relies on doing it in the
 * cull phase, which could result in a lower motion-to-photon latency.
 *
 * To further reduce motion-to-photon latency, it is recommended that objects
 * with this effect are rendered as late as possible into the cull process.
 * This can be achieved with set_bin().
 */
class EXPCL_PANDA_DEVICE TrackerEffect FINAL : public RenderEffect {
private:
  INLINE TrackerEffect(const InputDevice *tracker, int tracked_axes = TA_all);

PUBLISHED:
  enum TrackedAxis {
    TA_x     = 0x001,
    TA_y     = 0x002,
    TA_z     = 0x004,
    TA_pos   = 0x007,
    TA_orient= 0x008,
    TA_all   = 0x00f,
  };

  static CPT(RenderEffect) make(const InputDevice *tracker, int tracked_axes = TA_all);

public:
  INLINE const InputDevice *get_device() const;
  INLINE int get_tracked_axes() const;

  virtual bool safe_to_transform() const override;
  virtual void output(ostream &out) const override;

  virtual bool has_cull_callback() const override;
  virtual void cull_callback(CullTraverser *trav, CullTraverserData &data,
                             CPT(TransformState) &node_transform,
                             CPT(RenderState) &node_state) const;

  virtual bool has_adjust_transform() const override;
  virtual void adjust_transform(CPT(TransformState) &net_transform,
                                CPT(TransformState) &node_transform,
                                const PandaNode *node) const override;

PUBLISHED:
  MAKE_PROPERTY(device, get_device);
  MAKE_PROPERTY(tracked_axes, get_tracked_axes);

protected:
  virtual int compare_to_impl(const RenderEffect *other) const override;

private:
  CPT(InputDevice) const _device;
  int const _tracked_axes;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    RenderEffect::init_type();
    register_type(_type_handle, "TrackerEffect",
                  RenderEffect::get_class_type());
  }
  virtual TypeHandle get_type() const override {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() override {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "trackerEffect.I"

#endif
