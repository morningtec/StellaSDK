/* CFURLAccess.h
   
   Copyright (C) 2012 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: April, 2012
   
   This file is part of CoreBase.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFURLACCESS__
#define __COREFOUNDATION_CFURLACCESS__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFURL.h>

CF_EXTERN_C_BEGIN

/*
 * File URL Properties
 */
CF_EXPORT const CFStringRef kCFURLFileExists; /* CFBoolean */
CF_EXPORT const CFStringRef kCFURLFileDirectoryContents; /* CFArray */
CF_EXPORT const CFStringRef kCFURLFileLength; /* CFNumber */
CF_EXPORT const CFStringRef kCFURLFileLastModificationTime; /* CFDate */
CF_EXPORT const CFStringRef kCFURLFilePOSIXMode; /* CFNumber */
CF_EXPORT const CFStringRef kCFURLFileOwnerID; /* CFNumber */

/*
 * HTTP URL Properties
 */
CF_EXPORT const CFStringRef kCFURLHTTPStatusCode; /*CFNumber */
CF_EXPORT const CFStringRef kCFURLHTTPStatusLine; /* CFString */

/*
 * Error Codes
 */
typedef enum
{
  kCFURLUnknownError =                 -10,
  kCFURLUnknownSchemeError =           -11,
  kCFURLResourceNotFoundError =        -12,
  kCFURLResourceAccessViolationError = -13,
  kCFURLRemoteHostUnavailableError =   -14,
  kCFURLImproperArgumentsError =       -15,
  kCFURLUnknownPropertyKeyError =      -16,
  kCFURLPropertyKeyUnavailableError =  -17,
  kCFURLTimeoutError =                 -18
} CFURLError;

CF_EXPORT Boolean
CFURLCreateDataAndPropertiesFromResource (CFAllocatorRef alloc, CFURLRef url,
  CFDataRef *resourceData, CFDictionaryRef *properties,
  CFArrayRef desiredProperties, SInt32 *errorCode);

CF_EXPORT CFTypeRef
CFURLCreatePropertyFromResource (CFAllocatorRef alloc, CFURLRef url,
  CFStringRef property, SInt32 *errorCode);

CF_EXPORT Boolean
CFURLDestroyResource (CFURLRef url, SInt32 *errorCode);

CF_EXPORT Boolean
CFURLWriteDataAndPropertiesToResource (CFURLRef url, CFDataRef dataToWrite,
  CFDictionaryRef propertiesToWrite, SInt32 *errorCode);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFURLACCESS__ */

