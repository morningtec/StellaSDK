/* CFCalendar.h
   
   Copyright (C) 2011 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: March, 2011
   
   This file is part of the GNUstep CoreBase Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFCALENDAR__
#define __COREFOUNDATION_CFCALENDAR__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFLocale.h>

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

/** CFCalendar is "toll-free bridged" to NSCalendar.
 */
typedef struct __CFCalendar *CFCalendarRef;

typedef enum
{
  kCFCalendarUnitEra = (1UL << 1),
  kCFCalendarUnitYear = (1UL << 2),
  kCFCalendarUnitMonth = (1UL << 3),
  kCFCalendarUnitDay = (1UL << 4),
  kCFCalendarUnitHour = (1UL << 5),
  kCFCalendarUnitMinute = (1UL << 6),
  kCFCalendarUnitSecond = (1UL << 7),
  kCFCalendarUnitWeek = (1UL << 8),
  kCFCalendarUnitWeekday = (1UL << 9),
  kCFCalendarUnitWeekdayOrdinal = (1UL << 10),
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
  kCFCalendarUnitQuarter = (1UL << 11),
#endif
} CFCalendarUnit;

enum
{
  kCFCalendarComponentsWrap = (1UL << 0)
};

/*
 * Creating a Calendar
 */
CFCalendarRef
CFCalendarCopyCurrent (void);

CFCalendarRef
CFCalendarCreateWithIdentifier (CFAllocatorRef allocator, CFStringRef ident);

/*
 * Calendrical Calculations
 */
Boolean
CFCalendarAddComponents (CFCalendarRef cal, CFAbsoluteTime *at,
  CFOptionFlags options, const char *componentDesc, ...);

Boolean
CFCalendarComposeAbsoluteTime (CFCalendarRef cal, CFAbsoluteTime *at,
  const char *componentDesc, ...);

Boolean
CFCalendarDecomposeAbsoluteTime (CFCalendarRef cal, CFAbsoluteTime at,
  const char *componentDesc, ...);

Boolean
CFCalendarGetComponentDifference (CFCalendarRef cal, CFAbsoluteTime startinAT,
  CFAbsoluteTime resultAT, CFOptionFlags options,
  const char *componentDesc, ...);

/*
 * Getting Ranges of Units
 */
CFRange
CFCalendarGetRangeOfUnit (CFCalendarRef cal, CFCalendarUnit smallerUnit,
  CFCalendarUnit biggerUnit, CFAbsoluteTime at);

CFIndex
CFCalendarGetOrdinalityOfUnit (CFCalendarRef cal, CFCalendarUnit smallerUnit,
  CFCalendarUnit biggerUnit, CFAbsoluteTime at);

CFRange
CFCalendarGetMaximumRangeOfUnit (CFCalendarRef cal, CFCalendarUnit unit);

CFRange
CFCalendarGetMinimumRangeOfUnit (CFCalendarRef cal, CFCalendarUnit unit);

/*
 * Getting and Setting the Time Zone
 */
CFTimeZoneRef
CFCalendarCopyTimeZone (CFCalendarRef cal);

void
CFCalendarSetTimeZone (CFCalendarRef cal, CFTimeZoneRef tz);

/*
 * Getting the Identifier
 */
CFStringRef
CFCalendarGetIdentifier (CFCalendarRef cal);

/*
 * Getting and Setting the Locale
 */
CFLocaleRef
CFCalendarCopyLocale (CFCalendarRef cal);

void
CFCalendarSetLocale (CFCalendarRef cal, CFLocaleRef locale);

/*
 * Getting and Setting Day Information
 */
CFIndex
CFCalendarGetFirstWeekday (CFCalendarRef cal);

void
CFCalendarSetFirstWeekday (CFCalendarRef cal, CFIndex wkdy);

CFIndex
CFCalendarGetMinimumDaysInFirstWeek (CFCalendarRef cal);

void
CFCalendarSetMinimumDaysInFirstWeek (CFCalendarRef cal, CFIndex mwd);

/*
 * Getting the Type ID
 */
CFTypeID
CFCalendarGetTypeID (void);

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED
Boolean
CFCalendarGetTimeRangeOfUnit (CFCalendarRef cal, CFCalendarUnit unit,
  CFAbsoluteTime at, CFAbsoluteTime *startp, CFTimeInterval *tip);
#endif

CF_EXTERN_C_END

#endif /* MAC_OS_X_VERSION_10_4 */

#endif /* __COREFOUNDATION_CFCALENDAR__ */

