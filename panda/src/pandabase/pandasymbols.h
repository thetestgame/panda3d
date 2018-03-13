/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file pandasymbols.h
 * @author drose
 * @date 2000-02-18
 */

#ifndef PANDASYMBOLS_H
#define PANDASYMBOLS_H

/* See dtoolsymbols.h for a rant on the purpose of this file.  */

/* Note that the symbols declared in this file appear in alphabetical
   order.  Also note that we must use C-style comments only here, not
   C++-style comments, since this file is occasionally included by a C
   file. */

#ifdef BUILDING_CFTALK
  #define EXPCL_CFTALK EXPORT_CLASS
  #define EXPTP_CFTALK EXPORT_TEMPL
#else
  #define EXPCL_CFTALK IMPORT_CLASS
  #define EXPTP_CFTALK IMPORT_TEMPL
#endif

#ifdef BUILDING_COLLADA
  #define EXPCL_COLLADA EXPORT_CLASS
  #define EXPTP_COLLADA EXPORT_TEMPL
#else
  #define EXPCL_COLLADA IMPORT_CLASS
  #define EXPTP_COLLADA IMPORT_TEMPL
#endif

#ifdef BUILDING_FFMPEG
  #define EXPCL_FFMPEG EXPORT_CLASS
  #define EXPTP_FFMPEG EXPORT_TEMPL
#else
  #define EXPCL_FFMPEG IMPORT_CLASS
  #define EXPTP_FFMPEG IMPORT_TEMPL
#endif

#ifdef BUILDING_FRAMEWORK
  #define EXPCL_FRAMEWORK EXPORT_CLASS
  #define EXPTP_FRAMEWORK EXPORT_TEMPL
#else
  #define EXPCL_FRAMEWORK IMPORT_CLASS
  #define EXPTP_FRAMEWORK IMPORT_TEMPL
#endif

#ifdef BUILDING_LINUX_AUDIO
  #define EXPCL_LINUX_AUDIO EXPORT_CLASS
  #define EXPTP_LINUX_AUDIO EXPORT_TEMPL
#else
  #define EXPCL_LINUX_AUDIO IMPORT_CLASS
  #define EXPTP_LINUX_AUDIO IMPORT_TEMPL
#endif

#ifdef BUILDING_MILES_AUDIO
  #define EXPCL_MILES_AUDIO EXPORT_CLASS
  #define EXPTP_MILES_AUDIO EXPORT_TEMPL
#else
  #define EXPCL_MILES_AUDIO IMPORT_CLASS
  #define EXPTP_MILES_AUDIO IMPORT_TEMPL
#endif

#ifdef BUILDING_FMOD_AUDIO
  #define EXPCL_FMOD_AUDIO EXPORT_CLASS
  #define EXPTP_FMOD_AUDIO EXPORT_TEMPL
#else
  #define EXPCL_FMOD_AUDIO IMPORT_CLASS
  #define EXPTP_FMOD_AUDIO IMPORT_TEMPL
#endif

#ifdef BUILDING_OCULUSVR
  #define EXPCL_OCULUSVR EXPORT_CLASS
  #define EXPTP_OCULUSVR EXPORT_TEMPL
#else
  #define EXPCL_OCULUSVR IMPORT_CLASS
  #define EXPTP_OCULUSVR IMPORT_TEMPL
#endif

#ifdef BUILDING_OPENAL_AUDIO
  #define EXPCL_OPENAL_AUDIO EXPORT_CLASS
  #define EXPTP_OPENAL_AUDIO EXPORT_TEMPL
#else
  #define EXPCL_OPENAL_AUDIO IMPORT_CLASS
  #define EXPTP_OPENAL_AUDIO IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDA
  #define EXPCL_PANDA EXPORT_CLASS
  #define EXPTP_PANDA EXPORT_TEMPL
#else
  #define EXPCL_PANDA IMPORT_CLASS
  #define EXPTP_PANDA IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAAWESOMIUM
  #define EXPCL_PANDAAWESOMIUM EXPORT_CLASS
  #define EXPTP_PANDAAWESOMIUM EXPORT_TEMPL
#else
  #define EXPCL_PANDAAWESOMIUM IMPORT_CLASS
  #define EXPTP_PANDAAWESOMIUM IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDABULLET
  #define EXPCL_PANDABULLET EXPORT_CLASS
  #define EXPTP_PANDABULLET EXPORT_TEMPL
#else
  #define EXPCL_PANDABULLET IMPORT_CLASS
  #define EXPTP_PANDABULLET IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDACR
  #define EXPCL_PANDACR EXPORT_CLASS
  #define EXPTP_PANDACR EXPORT_TEMPL
#else
  #define EXPCL_PANDACR IMPORT_CLASS
  #define EXPTP_PANDACR IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDADX
  #define EXPCL_PANDADX EXPORT_CLASS
  #define EXPTP_PANDADX EXPORT_TEMPL
#else
  #define EXPCL_PANDADX IMPORT_CLASS
  #define EXPTP_PANDADX IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAEGG
  #define EXPCL_PANDAEGG EXPORT_CLASS
  #define EXPTP_PANDAEGG EXPORT_TEMPL
#else
  #define EXPCL_PANDAEGG IMPORT_CLASS
  #define EXPTP_PANDAEGG IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAEXPRESS
  #define EXPCL_PANDAEXPRESS EXPORT_CLASS
  #define EXPTP_PANDAEXPRESS EXPORT_TEMPL
#else
  #define EXPCL_PANDAEXPRESS IMPORT_CLASS
  #define EXPTP_PANDAEXPRESS IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAFX
  #define EXPCL_PANDAFX EXPORT_CLASS
  #define EXPTP_PANDAFX EXPORT_TEMPL
#else
  #define EXPCL_PANDAFX IMPORT_CLASS
  #define EXPTP_PANDAFX IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAGL
  #define EXPCL_PANDAGL EXPORT_CLASS
  #define EXPTP_PANDAGL EXPORT_TEMPL
#else
  #define EXPCL_PANDAGL IMPORT_CLASS
  #define EXPTP_PANDAGL IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAGLES
  #define EXPCL_PANDAGLES EXPORT_CLASS
  #define EXPTP_PANDAGLES EXPORT_TEMPL
#else
  #define EXPCL_PANDAGLES IMPORT_CLASS
  #define EXPTP_PANDAGLES IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAGLES2
  #define EXPCL_PANDAGLES2 EXPORT_CLASS
  #define EXPTP_PANDAGLES2 EXPORT_TEMPL
#else
  #define EXPCL_PANDAGLES2 IMPORT_CLASS
  #define EXPTP_PANDAGLES2 IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAODE
  #define EXPCL_PANDAODE EXPORT_CLASS
  #define EXPTP_PANDAODE EXPORT_TEMPL
#else
  #define EXPCL_PANDAODE IMPORT_CLASS
  #define EXPTP_PANDAODE IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAPHYSICS
  #define EXPCL_PANDAPHYSICS EXPORT_CLASS
  #define EXPTP_PANDAPHYSICS EXPORT_TEMPL
#else
  #define EXPCL_PANDAPHYSICS IMPORT_CLASS
  #define EXPTP_PANDAPHYSICS IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAPHYSX
  #define EXPCL_PANDAPHYSX EXPORT_CLASS
  #define EXPTP_PANDAPHYSX EXPORT_TEMPL
#else
  #define EXPCL_PANDAPHYSX IMPORT_CLASS
  #define EXPTP_PANDAPHYSX IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDASPEEDTREE
  #define EXPCL_PANDASPEEDTREE EXPORT_CLASS
  #define EXPTP_PANDASPEEDTREE EXPORT_TEMPL
#else
  #define EXPCL_PANDASPEEDTREE IMPORT_CLASS
  #define EXPTP_PANDASPEEDTREE IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDASKEL
  #define EXPCL_PANDASKEL EXPORT_CLASS
  #define EXPTP_PANDASKEL EXPORT_TEMPL
#else
  #define EXPCL_PANDASKEL IMPORT_CLASS
  #define EXPTP_PANDASKEL IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAWIN
  #define EXPCL_PANDAWIN EXPORT_CLASS
  #define EXPTP_PANDAWIN EXPORT_TEMPL
#else
  #define EXPCL_PANDAWIN IMPORT_CLASS
  #define EXPTP_PANDAWIN IMPORT_TEMPL
#endif

#ifdef BUILDING_PANDAX11
  #define EXPCL_PANDAX11 EXPORT_CLASS
  #define EXPTP_PANDAX11 EXPORT_TEMPL
#else
  #define EXPCL_PANDAX11 IMPORT_CLASS
  #define EXPTP_PANDAX11 IMPORT_TEMPL
#endif

#ifdef BUILDING_ROCKET
  #define EXPCL_ROCKET EXPORT_CLASS
  #define EXPTP_ROCKET EXPORT_TEMPL
#else
  #define EXPCL_ROCKET IMPORT_CLASS
  #define EXPTP_ROCKET IMPORT_TEMPL
#endif

#ifdef BUILDING_SHADER
  #define EXPCL_SHADER EXPORT_CLASS
  #define EXPTP_SHADER EXPORT_TEMPL
#else
  #define EXPCL_SHADER IMPORT_CLASS
  #define EXPTP_SHADER IMPORT_TEMPL
#endif

#ifdef BUILDING_TINYDISPLAY
  #define EXPCL_TINYDISPLAY EXPORT_CLASS
  #define EXPTP_TINYDISPLAY EXPORT_TEMPL
#else
  #define EXPCL_TINYDISPLAY IMPORT_CLASS
  #define EXPTP_TINYDISPLAY IMPORT_TEMPL
#endif

#ifdef BUILDING_VISION
  #define EXPCL_VISION EXPORT_CLASS
  #define EXPTP_VISION EXPORT_TEMPL
#else
  #define EXPCL_VISION IMPORT_CLASS
  #define EXPTP_VISION IMPORT_TEMPL
#endif

#ifdef BUILDING_VRPN
  #define EXPCL_VRPN EXPORT_CLASS
  #define EXPTP_VRPN EXPORT_TEMPL
#else
  #define EXPCL_VRPN IMPORT_CLASS
  #define EXPTP_VRPN IMPORT_TEMPL
#endif

#ifdef BUILDING_OPENVR
  #define EXPCL_OPENVR EXPORT_CLASS
  #define EXPTP_OPENVR EXPORT_TEMPL
#else
  #define EXPCL_OPENVR IMPORT_CLASS
  #define EXPTP_OPENVR IMPORT_TEMPL
#endif

#if (defined(WIN32_VC) || defined(WIN64_VC)) && !defined(CPPPARSER)
#define INLINE_LINMATH __forceinline
#define INLINE_MATHUTIL __forceinline

#ifdef BUILDING_PANDA
#define INLINE_GRAPH __forceinline
#define INLINE_DISPLAY __forceinline
#else
#define INLINE_GRAPH
#define DONT_INLINE_GRAPH
#define INLINE_DISPLAY
#define DONT_INLINE_DISPLAY
#endif

#else
#define INLINE_LINMATH INLINE
#define INLINE_MATHUTIL INLINE
#define INLINE_GRAPH INLINE
#define INLINE_DISPLAY INLINE
#endif

#define INLINE_CHAR INLINE
#define INLINE_CHAT INLINE
#define INLINE_CHAN INLINE
#define INLINE_CHANCFG INLINE
#define INLINE_COLLIDE INLINE
#define INLINE_CULL INLINE
#define INLINE_DEVICE INLINE
#define INLINE_DGRAPH INLINE
#define INLINE_GOBJ INLINE
#define INLINE_GRUTIL INLINE
#define INLINE_GSGBASE INLINE
#define INLINE_GSGMISC INLINE
#define INLINE_LIGHT INLINE
#define INLINE_PARAMETRICS INLINE
#define INLINE_SGRATTRIB INLINE
#define INLINE_SGMANIP INLINE
#define INLINE_SGRAPH INLINE
#define INLINE_SGRAPHUTIL INLINE
#define INLINE_SWITCHNODE INLINE
#define INLINE_TEXT INLINE
#define INLINE_TFORM INLINE
#define INLINE_LERP INLINE
#define INLINE_LOADER INLINE
#define INLINE_PUTIL INLINE
#define INLINE_EFFECTS INLINE
#define INLINE_GUI INLINE
#define INLINE_AUDIO INLINE


#define EXPCL_PANDA_PGRAPH EXPCL_PANDA
#define EXPTP_PANDA_PGRAPH EXPTP_PANDA

#define EXPCL_PANDA_PGRAPHNODES EXPCL_PANDA
#define EXPTP_PANDA_PGRAPHNODES EXPTP_PANDA

#define EXPCL_PANDA_RECORDER EXPCL_PANDA
#define EXPTP_PANDA_RECORDER EXPTP_PANDA

#define EXPCL_PANDA_PIPELINE EXPCL_PANDA
#define EXPTP_PANDA_PIPELINE EXPTP_PANDA

#define EXPCL_PANDA_GRUTIL EXPCL_PANDA
#define EXPTP_PANDA_GRUTIL EXPTP_PANDA

#define EXPCL_PANDA_CHAN EXPCL_PANDA
#define EXPTP_PANDA_CHAN EXPTP_PANDA

#define EXPCL_PANDA_CHAR EXPCL_PANDA
#define EXPTP_PANDA_CHAR EXPTP_PANDA

#define EXPCL_PANDA_PSTATCLIENT EXPCL_PANDA
#define EXPTP_PANDA_PSTATCLIENT EXPTP_PANDA

#define EXPCL_PANDA_COLLIDE EXPCL_PANDA
#define EXPTP_PANDA_COLLIDE EXPTP_PANDA

#define EXPCL_PANDA_CULL EXPCL_PANDA
#define EXPTP_PANDA_CULL EXPTP_PANDA

#define EXPCL_PANDA_DEVICE EXPCL_PANDA
#define EXPTP_PANDA_DEVICE EXPTP_PANDA

#define EXPCL_PANDA_DGRAPH EXPCL_PANDA
#define EXPTP_PANDA_DGRAPH EXPTP_PANDA

#define EXPCL_PANDA_DISPLAY EXPCL_PANDA
#define EXPTP_PANDA_DISPLAY EXPTP_PANDA

#define EXPCL_PANDA_EVENT EXPCL_PANDA
#define EXPTP_PANDA_EVENT EXPTP_PANDA

#define EXPCL_PANDA_GOBJ EXPCL_PANDA
#define EXPTP_PANDA_GOBJ EXPTP_PANDA

#define EXPCL_PANDA_GSGBASE EXPCL_PANDA
#define EXPTP_PANDA_GSGBASE EXPTP_PANDA

#define EXPCL_PANDA_LINMATH EXPCL_PANDA
#define EXPTP_PANDA_LINMATH EXPTP_PANDA

#define EXPCL_PANDA_MATHUTIL EXPCL_PANDA
#define EXPTP_PANDA_MATHUTIL EXPTP_PANDA

#define EXPCL_PANDA_MOVIES EXPCL_PANDA
#define EXPTP_PANDA_MOVIES EXPTP_PANDA

#define EXPCL_PANDA_NET EXPCL_PANDA
#define EXPTP_PANDA_NET EXPTP_PANDA

#define EXPCL_PANDA_NATIVENET EXPCL_PANDA
#define EXPTP_PANDA_NATIVENET EXPTP_PANDA

#define EXPCL_PANDA_PARAMETRICS EXPCL_PANDA
#define EXPTP_PANDA_PARAMETRICS EXPTP_PANDA

#define EXPCL_PANDA_PNMIMAGETYPES EXPCL_PANDA
#define EXPTP_PANDA_PNMIMAGETYPES EXPTP_PANDA

#define EXPCL_PANDA_PNMIMAGE EXPCL_PANDA
#define EXPTP_PANDA_PNMIMAGE EXPTP_PANDA

#define EXPCL_PANDA_PNMTEXT EXPCL_PANDA
#define EXPTP_PANDA_PNMTEXT EXPTP_PANDA

#define EXPCL_PANDA_TEXT EXPCL_PANDA
#define EXPTP_PANDA_TEXT EXPTP_PANDA

#define EXPCL_PANDA_TFORM EXPCL_PANDA
#define EXPTP_PANDA_TFORM EXPTP_PANDA

#define EXPCL_PANDA_LERP EXPCL_PANDA
#define EXPTP_PANDA_LERP EXPTP_PANDA

#define EXPCL_PANDA_PUTIL EXPCL_PANDA
#define EXPTP_PANDA_PUTIL EXPTP_PANDA

#define EXPCL_PANDA_AUDIO EXPCL_PANDA
#define EXPTP_PANDA_AUDIO EXPTP_PANDA

#define EXPCL_PANDA_PGUI EXPCL_PANDA
#define EXPTP_PANDA_PGUI EXPTP_PANDA

#define EXPCL_PANDA_PANDABASE EXPCL_PANDA
#define EXPTP_PANDA_PANDABASE EXPTP_PANDA

#endif
