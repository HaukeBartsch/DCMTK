/*
 *
 *  Copyright (C) 2012, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  ofstd
 *
 *  Author:  Uli Schlachter
 *
 *  Purpose: common defines for import and exporting symbols
 *
 */

#ifndef OFEXPORT_H
#define OFEXPORT_H

#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */


#ifdef DCMTK_SHARED
#ifdef _WIN32
/* Defines needed for building DLLs on windows */
#define DCMTK_DECL_EXPORT __declspec(dllexport)
/* Only use dllimport when DCMTK gets linked into multiple shared libraries. */
#ifndef DCMTK_STATIC_FOR_SHARED
#define DCMTK_DECL_IMPORT __declspec(dllimport)
#endif
#elif defined(HAVE_HIDDEN_VISIBILITY)
/* GCC hides everything when given -fvisibility=hidden. The symbols which
 * should be visible have to get a default visibility again.
 */
#define DCMTK_DECL_EXPORT __attribute__ ((visibility("default")))
#endif
#endif

#ifndef DCMTK_DECL_EXPORT
#define DCMTK_DECL_EXPORT
#endif

#ifndef DCMTK_DECL_IMPORT
#define DCMTK_DECL_IMPORT
#endif


#endif