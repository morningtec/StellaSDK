/* GNUstep.h - macros to make easier to port gnustep apps to macos-x
   Copyright (C) 2001 Free Software Foundation, Inc.

   Written by: Nicola Pero <n.pero@mi.flashnet.it>
   Date: March, October 2001
   
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

#ifndef __GNUSTEP_GNUSTEP_H_INCLUDED_
#define __GNUSTEP_GNUSTEP_H_INCLUDED_

/* The contents of this file are designed to be usable with either
 * GNUstep-base or MacOS-X Foundation.
 */

#ifndef __has_feature
#  define __has_feature(x) 0
#endif

#if	GS_WITH_GC || __has_feature(objc_arc)

#ifndef	RETAIN
#define	RETAIN(object)		(object)
#endif
#ifndef	RELEASE
#define	RELEASE(object)		
#endif
#ifndef	AUTORELEASE
#define	AUTORELEASE(object)	(object)
#endif

#ifndef	TEST_RETAIN
#define	TEST_RETAIN(object)	(object)
#endif
#ifndef	TEST_RELEASE
#define	TEST_RELEASE(object)
#endif
#ifndef	TEST_AUTORELEASE
#define	TEST_AUTORELEASE(object)	(object)
#endif

#ifndef	ASSIGN
#define	ASSIGN(object,value)	object = (value)
#endif
#ifndef	ASSIGNCOPY
#define	ASSIGNCOPY(object,value)	object = [(value) copy]
#endif
#ifndef	DESTROY
#define	DESTROY(object) 	object = nil
#endif

#define	IF_NO_GC(X)	

#else

#ifndef	RETAIN
/**
 *	Basic retain operation ... calls [NSObject-retain]<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -retain method.
 */
#define	RETAIN(object)		[(object) retain]
#endif

#ifndef	RELEASE
/**
 *	Basic release operation ... calls [NSObject-release]<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -release method.
 */
#define	RELEASE(object)		[(object) release]
#endif

#ifndef	AUTORELEASE
/**
 *	Basic autorelease operation ... calls [NSObject-autorelease]<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -autorelease method.
 */
#define	AUTORELEASE(object)	[(object) autorelease]
#endif

#ifndef	TEST_RETAIN
/**
 *	Tested retain - only invoke the
 *	objective-c method if the receiver is not nil.<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -retain method.
 */
#define	TEST_RETAIN(object)	({\
id __object = (object); (__object != nil) ? [__object retain] : nil; })
#endif

#ifndef	TEST_RELEASE
/**
 *	Tested release - only invoke the
 *	objective-c method if the receiver is not nil.<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -release method.
 */
#define	TEST_RELEASE(object)	({\
id __object = (object); if (__object != nil) [__object release]; })
#endif

#ifndef	TEST_AUTORELEASE
/**
 *	Tested autorelease - only invoke the
 *	objective-c method if the receiver is not nil.<br />
 *	Deprecated ... pointless on modern processors.
 *	Simply call the -autorelease method.
 */
#define	TEST_AUTORELEASE(object)	({\
id __object = (object); (__object != nil) ? [__object autorelease] : nil; })
#endif

#ifndef	ASSIGN
/**
 *	ASSIGN(object,value) assigns the value to the object with
 *	appropriate retain and release operations.<br />
 *	Use this to avoid retain/release errors.
 */
#define	ASSIGN(object,value)	({\
  id __object = object; \
  object = [(value) retain]; \
  [__object release]; \
})
#endif

#ifndef	ASSIGNCOPY
/**
 *	ASSIGNCOPY(object,value) assigns a copy of the value to the object
 *	with release of the original.<br />
 *	Use this to avoid retain/release errors.
 */
#define	ASSIGNCOPY(object,value)	({\
  id __object = object; \
  object = [(value) copy];\
  [__object release]; \
})
#endif

#ifndef	DESTROY
/**
 *	DESTROY() is a release operation which also sets the variable to be
 *	a nil pointer for tidiness - we can't accidentally use a DESTROYED
 *	object later.  It also makes sure to set the variable to nil before
 *	releasing the object - to avoid side-effects of the release trying
 *	to reference the object being released through the variable.
 */
#define	DESTROY(object) 	({ \
  id __o = object; \
  object = nil; \
  [__o release]; \
})
#endif

#define	IF_NO_GC(X)	X

#endif

#ifndef	CREATE_AUTORELEASE_POOL
/** DEPRECATED ... use NSAutoreleasePool *X = [NSAutoreleasePool new]
 */
#define	CREATE_AUTORELEASE_POOL(X)	\
  NSAutoreleasePool *X = [NSAutoreleasePool new]
#endif

#ifndef RECREATE_AUTORELEASE_POOL
/** DEPRECATED ... use [X release]; X = [NSAutoreleasePool new]
 */
#define RECREATE_AUTORELEASE_POOL(X)  \
  DESTROY(X);\
  X = [NSAutoreleasePool new]
#endif


/**
 * <p>
 *   This function (macro) is a GNUstep extension.
 * </p>
 * <p>
 *   <code>_(@"My string to translate")</code>
 * </p>
 * <p>
 *   is basically equivalent to
 * </p>
 * <p>
 *   <code>NSLocalizedString(@"My string to translate", @"")</code>
 * </p>
 * <p>
 * It is useful when you need to translate an application
 * very quickly, as you just need to enclose all strings
 * inside <code>_()</code>.  But please note that when you
 * use this macro, you are not taking advantage of comments
 * for the translator, so consider using
 * <code>NSLocalizedString</code> instead when you need a
 * comment.
 * </p>
 * <p>You may define GS_LOCALISATION_BUNDLE_ID to the bundle identifier
 * of the bundle which is to provide the localisation information.<br />
 * This can be used when compiling a single file by specifying something like
 * '-D GS_LOCALISATION_BUNDLE_ID=$(FRAMEWORK_NAME)' in your make file.<br />
 * If this is not defined, the localisation is provided by your application's
 * main bundle exactly like the NSLocalizedString function.
 * </p>
 * <p>Alternatively you may define GS_LOCALISATION_BUNDLE to be the bundle
 * to be used to prvide the localisation information.
 * </p>
 */
# define _(X) \
  [GS_LOCALISATION_BUNDLE localizedStringForKey: (X) value: @"" table: nil]

#if	!defined(GS_LOCALISATION_BUNDLE)
# if	defined(GS_LOCALISATION_BUNDLE_ID)
#   define	GS_LOCALISATION_BUNDLE	[NSBundle bundleWithIdentifier: \
  GS_LOCALISATION_BUNDLE_ID]
# else
#   define	GS_LOCALISATION_BUNDLE	[NSBundle mainBundle]
# endif
#endif


 
/**
 * <p>
 *   This function (macro) is a GNUstep extension.
 * </p>
 * <p>
 *   <code>__(@"My string to translate")</code>
 * </p>
 * <p>
 *   is exactly the same as
 * </p>
 * <p>
 *   <code>GSLocalizedStaticString(@"My string to translate", @"")</code>
 * </p>
 * <p>
 *   It is useful when you need to translate an application very
 *   quickly.  You would use it as follows for static strings:
 * </p>
 * <p>
 *  <code>
 *    NSString *message = __(@"Hello there");
 *    ... more code ...
 *    NSLog (_(messages));
 *  </code>
 * </p>
 * <p>
 *   But please note that when you use this macro, you are not
 *   taking advantage of comments for the translator, so
 *   consider using <code>GSLocalizedStaticString</code>
 *   instead when you need a comment.
 * </p>
 */
#define __(X) X

/* The better way for a static string, with a comment - use as follows -
 *
 * static NSString *string = GSLocalizedStaticString (@"New Game",
 *                                                    @"Menu Option");
 *
 * NSLog (_(string));
 *
 * If you need anything more complicated than this, please initialize
 * the static strings manually.
 */

/**
 * <p>
 *   This function (macro) is a GNUstep extensions, and it is used
 *   to localize static strings.  Here is an example of a static
 *   string:
 * </p>
 * <p>
 *   <code>
 *     NSString *message = @"Hi there";
 *     ... some code ...
 *     NSLog (message);
 *  </code>
 * </p>
 * <p>
 *   This string can not be localized using the standard
 *   openstep functions/macros.  By using this gnustep extension,
 *   you can localize it as follows:
 * </p>
 * <p>
 *   <code>
 *     NSString *message = GSLocalizedStaticString (@"Hi there",
 *       @"Greeting");
 * 
 *     ... some code ...
 * 
 *     NSLog (NSLocalizedString (message, @""));
 *  </code>
 * </p>
 * <p>
 *   When the tools generate the
 *   <code>Localizable.strings</code> file from the source
 *   code, they will ignore the <code>NSLocalizedString</code>
 *   call while they will extract the string (and the comment)
 *   to localize from the <code>GSLocalizedStaticString</code>
 *   call.
 * </p>
 * <p>
 *   When the code is compiled, instead, the
 *   <code>GSLocalizedStaticString</code> call is ignored (discarded,
 *   it is a macro which simply expands to <code>key</code>), while
 *   the <code>NSLocalizedString</code> will actually look up the
 *   string for translation in the <code>Localizable.strings</code>
 *   file.
 * </p>
 * <p>
 *   Please note that there is currently no macro/function to
 *   localize static strings using different tables.  If you
 *   need that functionality, you have either to prepare the
 *   localization tables by hand, or to rewrite your code in
 *   such a way as not to use static strings.
 * </p>
 */
#define GSLocalizedStaticString(key, comment) key

/**
 * To be used inside a method for making sure that a range does not specify
 * anything outside the size of an array/string.  Raises exception if range
 * extends beyond [0,size).
 */
#define GS_RANGE_CHECK(RANGE, SIZE) \
  if (RANGE.location > SIZE || RANGE.length > (SIZE - RANGE.location)) \
    [NSException raise: NSRangeException \
                 format: @"in %s, range { %u, %u } extends beyond size (%u)", \
		 GSNameFromSelector(_cmd), RANGE.location, RANGE.length, SIZE]

/** Checks whether INDEX is strictly less than OVER (within C array space). */
#define CHECK_INDEX_RANGE_ERROR(INDEX, OVER) \
if (INDEX >= OVER) \
  [NSException raise: NSRangeException \
               format: @"in %s, index %d is out of range", \
               GSNameFromSelector(_cmd), INDEX]

#endif /* __GNUSTEP_GNUSTEP_H_INCLUDED_ */
