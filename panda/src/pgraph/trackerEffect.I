/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.I
 * @author thetestgame
 * @date 2018-03-12
 */

/**
 * Returns the InputDevice linked to this TrackerEffect.
 */
INLINE const InputDevice & TrackerEffect::
get_device() const {
  return _device;
}
