/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.cxx
 * @author thetestgame
 * @date 2018-03-12
 */

#include "trackerEffect.h"
#include "config_pgraph.h"

TypeHandle TrackerEffect::_type_handle;

/**
 *
 */
TrackerEffect::TrackerEffect() {}

/**
 *
 */
CPT(RenderEffect) TrackerEffect::
make(const InputDevice &device) {
    TrackerEffect *effect = new TrackerEffect;
    effect->_device = device;
    return return_new(effect);
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
    out << get_type() << ":";
    out << " device " << _device.get_name();
}

/**
 * Should be overridden by derived classes to return true if
 * adjust_transform() has been defined, and therefore the RenderEffect has
 * some effect on the node's apparent local and net transforms.
 */
bool TrackerEffect::
has_adjust_transform() const {
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

    TrackerData tracker_data = _device.get_tracker();
    if (!tracker_data.has_pos() && !tracker_data.has_orient()) {
        // No positional data found
        return;
    }

    //LVecBase3 desired_pos = tracker_data.get_pos();
    //LQuaternion desired_quat = tracker_data.get_orient()
}