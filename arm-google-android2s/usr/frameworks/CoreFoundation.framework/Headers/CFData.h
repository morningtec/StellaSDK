/* CFData.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: January, 2010
   
   This file is part of CoreBase.
   
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

#ifndef __COREFOUNDATION_CFDATA_H__
#define __COREFOUNDATION_CFDATA_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSData;
@class NSMutableData;
typedef NSData* CFDataRef;
typedef NSMutableData* CFMutableDataRef;
#else
typedef const struct __CFData * CFDataRef;
typedef struct __CFData * CFMutableDataRef;
#endif


/*
 * Creating a CFData Object
 */
CF_EXPORT CFDataRef
CFDataCreate (CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length);

CF_EXPORT CFDataRef
CFDataCreateCopy (CFAllocatorRef allocator, CFDataRef theData);

CF_EXPORT CFDataRef
CFDataCreateWithBytesNoCopy (CFAllocatorRef allocator,const UInt8 *bytes,
  CFIndex length, CFAllocatorRef bytesDeallocator);

/*
 * Examining a CFData Object
 */
CF_EXPORT const UInt8 *
CFDataGetBytePtr (CFDataRef theData);

CF_EXPORT void
CFDataGetBytes (CFDataRef theData, CFRange range, UInt8 *buffer);

CF_EXPORT CFIndex
CFDataGetLength (CFDataRef theData);

/*
 * Getting the CFData Type ID
 */
CF_EXPORT CFTypeID
CFDataGetTypeID (void);

/*
 * Creating a Mutable Data Object
 */
CF_EXPORT CFMutableDataRef
CFDataCreateMutable (CFAllocatorRef allocator, CFIndex capacity);

CF_EXPORT CFMutableDataRef
CFDataCreateMutableCopy (CFAllocatorRef allocator, CFIndex capacity,
  CFDataRef theData);

/*
 * Accessing Mutable Data
 */
CF_EXPORT UInt8 *
CFDataGetMutableBytePtr (CFMutableDataRef theData);

/*
 * Modifying a Mutable Data Object
 */
CF_EXPORT void
CFDataAppendBytes (CFMutableDataRef theData, const UInt8 *bytes, CFIndex length);

CF_EXPORT void
CFDataDeleteBytes (CFMutableDataRef theData, CFRange range);

CF_EXPORT void
CFDataReplaceBytes (CFMutableDataRef theData, CFRange range,
  const UInt8 *newBytes, CFIndex newLength);

CF_EXPORT void
CFDataIncreaseLength (CFMutableDataRef theData, CFIndex extraLength);

CF_EXPORT void
CFDataSetLength (CFMutableDataRef theData, CFIndex length);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFDATA_H__ */

