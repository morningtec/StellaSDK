/* CFPropertyList.h
   
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

#ifndef __COREFOUNDATION_CFPROPERTYLIST_H__
#define __COREFOUNDATION_CFPROPERTYLIST_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFError.h>
#include <CoreFoundation/CFStream.h>

CF_EXTERN_C_BEGIN

#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
typedef enum
{
   kCFPropertyListOpenStepFormat = 1,
   kCFPropertyListXMLFormat_v1_0 = 100,
   kCFPropertyListBinaryFormat_v1_0 = 200
} CFPropertyListFormat;
#endif

typedef enum
{
   kCFPropertyListImmutable = 0,
   kCFPropertyListMutableContainers = 1,
   kCFPropertyListMutableContainersAndLeaves = 2
} CFPropertyListMutabilityOptions;

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
enum
{
   kCFPropertyListReadCorruptError = 3840,
   kCFPropertyListReadUnknownVersionError = 3841,
   kCFPropertyListReadStreamError = 3842,
   kCFPropertyListWriteStreamError = 3851,
};
#endif



CF_EXPORT CFPropertyListRef
CFPropertyListCreateDeepCopy (CFAllocatorRef allocator,
                              CFPropertyListRef propertyList,
                              CFOptionFlags mutabilityOption);

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFDataRef
CFPropertyListCreateData (CFAllocatorRef allocator,
                          CFPropertyListRef propertyList,
                          CFPropertyListFormat format, CFOptionFlags options,
                          CFErrorRef *error);

CF_EXPORT CFPropertyListRef
CFPropertyListCreateWithData (CFAllocatorRef allocator, CFDataRef data,
                              CFOptionFlags options,
                              CFPropertyListFormat *format,
                              CFErrorRef *error);

CF_EXPORT CFPropertyListRef
CFPropertyListCreateWithStream (CFAllocatorRef allocator,
                                CFReadStreamRef stream,
                                CFIndex streamLength, CFOptionFlags options,
                                CFPropertyListFormat *format,
                                CFErrorRef *error);

CF_EXPORT CFIndex
CFPropertyListWrite (CFPropertyListRef propertyList, CFWriteStreamRef stream,
                     CFPropertyListFormat format, CFOptionFlags options,
                     CFErrorRef *error);
#endif

#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT Boolean
CFPropertyListIsValid (CFPropertyListRef plist, CFPropertyListFormat format);
#endif

/* The following function are marked as obsolete as of 10.6 */
CF_EXPORT CFPropertyListRef
CFPropertyListCreateFromXMLData (CFAllocatorRef allocator, CFDataRef xmlData,
                                 CFOptionFlags mutabilityOption,
                                 CFStringRef *errorString);

CF_EXPORT CFDataRef
CFPropertyListCreateXMLData (CFAllocatorRef allocator,
                             CFPropertyListRef propertyList);

#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFPropertyListRef
CFPropertyListCreateFromStream (CFAllocatorRef allocator,
                                CFReadStreamRef stream,
                                CFIndex streamLength,
                                CFOptionFlags mutabilityOption,
                                CFPropertyListFormat *format,
                                CFStringRef *errorString);

CF_EXPORT CFIndex
CFPropertyListWriteToStream (CFPropertyListRef propertyList,
                             CFWriteStreamRef stream,
                             CFPropertyListFormat format,
                             CFStringRef *errorString);
#endif

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFPROPERTYLIST_H__ */
