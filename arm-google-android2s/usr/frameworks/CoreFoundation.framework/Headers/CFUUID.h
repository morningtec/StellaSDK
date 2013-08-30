/* CFUUID.h
   
   Copyright (C) 2011 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: May, 2011
   
   This file is part of GNUstep CoreBase Library.
   
   This library is free software; you can redisibute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is disibuted in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFUUID_H__
#define __COREFOUNDATION_CFUUID_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

typedef const struct __CFUUID *CFUUIDRef;

typedef struct
{
  UInt8 byte0;
  UInt8 byte1;
  UInt8 byte2;
  UInt8 byte3;
  UInt8 byte4;
  UInt8 byte5;
  UInt8 byte6;
  UInt8 byte7;
  UInt8 byte8;
  UInt8 byte9;
  UInt8 byte10;
  UInt8 byte11;
  UInt8 byte12;
  UInt8 byte13;
  UInt8 byte14;
  UInt8 byte15;
} CFUUIDBytes;



/*
 * Creating CFUUID Objects
 */
CF_EXPORT CFUUIDRef
CFUUIDCreate (CFAllocatorRef alloc);

CF_EXPORT CFUUIDRef
CFUUIDCreateFromString (CFAllocatorRef alloc, CFStringRef uuidStr);

CF_EXPORT CFUUIDRef
CFUUIDCreateFromUUIDBytes (CFAllocatorRef alloc, CFUUIDBytes bytes);

CF_EXPORT CFUUIDRef
CFUUIDCreateWithBytes (CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1,
  UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7,
  UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12,
  UInt8 byte13, UInt8 byte14, UInt8 byte15);


/*
 * Getting Information About CFUUID Objects
 */
CF_EXPORT CFStringRef
CFUUIDCreateString (CFAllocatorRef alloc, CFUUIDRef uuid);

CF_EXPORT CFUUIDRef
CFUUIDGetConstantUUIDWithBytes (CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1,
  UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7,
  UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12,
  UInt8 byte13, UInt8 byte14, UInt8 byte15);

CF_EXPORT CFUUIDBytes
CFUUIDGetUUIDBytes (CFUUIDRef uuid);

/*
 * Getting the CFUUID Type Identifier
 */
CF_EXPORT CFTypeID
CFUUIDGetTypeID (void);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFUUID_H__ */

