/* CFDictionary.h
   
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

#ifndef __COREFOUNDATION_CFDICTIONARY_H__
#define __COREFOUNDATION_CFDICTIONARY_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSDictionary;
@class NSMutableDictionary;
typedef NSDictionary* CFDictionaryRef;
typedef NSMutableDictionary* CFMutableDictionaryRef;
#else
typedef const struct __CFDictionary * CFDictionaryRef;
typedef struct __CFDictionary * CFMutableDictionaryRef;
#endif

typedef void (*CFDictionaryApplierFunction) (const void *key,
  const void *value, void *context);

typedef CFStringRef (*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean  (*CFDictionaryEqualCallBack) (const void *value1,
  const void *value2);
typedef CFHashCode    (*CFDictionaryHashCallBack) (const void *value);
typedef void (*CFDictionaryReleaseCallBack) (CFAllocatorRef allocator,
  const void *value);
typedef const void *(*CFDictionaryRetainCallBack) (CFAllocatorRef allocator,
  const void *value);

typedef struct _CFDictionaryKeyCallBacks CFDictionaryKeyCallBacks;
struct _CFDictionaryKeyCallBacks
{
  CFIndex version;
  CFDictionaryRetainCallBack retain;
  CFDictionaryReleaseCallBack release;
  CFDictionaryCopyDescriptionCallBack copyDescription;
  CFDictionaryEqualCallBack equal;
  CFDictionaryHashCallBack hash;
};

typedef struct _CFDictionaryValueCallBacks CFDictionaryValueCallBacks;
struct _CFDictionaryValueCallBacks
{
   CFIndex version;
   CFDictionaryRetainCallBack retain;
   CFDictionaryReleaseCallBack release;
   CFDictionaryCopyDescriptionCallBack copyDescription;
   CFDictionaryEqualCallBack equal;
};

CF_EXPORT const CFDictionaryKeyCallBacks kCFCopyStringDictionaryKeyCallBacks;
CF_EXPORT const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;
CF_EXPORT const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;



/*
 * Creating a dictionary
 */
CFDictionaryRef
CFDictionaryCreate (CFAllocatorRef allocator, const void **keys,
  const void **values, CFIndex numValues,
  const CFDictionaryKeyCallBacks *keyCallBacks,
  const CFDictionaryValueCallBacks *valueCallBacks);

CFDictionaryRef
CFDictionaryCreateCopy (CFAllocatorRef allocator, CFDictionaryRef theDict);

/*
 * Examining a dictionary
 */
Boolean
CFDictionaryContainsKey (CFDictionaryRef theDict, const void *key);

Boolean
CFDictionaryContainsValue (CFDictionaryRef theDict, const void *value);

CFIndex
CFDictionaryGetCount (CFDictionaryRef theDict);

CFIndex
CFDictionaryGetCountOfKey (CFDictionaryRef theDict, const void *key);

CFIndex
CFDictionaryGetCountOfValue (CFDictionaryRef theDict, const void *value);

void
CFDictionaryGetKeysAndValues (CFDictionaryRef theDict, const void **keys,
  const void **values);

const void *
CFDictionaryGetValue (CFDictionaryRef theDict, const void *key);

Boolean
CFDictionaryGetValueIfPresent (CFDictionaryRef theDict, const void *key,
  const void **value);

/*
 * Applying a funcation to a dictionary
 */
void
CFDictionaryApplyFunction (CFDictionaryRef theDict,
  CFDictionaryApplierFunction applier, void *context);

/*
 * Getting the CFDictionary type ID
 */
CFTypeID
CFDictionaryGetTypeID (void);

/*
 * Creating a Mutable Dictionary
 */
CFMutableDictionaryRef
CFDictionaryCreateMutable (CFAllocatorRef allocator, CFIndex capacity,
  const CFDictionaryKeyCallBacks *keyCallBacks,
  const CFDictionaryValueCallBacks *valueCallBacks);

CFMutableDictionaryRef
CFDictionaryCreateMutableCopy (CFAllocatorRef allocator, CFIndex capacity,
  CFDictionaryRef theDict);

/*
 * Modifying a Dictionary
 */
void
CFDictionaryAddValue (CFMutableDictionaryRef theDict, const void *key,
  const void *value);

void
CFDictionaryRemoveAllValues (CFMutableDictionaryRef theDict);

void
CFDictionaryRemoveValue (CFMutableDictionaryRef theDict, const void *key);

void
CFDictionaryReplaceValue (CFMutableDictionaryRef theDict, const void *key,
  const void *value);

void
CFDictionarySetValue (CFMutableDictionaryRef theDict, const void *key,
  const void *value);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFDICTIONARY_H__ */

