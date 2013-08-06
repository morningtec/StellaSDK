/* CFNumberFormatter.h
   
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
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFNUMBERFORMATTER__
#define __COREFOUNDATION_CFNUMBERFORMATTER__ 1

#include <CoreFoundation/CFBase.h>

#include <CoreFoundation/CFLocale.h>
#include <CoreFoundation/CFNumber.h>

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

/** @defgroup CFNumberFormatter
    @brief CFNumberFormatter can be used to format and parse CFStrings
    into numbers.
    
    Unlike other Core Foundation types with similar names to Cocoa classes
    CFNumberFormatter is @b not "toll-free bridged" to NSNumberFormatter.
    
    @{
 */
typedef struct __CFNumberFormatter *CFNumberFormatterRef;

typedef CFOptionFlags CFNumberFormatterOptionFlags;
enum
{
  kCFNumberFormatterParseIntegersOnly = 1
};

typedef CFIndex CFNumberFormatterPadPosition;
enum
{
  kCFNumberFormatterPadBeforePrefix = 0,
  kCFNumberFormatterPadAfterPrefix  = 1,
  kCFNumberFormatterPadBeforeSuffix = 2,
  kCFNumberFormatterPadAfterSuffix  = 3
};

typedef enum
{
  kCFNumberFormatterRoundCeiling  = 0,
  kCFNumberFormatterRoundFloor    = 1,
  kCFNumberFormatterRoundDown     = 2,
  kCFNumberFormatterRoundUp       = 3,
  kCFNumberFormatterRoundHalfEven = 4,
  kCFNumberFormatterRoundHalfDown = 5,
  kCFNumberFormatterRoundHalfUp   = 6
} CFNumberFormatterRoundingMode;

typedef enum
{
  kCFNumberFormatterNoStyle         = 0,
  kCFNumberFormatterDecimalStyle    = 1,
  kCFNumberFormatterCurrencyStyle   = 2,
  kCFNumberFormatterPercentStyle    = 3,
  kCFNumberFormatterScientificStyle = 4,
  kCFNumberFormatterSpellOutStyle   = 5
} CFNumberFormatterStyle;

CF_EXPORT const CFStringRef kCFNumberFormatterCurrencyCode; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterDecimalSeparator; /* CFString */
CF_EXPORT const CFStringRef
  kCFNumberFormatterCurrencyDecimalSeparator; /* CFString */
CF_EXPORT const CFStringRef
  kCFNumberFormatterAlwaysShowDecimalSeparator; /* CFBoolean */
CF_EXPORT const CFStringRef kCFNumberFormatterGroupingSeparator; /* CFString */
CF_EXPORT const CFStringRef
  kCFNumberFormatterUseGroupingSeparator; /* CFBoolean */
CF_EXPORT const CFStringRef kCFNumberFormatterPercentSymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterZeroSymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterNaNSymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterInfinitySymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterMinusSign; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterPlusSign; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterCurrencySymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterExponentSymbol; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterMinIntegerDigits; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterMaxIntegerDigits; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterMinFractionDigits; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterMaxFractionDigits; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterGroupingSize; /* CFNumber */
CF_EXPORT const CFStringRef
  kCFNumberFormatterSecondaryGroupingSize; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterRoundingMode; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterRoundingIncrement; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterFormatWidth; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterPaddingPosition; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterPaddingCharacter; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterDefaultFormat; /* CFString */
#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFNumberFormatterMultiplier; /* CFNumber */
CF_EXPORT const CFStringRef kCFNumberFormatterPositivePrefix; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterPositiveSuffix; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterNegativePrefix; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterNegativeSuffix; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterPerMillSymbol; /* CFString */
CF_EXPORT const CFStringRef
  kCFNumberFormatterInternationalCurrencySymbol; /* CFString */
#endif
#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED 
CF_EXPORT const CFStringRef
  kCFNumberFormatterCurrencyGroupingSeparator; /* CFString */
CF_EXPORT const CFStringRef kCFNumberFormatterIsLenient; /* CFBoolean */
CF_EXPORT const CFStringRef
  kCFNumberFormatterUseSignificantDigits; /* CFBoolean */
CF_EXPORT const CFStringRef
  kCFNumberFormatterMinSignificantDigits; /* CFNumber */
CF_EXPORT const CFStringRef
  kCFNumberFormatterMaxSignificantDigits; /* CFNumber */
#endif



/*
 * Creating a Number Formatter
 */
CF_EXPORT CFNumberFormatterRef
CFNumberFormatterCreate (CFAllocatorRef allocator, CFLocaleRef locale,
  CFNumberFormatterStyle style);

/*
 * Configuring a Number Formatter
 */
void
CFNumberFormatterSetFormat (CFNumberFormatterRef formatter,
  CFStringRef formatString);

void
CFNumberFormatterSetProperty (CFNumberFormatterRef formatter,
  CFStringRef key, CFTypeRef value);

/*
 * Formatting Values
 */
CFNumberRef
CFNumberFormatterCreateNumberFromString (CFAllocatorRef allocator,
  CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep,
  CFOptionFlags options);

CFStringRef
CFNumberFormatterCreateStringWithNumber (CFAllocatorRef allocator,
  CFNumberFormatterRef formatter, CFNumberRef number);

CFStringRef
CFNumberFormatterCreateStringWithValue (CFAllocatorRef allocator,
  CFNumberFormatterRef formatter, CFNumberType numberType,
  const void *valuePtr);

Boolean
CFNumberFormatterGetDecimalInfoForCurrencyCode (CFStringRef currencyCode,
  SInt32 *defaultFractionDigits, double *roundingIncrement);

Boolean
CFNumberFormatterGetValueFromString (CFNumberFormatterRef formatter,
  CFStringRef string, CFRange *rangep, CFNumberType numberType, void *valuePtr);

/*
 * Examining a Number Formatter
 */
CFTypeRef
CFNumberFormatterCopyProperty (CFNumberFormatterRef formatter,
  CFStringRef key);

CFStringRef
CFNumberFormatterGetFormat (CFNumberFormatterRef formatter);

CFLocaleRef
CFNumberFormatterGetLocale (CFNumberFormatterRef formatter);

CFNumberFormatterStyle
CFNumberFormatterGetStyle (CFNumberFormatterRef formatter);

/*
 * Getting the CFNumberFormatter Type ID
 */
CFTypeID
CFNumberFormatterGetTypeID (void);

/** @}
*/

CF_EXTERN_C_END

#endif /* MAC_OS_X_VERSION_10_3 */

#endif /* __COREFOUNDATION_CFNUMBERFORMATTER__ */

