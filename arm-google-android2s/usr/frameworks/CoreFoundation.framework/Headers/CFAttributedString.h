/* CFAttributedString.h
   
   Copyright (C) 2012 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: April, 2012
   
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

#ifndef __COREFOUNDATION_CFATTRIBUTEDSTIRNG_H__
#define __COREFOUNDATION_CFATTRIBUTEDSTIRNG_H__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDictionary.h>

CF_EXTERN_C_BEGIN

typedef const struct __CFAttributedString * CFAttributedStringRef;
typedef struct __CFAttributedString * CFMutableAttributedStringRef;

/*
 * Getting Attributed String Properties
 */
CF_EXPORT CFTypeID
CFAttributedStringGetTypeID (void);

/*
 * Creating a CFAttributedString
 */
CF_EXPORT CFAttributedStringRef
CFAttributedStringCreate (CFAllocatorRef alloc, CFStringRef str,
  CFDictionaryRef attribs);

CF_EXPORT CFAttributedStringRef
CFAttributedStringCreateCopy (CFAllocatorRef alloc, CFAttributedStringRef str);

CF_EXPORT CFAttributedStringRef
CFAttributedStringCreateWithSubstring (CFAllocatorRef alloc,
  CFAttributedStringRef str, CFRange range);

CF_EXPORT CFIndex
CFAttributedStringGetLength (CFAttributedStringRef str);

CF_EXPORT CFStringRef
CFAttributedStringGetString (CFAttributedStringRef str);

/*
 * Accessing Attributes
 */
CF_EXPORT CFTypeRef
CFAttributedStringGetAttribute (CFAttributedStringRef str, CFIndex loc,
  CFStringRef attrName, CFRange *effRange);

CF_EXPORT CFDictionaryRef
CFAttributedStringGetAttributes (CFAttributedStringRef str, CFIndex loc,
  CFRange *effRange);

CF_EXPORT CFTypeRef
CFAttributedStringGetAttributeAndLongestEffectiveRange (
  CFAttributedStringRef str, CFIndex loc, CFStringRef attrName,
  CFRange inRange, CFRange *longestEffRange);

CF_EXPORT CFDictionaryRef
CFAttributedStringGetAttributesAndLongestEffectiveRange (
  CFAttributedStringRef str, CFIndex loc, CFRange inRange,
  CFRange *longestEffRange);

/*
 * Creating a CFMutableAttributedString
 */
CF_EXPORT CFMutableAttributedStringRef
CFAttributedStringCreateMutable (CFAllocatorRef alloc, CFIndex maxLength);

CF_EXPORT CFMutableAttributedStringRef
CFAttributedStringCreateMutableCopy (CFAllocatorRef alloc, CFIndex maxLength,
  CFAttributedStringRef str);

/*
 * Modifying a CFMutableAttributedString
 */
CF_EXPORT void
CFAttributedStringBeginEditing (CFMutableAttributedStringRef str);

CF_EXPORT void
CFAttributedStringEndEditing (CFMutableAttributedStringRef str);

CF_EXPORT CFMutableStringRef
CFAttributedStringGetMutableString (CFMutableAttributedStringRef str);

CF_EXPORT void
CFAttributedStringRemoveAttribute (CFMutableAttributedStringRef str,
  CFRange range, CFStringRef attrName);

CF_EXPORT void
CFAttributedStringReplaceString (CFMutableAttributedStringRef str,
  CFRange range, CFStringRef repl);

CF_EXPORT void
CFAttributedStringReplaceAttributedString (CFMutableAttributedStringRef str,
  CFRange range, CFAttributedStringRef repl);

CF_EXPORT void
CFAttributedStringSetAttribute (CFMutableAttributedStringRef str,
  CFRange range, CFStringRef attrName, CFTypeRef value);

CF_EXPORT void
CFAttributedStringSetAttributes (CFMutableAttributedStringRef str,
  CFRange range, CFDictionaryRef repl, Boolean clearOtherAttribs);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFATTRIBUTEDSTIRNG_H__ */

