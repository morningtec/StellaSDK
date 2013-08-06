/* CFTimeZone.c
   
   Copyright (C) 2011 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: July, 2011
   
   This file is part of the GNUstep CoreBase Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFTIMEZONE__
#define __COREFOUNDATION_CFTIMEZONE__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFLocale.h>

CF_EXTERN_C_BEGIN

CF_EXPORT const CFStringRef kCFTimeZoneSystemTimeZoneDidChangeNotification;

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED
typedef enum
{
  kCFTimeZoneNameStyleStandard,
  kCFTimeZoneNameStyleShortStandard,
  kCFTimeZoneNameStyleDaylightSaving,
  kCFTimeZoneNameStyleShortDaylightSaving
} CFTimeZoneNameStyle;
#endif


CF_EXPORT CFTimeZoneRef
CFTimeZoneCreateWithName (CFAllocatorRef alloc, CFStringRef name,
  Boolean tryAbbrev);

CF_EXPORT CFTimeZoneRef
CFTimeZoneCreateWithTimeIntervalFromGMT (CFAllocatorRef alloc,
  CFTimeInterval ti);

CF_EXPORT CFTimeZoneRef
CFTimeZoneCreate (CFAllocatorRef alloc, CFStringRef name, CFDataRef data);

CF_EXPORT CFDictionaryRef
CFTimeZoneCopyAbbreviationDictionary (void);

CF_EXPORT CFStringRef
CFTimeZoneCopyAbbreviation (CFTimeZoneRef tz, CFAbsoluteTime at);

CF_EXPORT CFTimeZoneRef
CFTimeZoneCopyDefault (void);

CF_EXPORT CFTimeZoneRef
CFTimeZoneCopySystem (void);

CF_EXPORT void
CFTimeZoneSetDefault (CFTimeZoneRef tz);

CF_EXPORT CFArrayRef
CFTimeZoneCopyKnownNames (void);

CF_EXPORT void
CFTimeZoneResetSystem (void);

CF_EXPORT void
CFTimeZoneSetAbbreviationDictionary (CFDictionaryRef dict);

CF_EXPORT CFStringRef
CFTimeZoneGetName (CFTimeZoneRef tz);

CF_EXPORT CFTimeInterval
CFTimeZoneGetSecondsFromGMT (CFTimeZoneRef tz, CFAbsoluteTime at);

CF_EXPORT CFDataRef
CFTimeZoneGetData (CFTimeZoneRef tz);

CF_EXPORT Boolean
CFTimeZoneIsDaylightSavingTime (CFTimeZoneRef tz, CFAbsoluteTime at);

CF_EXPORT CFTypeID
CFTimeZoneGetTypeID (void);

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFStringRef
CFTimeZoneCopyLocalizedName (CFTimeZoneRef tz, CFTimeZoneNameStyle style,
  CFLocaleRef locale);

CF_EXPORT CFTimeInterval
CFTimeZoneGetDaylightSavingTimeOffset (CFTimeZoneRef tz, CFAbsoluteTime at);

CF_EXPORT CFAbsoluteTime
CFTimeZoneGetNextDaylightSavingTimeTransition (CFTimeZoneRef tz,
  CFAbsoluteTime at);
#endif

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFTIMEZONE__ */

