/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.cxx
 * @author rdb
 * @date 2016-12-29
 */

#include "trackerEffect.h"
#include "inputDevice.h"
#include "cullTraverserData.h"

TypeHandle TrackerEffect::_type_handle;

/**
 * Constructs a new TrackerEffect object with the indicated properties.
 */
CPT(RenderEffect) TrackerEffect::
make(const InputDevice *tracker, int tracked_axes) {
  return return_new(new TrackerEffect(tracker, tracked_axes));
}

/**
 * Returns true if it is generally safe to transform this particular kind of
 * RenderEffect by calling the xform() method, false otherwise.
 */
bool TrackerEffect::
safe_to_transform() const {
  return false;
}

/**
 *
 */
void TrackerEffect::
output(ostream &out) const {
  out << get_type() << ":" << *_device;
}

/**
 * Should be overridden by derived classes to return true if cull_callback()
 * has been defined.  Otherwise, returns false to indicate cull_callback()
 * does not need to be called for this effect during the cull traversal.
 */
bool TrackerEffect::
has_cull_callback() const {
  return true;
}

/**
 * If has_cull_callback() returns true, this function will be called during
 * the cull traversal to perform any additional operations that should be
 * performed at cull time.  This may include additional manipulation of render
 * state or additional visible/invisible decisions, or any other arbitrary
 * operation.
 *
 * At the time this function is called, the current node's transform and state
 * have not yet been applied to the net_transform and net_state.  This
 * callback may modify the node_transform and node_state to apply an effective
 * change to the render state at this level.
 */
void TrackerEffect::
cull_callback(CullTraverser *trav, CullTraverserData &data,
              CPT(TransformState) &node_transform,
              CPT(RenderState) &) const {
  CPT(TransformState) dummy_transform = TransformState::make_identity();
  adjust_transform(dummy_transform, node_transform, data.node());
}

/**
 * Should be overridden by derived classes to return true if
 * adjust_transform() has been defined, and therefore the RenderEffect has
 * some effect on the node's apparent local and net transforms.
 */
bool TrackerEffect::
has_adjust_transform() const {
  // Don't check _device->is_connected() here, because the value gets cached.
  return true;
}

/**
 * Performs some operation on the node's apparent net and/or local transforms.
 * This will only be called if has_adjust_transform() is redefined to return
 * true.
 *
 * Both parameters are in/out.  The original transforms will be passed in, and
 * they may (or may not) be modified in-place by the RenderEffect.
 */
void TrackerEffect::
adjust_transform(CPT(TransformState) &net_transform,
                 CPT(TransformState) &node_transform,
                 const PandaNode *) const {

  if (!_device->is_connected()) {
    return;
  }

  //TODO: set net transform, based on tracking origin etc.

  TrackerData pose = _device->get_tracker();

  bool has_pos = pose.has_pos() && ((_tracked_axes & TA_pos) != 0);
  bool has_orient = pose.has_orient() && ((_tracked_axes & TA_orient) != 0);

  //cerr << "tracking: " << has_pos << ", " << has_orient << "\n";

  if (has_pos) {
    node_transform = node_transform->set_pos(pose.get_pos());
  }
  if (has_orient) {
    node_transform = node_transform->set_quat(pose.get_orient());
  }
}

/**
 * Intended to be overridden by derived TrackerEffect types to return a
 * unique number indicating whether this TrackerEffect is equivalent to the
 * other one.
 *
 * This should return 0 if the two TrackerEffect objects are equivalent, a
 * number less than zero if this one should be sorted before the other one,
 * and a number greater than zero otherwise.
 *
 * This will only be called with two TrackerEffect objects whose get_type()
 * functions return the same.
 */
int TrackerEffect::
compare_to_impl(const RenderEffect *other) const {
  const TrackerEffect *ta;
  DCAST_INTO_R(ta, other, 0);

  if (_device != ta->_device) {
    return _device < ta->_device ? -1 : 1;
  }

  return _tracked_axes - ta->_tracked_axes;
}
