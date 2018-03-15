/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.I
 * @author rdb
 * @date 2016-12-29
 */

/**
 * Use TrackerEffect::make() to construct a new TrackerEffect object.
 */
INLINE TrackerEffect::
TrackerEffect(const InputDevice *device, int tracked_axes) :
  _device(device), _tracked_axes(tracked_axes) {
  nassertv(device != NULL);
}

/**
 * Returns the tracker device.
 */
INLINE const InputDevice *TrackerEffect::
get_device() const {
  return _device;
}

/**
 * Returns a bitmask of tracked axes.
 */
INLINE int TrackerEffect::
get_tracked_axes() const {
  return _tracked_axes;
}
