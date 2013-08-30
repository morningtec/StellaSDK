/* CFBitVector.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: December, 2011
   
   This file is part of the GNUstep CoreBase Library.
   
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

#ifndef __COREFOUNDATION_CFBITVECTOR_H__
#define __COREFOUNDATION_CFBITVECTOR_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

typedef const struct __CFBitVector *CFBitVectorRef;
typedef struct __CFBitVector *CFMutableBitVectorRef;

typedef UInt32 CFBit;

/*
 * Creating a Bit Vector
 */
CF_EXPORT CFBitVectorRef
CFBitVectorCreate (CFAllocatorRef allocator, const UInt8 *bytes,
  CFIndex numBits);

CF_EXPORT CFBitVectorRef
CFBitVectorCreateCopy (CFAllocatorRef allocator, CFBitVectorRef bv);

/*
 * Getting Information About a Bit Vector
 */
CF_EXPORT Boolean
CFBitVectorContainsBit (CFBitVectorRef bv, CFRange range, CFBit value);

CF_EXPORT CFBit
CFBitVectorGetBitAtIndex (CFBitVectorRef bv, CFIndex idx);

CF_EXPORT void
CFBitVectorGetBits (CFBitVectorRef bv, CFRange range, UInt8 *bytes);

CF_EXPORT CFIndex
CFBitVectorGetCount (CFBitVectorRef bv);

CF_EXPORT CFIndex
CFBitVectorGetCountOfBit (CFBitVectorRef bv, CFRange range, CFBit value);

CF_EXPORT CFIndex
CFBitVectorGetFirstIndexOfBit (CFBitVectorRef bv, CFRange range, CFBit value);

CF_EXPORT CFIndex
CFBitVectorGetLastIndexOfBit (CFBitVectorRef bv, CFRange range, CFBit value);

/*
 * Getting the CFBitVector Type ID
 */
CF_EXPORT CFTypeID
CFBitVectorGetTypeID (void);



/*
 * CFMutableBitVector
 */
CF_EXPORT CFMutableBitVectorRef
CFBitVectorCreateMutable (CFAllocatorRef allocator, CFIndex capacity);

CF_EXPORT CFMutableBitVectorRef
CFBitVectorCreateMutableCopy (CFAllocatorRef allocator, CFIndex capacity,
  CFBitVectorRef bv);

CF_EXPORT void
CFBitVectorFlipBitAtIndex (CFMutableBitVectorRef bv, CFIndex idx);

CF_EXPORT void
CFBitVectorFlipBits (CFMutableBitVectorRef bv, CFRange range);

CF_EXPORT void
CFBitVectorSetAllBits (CFMutableBitVectorRef bv, CFBit value);

CF_EXPORT void
CFBitVectorSetBitAtIndex (CFMutableBitVectorRef bv, CFIndex idx, CFBit value);

CF_EXPORT void
CFBitVectorSetBits (CFMutableBitVectorRef bv, CFRange range, CFBit value);

CF_EXPORT void
CFBitVectorSetCount (CFMutableBitVectorRef bv, CFIndex count);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFBITVECTOR_H__ */

