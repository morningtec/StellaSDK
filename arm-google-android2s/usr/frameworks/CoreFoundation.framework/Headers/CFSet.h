/* CFSet.h
   
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
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/ 

#ifndef __COREFOUNDATION_CFSET_H__
#define __COREFOUNDATION_CFSET_H__ 1

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSSet;
@class NSMutableSet;
typedef NSSet* CFSetRef;
typedef NSMutableSet* CFMutableSetRef;
#else
typedef const struct __CFSet *CFSetRef;
typedef struct __CFSet *CFMutableSetRef;
#endif

typedef void (*CFSetApplierFunction) (const void *value, void *context);

typedef CFStringRef (*CFSetCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFSetEqualCallBack) (const void *value1,
  const void *value2);
typedef CFHashCode (*CFSetHashCallBack) (const void *value);
typedef void (*CFSetReleaseCallBack) (CFAllocatorRef alloc, const void *value);
typedef const void *(*CFSetRetainCallBack) (CFAllocatorRef alloc,
  const void *value);

typedef struct CFSetCallBacks CFSetCallBacks;
struct CFSetCallBacks
{
  CFIndex version;
  CFSetRetainCallBack retain;
  CFSetReleaseCallBack release;
  CFSetCopyDescriptionCallBack copyDescription;
  CFSetEqualCallBack equal;
  CFSetHashCallBack hash;
};

CF_EXPORT const CFSetCallBacks kCFCopyStringSetCallBacks;
CF_EXPORT const CFSetCallBacks kCFTypeSetCallBacks;



/*
 * Creating a set
 */
CFSetRef
CFSetCreate (CFAllocatorRef alloc, const void **values, CFIndex numValues,
  const CFSetCallBacks *callBacks);

CFSetRef
CFSetCreateCopy (CFAllocatorRef alloc, CFSetRef set);

/*
 * Examining a dictionary
 */
Boolean
CFSetContainsValue (CFSetRef set, const void *value);

CFIndex
CFSetGetCount (CFSetRef set);

CFIndex
CFSetGetCountOfValue (CFSetRef set, const void *value);

void
CFSetGetValues (CFSetRef set, const void **values);

const void *
CFSetGetValue (CFSetRef set, const void *value);

Boolean
CFSetGetValueIfPresent (CFSetRef set, const void *candidate,
  const void **value);

/*
 * Applying a funcation to a dictionary
 */
void
CFSetApplyFunction (CFSetRef set, CFSetApplierFunction applier, void *context);

/*
 * Getting the CFSet type ID
 */
CFTypeID
CFSetGetTypeID (void);



/*
 * Creating a Mutable Dictionary
 */
CFMutableSetRef
CFSetCreateMutable (CFAllocatorRef alloc, CFIndex capacity,
  const CFSetCallBacks *callBacks);

CFMutableSetRef
CFSetCreateMutableCopy (CFAllocatorRef alloc, CFIndex capacity, CFSetRef set);

/*
 * Modifying a Dictionary
 */
void
CFSetAddValue (CFMutableSetRef set, const void *value);

void
CFSetRemoveAllValues (CFMutableSetRef set);

void
CFSetRemoveValue (CFMutableSetRef set, const void *value);

void
CFSetReplaceValue (CFMutableSetRef set, const void *value);

void
CFSetSetValue (CFMutableSetRef set, const void *value);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFSET_H__ */

