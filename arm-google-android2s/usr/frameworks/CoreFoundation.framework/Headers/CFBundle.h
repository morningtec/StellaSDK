/* CFBundle.h
   
   Copyright (C) 2011 Free Software Foundation, Inc.
   
   Written by: David Chisnall
   Date: April, 2011
   
   This file is part of the GNUstep CoreBase Library.
   
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

#ifndef __COREFOUNDATION_CFBUNDLE__
#define __COREFOUNDATION_CFBUNDLE__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFURL.h>

CF_EXTERN_C_BEGIN

typedef const struct __CFBundle *CFBundleRef;

CF_EXPORT const CFStringRef kCFBundleNameKey;
CF_EXPORT const CFStringRef kCFBundleVersionKey;
CF_EXPORT const CFStringRef kCFBundleIdentifierKey;
CF_EXPORT const CFStringRef kCFBundleInfoDictionaryVersionKey;
CF_EXPORT const CFStringRef kCFBundleLocalizationsKey;
CF_EXPORT const CFStringRef kCFBundleExecutableKey;
CF_EXPORT const CFStringRef kCFBundleDevelopmentRegionKey;

CFBundleRef CFBundleCreate(CFAllocatorRef allocator, CFURLRef bundleURL);

void* CFBundleGetFunctionPointerForName(CFBundleRef bundle,
                                        CFStringRef functionName);

void* CFBundleGetDataPointerForName(CFBundleRef bundle,
                                    CFStringRef functionName);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFBUNDLE__ */

