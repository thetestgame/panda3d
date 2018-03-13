/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file openvrHmd.h
 * @author thetestgame
 * @date 2018-03-11
 */
#ifndef OPENVR_HMD_H
#define OPENVR_HMD_H

#include "openvrDevice.h"
#include "graphicsEngine.h"
#include "graphicsPipe.h"
#include "graphicsWindow.h"
#include "windowProperties.h"

class EXPCL_OPENVR OpenVRHmd : public OpenVRDevice {

PUBLISHED:

    ~OpenVRHmd();

public:
    OpenVRHmd();
public:
    static TypeHandle get_class_type() {
        return _type_handle;
    }
    static void init_type() {
        OpenVRDevice::init_type();
        register_type(_type_handle, "OpenVRHmd",
                    OpenVRDevice::get_class_type());
    }
    virtual TypeHandle get_type() const {
        return get_class_type();
    }
    virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
private:
    static TypeHandle _type_handle;
};

#endif