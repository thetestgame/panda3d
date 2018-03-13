/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file trackerEffect.h
 * @author thetestgame
 * @date 2018-03-12
 */

#ifndef TRACKER_EFFECT_H
#define TRACKER_EFFECT_H

#include "pandabase.h"
#include "renderEffect.h"
#include "nodePath.h"
#include "inputDevice.h"

/**
 * Indicates that geometry at this node should automatically rotate and position to match
 * the tracker data on the specified InputDevice.
 */
class EXPCL_PANDA_PGRAPH TrackerEffect: public RenderEffect {

  private: 
    TrackerEffect();

  PUBLISHED: 
    static CPT(RenderEffect) make(const InputDevice & device);

    INLINE const InputDevice & get_device() const;

  public: 

    virtual bool safe_to_transform() const;
    virtual void output(ostream & out) const;

    virtual bool has_adjust_transform() const;
    virtual void adjust_transform(CPT(TransformState) & net_transform,
                CPT(TransformState) & node_transform,
                const PandaNode * node) const;

  private: 
    InputDevice _device;

  public: 
    static TypeHandle get_class_type() {
        return _type_handle;
    }
    
    static void init_type() {
        RenderEffect::init_type();
        register_type(_type_handle, "TrackerEffect",
            RenderEffect::get_class_type());
    }

    virtual TypeHandle get_type() const {
        return get_class_type();
    }

    virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }

  private: 
    static TypeHandle _type_handle;
};

#include "trackerEffect.I"

#endif