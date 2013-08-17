/* CFTree.h
   
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

#ifndef __CFCOREFOUNDATION_CFTREE_H__
#define __CFCOREFOUNDATION_CFTREE_H__

#include <CoreFoundation/CFBase.h>

CF_EXTERN_C_BEGIN

typedef struct __CFTree *CFTreeRef;

typedef void (*CFTreeApplierFunction) (const void *value, void *context);

typedef const void *(*CFTreeRetainCallBack) (const void *info);
typedef void (*CFTreeReleaseCallBack) (const void *info);
typedef CFStringRef (*CFTreeCopyDescriptionCallBack) (const void *info);

typedef struct _CFTreeContext CFTreeContext;
struct _CFTreeContext
{
  CFIndex version;
  void *info;
  CFTreeRetainCallBack retain;
  CFTreeReleaseCallBack release;
  CFTreeCopyDescriptionCallBack copyDescription;
};

/*
 * Creating Trees
 */
CF_EXPORT CFTreeRef
CFTreeCreate (CFAllocatorRef allocator, const CFTreeContext *context);

/*
 * Modifying a Tree
 */
CF_EXPORT void
CFTreeAppendChild (CFTreeRef tree, CFTreeRef newChild);

CF_EXPORT void
CFTreeInsertSibling (CFTreeRef tree, CFTreeRef newSibling);

CF_EXPORT void
CFTreeRemoveAllChildren (CFTreeRef tree);

CF_EXPORT void
CFTreePrependChild (CFTreeRef tree, CFTreeRef newChild);

CF_EXPORT void
CFTreeRemove (CFTreeRef tree);

CF_EXPORT void
CFTreeSetContext (CFTreeRef tree, const CFTreeContext *context);

/*
 * Sorting a Tree
 */
CF_EXPORT void
CFTreeSortChildren (CFTreeRef tree, CFComparatorFunction comp, void *context);

/*
 * Examining a Tree
 */
CF_EXPORT CFTreeRef
CFTreeFindRoot (CFTreeRef tree);

CF_EXPORT CFTreeRef
CFTreeGetChildAtIndex (CFTreeRef tree, CFIndex idx);

CF_EXPORT CFIndex
CFTreeGetChildCount (CFTreeRef tree);

CF_EXPORT void
CFTreeGetChildren (CFTreeRef tree, CFTreeRef *children);

CF_EXPORT void
CFTreeGetContext (CFTreeRef tree, CFTreeContext *context);

CF_EXPORT CFTreeRef
CFTreeGetFirstChild (CFTreeRef tree);

CF_EXPORT CFTreeRef
CFTreeGetNextSibling (CFTreeRef tree);

CF_EXPORT CFTreeRef
CFTreeGetParent (CFTreeRef tree);

/*
 * Performing an Operation on Tree Elements
 */
CF_EXPORT void
CFTreeApplyFunctionToChildren (CFTreeRef tree, CFTreeApplierFunction applier,
  void *context);

/*
 * Getting the Tree Type ID
 */
CF_EXPORT CFTypeID
CFTreeGetTypeID (void);

CF_EXTERN_C_END

#endif /* __CFCOREFOUNDATION_CFTREE_H__ */

