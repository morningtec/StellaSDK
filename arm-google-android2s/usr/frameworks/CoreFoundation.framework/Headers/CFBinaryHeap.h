/* CFBinaryHeap.h
   
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

#ifndef __COREFOUNDATION_CFBINARYHEAP_H__
#define __COREFOUNDATION_CFBINARYHEAP_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

typedef struct __CFBinaryHeap *CFBinaryHeapRef;



typedef void (*CFBinaryHeapApplierFunction) (const void *val, void *context);

typedef const void *(*CFBinaryHeapRetainCallBack) (CFAllocatorRef allocator,
  const void *ptr);
typedef void (*CFBinaryHeapReleaseCallBack) (CFAllocatorRef allocator,
  const void *ptr);
typedef CFStringRef (*CFBinaryHeapCopyDescriptionCallBack) (const void *ptr);
typedef CFComparisonResult (*CFBinaryHeapCompareCallBack) (const void *ptr1,
  const void *ptr2, void *info);

typedef struct CFBinaryHeapCallBacks CFBinaryHeapCallBacks;
struct CFBinaryHeapCallBacks
{
  CFIndex version;
  CFBinaryHeapRetainCallBack retain;
  CFBinaryHeapReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFBinaryHeapCompareCallBack compare;
};

typedef struct CFBinaryHeapCompareContext CFBinaryHeapCompareContext;
struct CFBinaryHeapCompareContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};

CF_EXPORT const CFBinaryHeapCallBacks kCFStringBinaryHeapCallBacks;



CF_EXPORT CFTypeID
CFBinaryHeapGetTypeID (void);

CF_EXPORT CFBinaryHeapRef
CFBinaryHeapCreate (CFAllocatorRef allocator, CFIndex capacity,
  const CFBinaryHeapCallBacks *callBacks,
  const CFBinaryHeapCompareContext *compareContext);

CF_EXPORT CFBinaryHeapRef
CFBinaryHeapCreateCopy (CFAllocatorRef allocator, CFIndex capacity,
  CFBinaryHeapRef heap);

CF_EXPORT void
CFBinaryHeapAddValue (CFBinaryHeapRef heap, const void *value);

CF_EXPORT void
CFBinaryHeapApplyFunction (CFBinaryHeapRef heap,
  CFBinaryHeapApplierFunction applier, void *context);

CF_EXPORT Boolean
CFBinaryHeapContainsValue (CFBinaryHeapRef heap, const void *value);

CF_EXPORT CFIndex
CFBinaryHeapGetCount (CFBinaryHeapRef heap);

CF_EXPORT CFIndex
CFBinaryHeapGetCountOfValue (CFBinaryHeapRef heap, const void *value);

CF_EXPORT const void *
CFBinaryHeapGetMinimum (CFBinaryHeapRef heap);

CF_EXPORT Boolean
CFBinaryHeapGetMinimumIfPresent (CFBinaryHeapRef heap, const void **value);

CF_EXPORT void
CFBinaryHeapGetValues (CFBinaryHeapRef heap, const void **values);

CF_EXPORT void
CFBinaryHeapRemoveAllValues (CFBinaryHeapRef heap);

CF_EXPORT void
CFBinaryHeapRemoveMinimumValue (CFBinaryHeapRef heap);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFBINARYHEAP_H__ */

