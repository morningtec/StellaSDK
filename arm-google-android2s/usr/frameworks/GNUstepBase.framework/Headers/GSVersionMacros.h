/* GSVersionMacros.h - macros for managing API versioning and visibility
   Copyright (C) 2006 Free Software Foundation, Inc.

   Written by: Richard Frith-Macdonald <rfm@gnu.org>
   Date: Oct, October 2006

   This file is part of GNUstep.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef __GNUSTEP_GSVERSIONMACROS_H_INCLUDED_
#define __GNUSTEP_GSVERSIONMACROS_H_INCLUDED_

/* By default we defined NO_GNUSTEP to 0 so that we will include extensions.
 */
#if	!defined(NO_GNUSTEP)
#  define	NO_GNUSTEP	0
#endif

/* Check consistency of definitions for system compatibility.
 */
#if	defined(STRICT_OPENSTEP)
#  define	GS_OPENSTEP_V	 10000
#  undef	NO_GNUSTEP
#  define	NO_GNUSTEP	1
#elif	defined(STRICT_MACOS_X)
#  define	GS_OPENSTEP_V	100600
#  undef	NO_GNUSTEP
#  define	NO_GNUSTEP	1
#endif

/*
 * For MacOS-X compatibility, we define the MacOS-X version constants and
 * we allow MAC_OS_X_VERSION_MIN_ALLOWED or MAC_OS_X_VERSION_MAX_ALLOWED
 * instead of GS_OPENSTEP_V
 */

#ifndef	MAC_OS_X_VERSION_10_0
#define	MAC_OS_X_VERSION_10_0	100000
#define	MAC_OS_X_VERSION_10_1	100100
#define	MAC_OS_X_VERSION_10_2	100200
#define	MAC_OS_X_VERSION_10_3	100300
#define	MAC_OS_X_VERSION_10_4	100400
#define	MAC_OS_X_VERSION_10_5	100500
#define	MAC_OS_X_VERSION_10_6	100600
#endif	/* MAC_OS_X_VERSION_10_0 */

#ifndef	GS_OPENSTEP_V
#ifdef	MAC_OS_X_VERSION_MIN_ALLOWED
#define	GS_OPENSTEP_V	MAC_OS_X_VERSION_MIN_ALLOWED
#else
#ifdef	MAC_OS_X_VERSION_MAX_ALLOWED
#define	GS_OPENSTEP_V	MAC_OS_X_VERSION_MAX_ALLOWED
#endif	/* MAC_OS_X_VERSION_MAX_ALLOWED */
#endif	/* MAC_OS_X_VERSION_MIN_ALLOWED */
#endif	/* GS_OPENSTEP_V */

/*
 * NB. The version values below must be integers ... by convention these are
 * made up of two digits each for major, minor and subminor version numbers
 * (ie each is in the range 00 to 99 though a leading zero in the major
 * number is not permitted).
 * So for a MacOS-X 10.3.9 release the version number would be 100309
 *
 * You may define GS_GNUSTEP_V or GS_OPENSTEP_V to ensure that your
 * program only 'sees' the specified varsion of the API.
 */

/**
 * <p>Macro to check a defined GNUstep version number (GS_GNUSTEP_V) against
 * the supplied arguments.  Returns true if no GNUstep version is specified,
 * or if ADD &lt;= version &lt; REM, where ADD is the version
 * number at which a feature guarded by the macro was introduced and
 * REM is the version number at which it was removed.
 * </p>
 * <p>The version number arguments are six digit integers where the first
 * two digits are the major version number, the second two are the minor
 * version number and the last two are the subminor number (all left padded
 * with a zero where necessary).  However, for convenience you can also
 * use any of several predefined constants ...
 * <ref type="macro" id="GS_API_NONE">GS_API_NONE</ref>,
 * <ref type="macro" id="GS_API_LATEST">GS_API_LATEST</ref>,
 * <ref type="macro" id="GS_API_OSSPEC">GS_API_OSSPEC</ref>,
 * <ref type="macro" id="GS_API_OPENSTEP">GS_API_OPENSTEP</ref>,
 * <ref type="macro" id="GS_API_MACOSX">GS_API_MACOSX</ref>
 * </p>
 * <p>Also see <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * </p>
 * <p>NB. If you are changing the API (eg adding a new feature) you need
 * to control the visibility io the new header file code using<br />
 * <code>#if GS_API_VERSION(ADD,GS_API_LATEST)</code><br />
 * where <code>ADD</code> is the version number of the next minor
 * release after the most recent one.<br />
 * As a general principle you should <em>not</em> change the API with
 * changing subminor version numbers ... as that tends to confuse
 * people (though Apple has sometimes done it).
 * </p>
 */
#define	GS_API_VERSION(ADD,REM) \
  (!defined(GS_GNUSTEP_V) || (GS_GNUSTEP_V >= ADD && GS_GNUSTEP_V < REM))

/**
 * <p>Macro to check a defined OpenStep/OPENSTEP/MacOS-X version against the
 * supplied arguments.  Returns true if no version is specified, or if
 * ADD &lt;= version &lt; REM, where ADD is the version
 * number at which a feature guarded by the macro was introduced and
 * REM is the version number at which it was removed.
 * </p>
 * <p>The version number arguments are six digit integers where the first
 * two digits are the major version number, the second two are the minor
 * version number and the last two are the subminor number (all left padded
 * with a zero where necessary).  However, for convenience you can also
 * use any of several predefined constants ...
 * <ref type="macro" id="GS_API_NONE">GS_API_NONE</ref>,
 * <ref type="macro" id="GS_API_LATEST">GS_API_LATEST</ref>,
 * <ref type="macro" id="GS_API_OSSPEC">GS_API_OSSPEC</ref>,
 * <ref type="macro" id="GS_API_OPENSTEP">GS_API_OPENSTEP</ref>,
 * <ref type="macro" id="GS_API_MACOSX">GS_API_MACOSX</ref>
 * </p>
 * <p>Also see <ref type="macro" id="GS_API_VERSION">GS_API_VERSION</ref>
 * </p>
 */
#define	OS_API_VERSION(ADD,REM) \
  (!defined(GS_OPENSTEP_V) || (GS_OPENSTEP_V >= ADD && GS_OPENSTEP_V < REM))

/**
 * A constant which is the lowest possible version number (0) so that
 * when used as the removal version (second argument of the GS_API_VERSION
 * or OS_API_VERSION macro) represents a feature which is not present in
 * any version.<br />
 * eg.<br />
 * #if <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * (GS_API_NONE, GS_API_NONE)<br />
 * denotes  code not present in OpenStep/OPENSTEP/MacOS-X
 */
#define	GS_API_NONE	     0

/**
 * A constant to represent a feature which is still present in the latest
 * version.  This is the highest possible version number.<br />
 * eg.<br />
 * #if <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * (GS_API_MACOSX, GS_API_LATEST)<br />
 * denotes code present from the initial MacOS-X version onwards.
 */
#define	GS_API_LATEST	999999

/**
 * The version number of the initial OpenStep specification.<br />
 * eg.<br />
 * #if <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * (GS_API_OSSPEC, GS_API_LATEST)<br />
 * denotes code present from the OpenStep specification onwards.
 */
#define	GS_API_OSSPEC	 10000

/**
 * The version number of the first OPENSTEP implementation.<br />
 * eg.<br />
 * #if <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * (GS_API_OPENSTEP, GS_API_LATEST)<br />
 * denotes code present from the initial OPENSTEP version onwards.
 */
#define	GS_API_OPENSTEP	 40000

/**
 * The version number of the first MacOS-X implementation.<br />
 * eg.<br />
 * #if <ref type="macro" id="OS_API_VERSION">OS_API_VERSION</ref>
 * (GS_API_MACOSX, GS_API_LATEST)<br />
 * denotes code present from the initial MacOS-X version onwards.
 */
#define	GS_API_MACOSX	100000


#if	defined(GNUSTEP_BASE_INTERNAL)
#import "GNUstepBase/GSConfig.h"
#else
#import <GNUstepBase/GSConfig.h>
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif

/* The following is for deciding whether private instance variables
 * should be visible ... if we are building with a compiler which
 * does not define __has_feature then we know we don't have non-fragile
 * ivar support.
 * In the header we bracket instance variable declarations in a
 * '#if	GS_EXPOSE(classname) ... #endif' sequence, so that the variables
 * will not be visible to code which uses the library.
 * In the source file we define EXPOSE_classname_IVARS to be 1
 * before including the header, so that the ivars are always available
 * in the class source itsself
 */

#if	GS_MIXEDABI
#  undef	GS_NONFRAGILE
#  define	GS_NONFRAGILE	0	/* Mixed is treated as fragile */
#else
#  if (__has_feature(objc_nonfragile_abi))
#    if	!GS_NONFRAGILE
#      if	defined(GNUSTEP_BASE_INTERNAL)
#        error "You are building gnustep-base using the objc-nonfragile-abi but your gnustep-base was not configured to use it."
#      endif
#    endif
#  else
#    if	GS_NONFRAGILE
#      error "Your gnustep-base was configured for the objc-nonfragile-abi but you are not using it now."
#    endif
#  endif
#endif

#define	GS_EXPOSE(X)	(!GS_NONFRAGILE || defined(EXPOSE_##X##_IVARS))

/* Static analyser macros: Provide annotations to help the analyser */
#ifdef __clang__
#  define GS_NORETURN_METHOD __attribute__((__noreturn__))
#else
#  define GS_NORETURN_METHOD
#endif

#ifndef NS_RETURNS_RETAINED
#  if __has_feature(attribute_ns_returns_retained)
#    define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#  else
#    define NS_RETURNS_RETAINED
#  endif
#endif

#ifndef NS_RETURNS_NOT_RETAINED
#  if __has_feature(attribute_ns_returns_not_retained)
#    define NS_RETURNS_NOT_RETAINED __attribute__((ns_returns_not_retained))
#  else
#    define NS_RETURNS_NOT_RETAINED
#  endif
#endif

#ifndef NS_CONSUMED
#  if __has_feature(attribute_ns_consumed)
#    define NS_CONSUMED __attribute__((ns_consumed))
#  else
#    define NS_CONSUMED
#  endif
#endif


#ifndef NS_CONSUMES_SELF
#  if __has_feature(attribute_ns_consumes_self)
#    define NS_CONSUMES_SELF __attribute__((ns_consumes_self))
#  else
#    define NS_CONSUMES_SELF
#  endif
#endif

#if defined(__clang__) && defined(__OBJC__)
static inline void gs_consumed(id NS_CONSUMED o) __attribute__ ((unused));
static inline void gs_consumed(id NS_CONSUMED __attribute__ ((unused))o) { return; }
#define	GS_CONSUMED(O)	gs_consumed(O);
#else
#define	GS_CONSUMED(O)
#endif

/* Include the appropriate header for ObjC2 blocks support if it is in use.
 *
 * FIXME: "OBJC2RUNTIME" is set to "1" if the runtime supports the ObjC2
 * runtime API, which is unrelated to whether the compiler has blocks
 * support or not.
 */
#if __has_feature(blocks)
#  if	OBJC2RUNTIME
#    if defined(_APPLE_)
#      include <Block.h>
#    else
#      include <objc/blocks_runtime.h>
#    endif
#  else
#    include <ObjectiveC2/blocks_runtime.h>
#  endif
#endif



#if	defined(GNUSTEP_WITH_DLL)

#if BUILD_libgnustep_base_DLL
#
# if defined(__MINGW__)
  /* On Mingw, the compiler will export all symbols automatically, so
   * __declspec(dllexport) is not needed.
   */
#  define GS_EXPORT  extern
#  define GS_DECLARE
# else
#  define GS_EXPORT  __declspec(dllexport)
#  define GS_DECLARE __declspec(dllexport)
# endif
#else
#  define GS_EXPORT  extern __declspec(dllimport)
#  define GS_DECLARE __declspec(dllimport)
#endif

#else /* GNUSTEP_WITH[OUT]_DLL */

#  define GS_EXPORT extern
#  define GS_DECLARE

#endif

/* Attribute definitions for attributes which may or may not be supported
 * depending on the compiler being used.
 * The definition should be of the form GS_XXX_CONTEXT where XXX is the
 * name of the attribute and CONTEXT is one of FUNC, METH, or IVAR
 * depending on where the attribute can be applied.
 */

#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#  define GS_DEPRECATED_FUNC __attribute__ ((deprecated))
#else
#  define GS_DEPRECATED_FUNC
#endif

#ifdef __clang__
#  define GS_UNUSED_IVAR __attribute__((unused))
#else
#  define GS_UNUSED_IVAR
#endif


/*
 * Attribute definition for root classes, annotates the interface declaration of
 * the class.
 */
#ifndef GS_ROOT_CLASS
#  if GS_HAVE_OBJC_ROOT_CLASS_ATTR || __has_feature(attribute_objc_root_class)
#    define GS_ROOT_CLASS __attribute__((objc_root_class))
#  else
#    define GS_ROOT_CLASS
#  endif
#endif

#endif /* __GNUSTEP_GSVERSIONMACROS_H_INCLUDED_ */
