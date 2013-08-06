/* CFError.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: January, 2010
   
   This file is part of GNUstep CoreBase Library.
   
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

#ifndef __COREFOUNDATION_CFERROR_H__
#define __COREFOUNDATION_CFERROR_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDictionary.h>

CF_EXTERN_C_BEGIN

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED

#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSError;
typedef NSError * CFErrorRef;
#else
typedef const struct __CFError * CFErrorRef;
#endif

CF_EXPORT const CFStringRef kCFErrorDomainPOSIX;
CF_EXPORT const CFStringRef kCFErrorDomainOSStatus;
CF_EXPORT const CFStringRef kCFErrorDomainMach;
CF_EXPORT const CFStringRef kCFErrorDomainCocoa;

CF_EXPORT const CFStringRef kCFErrorLocalizedDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedFailureReasonKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedRecoverySuggestionKey;
CF_EXPORT const CFStringRef kCFErrorDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorUnderlyingErrorKey;



/*
 * Creating a CFError
 */
CF_EXPORT CFErrorRef
CFErrorCreate (CFAllocatorRef allocator, CFStringRef domain, CFIndex code,
  CFDictionaryRef userInfo);

CF_EXPORT CFErrorRef
CFErrorCreateWithUserInfoKeysAndValues (CFAllocatorRef allocator,
  CFStringRef domain, CFIndex code, const void *const *userInfoKeys,
  const void *const *userInfoValues, CFIndex numUserInfoValues);

/*
 * Getting Information About an Error
 */
CF_EXPORT CFStringRef
CFErrorGetDomain (CFErrorRef err);

CF_EXPORT CFIndex
CFErrorGetCode (CFErrorRef err);

CF_EXPORT CFDictionaryRef
CFErrorCopyUserInfo (CFErrorRef err);

CF_EXPORT CFStringRef
CFErrorCopyDescription (CFErrorRef err);

CF_EXPORT CFStringRef
CFErrorCopyFailureReason (CFErrorRef err);

CF_EXPORT CFStringRef
CFErrorCopyRecoverySuggestion (CFErrorRef err);

/*
 * Getting the CFError Type ID
 */
CF_EXPORT CFTypeID
CFErrorGetTypeID (void);

#endif /* MAC_OS_X_VERSION_10_5 */

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFERROR_H__ */

