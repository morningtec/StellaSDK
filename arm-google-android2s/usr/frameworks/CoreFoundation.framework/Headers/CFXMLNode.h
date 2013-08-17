/* CFXMLNode.h
   
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

#ifndef __CFCOREFOUNDATION_CFXMLNODE_H__
#define __CFCOREFOUNDATION_CFXMLNODE_H__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFTree.h>
#include <CoreFoundation/CFURL.h>

CF_EXTERN_C_BEGIN

typedef const struct __CFXMLNode *CFXMLNodeRef;

typedef enum
{
  kCFXMLEntityTypeParameter =      0,
  kCFXMLEntityTypeParsedInternal = 1,
  kCFXMLEntityTypeParsedExternal = 2,
  kCFXMLEntityTypeUnparsed =       3,
  kCFXMLEntityTypeCharacter =      4
} CFXMLEntityTypeCode;

enum
{
  kCFXMLNodeCurrentVersion = 1
};

typedef enum
{
  kCFXMLNodeTypeDocument =                  1,
  kCFXMLNodeTypeElement =                   2,
  kCFXMLNodeTypeAttribute =                 3,
  kCFXMLNodeTypeProcessingInstruction =     4,
  kCFXMLNodeTypeComment =                   5,
  kCFXMLNodeTypeText =                      6,
  kCFXMLNodeTypeCDATASection =              7,
  kCFXMLNodeTypeDocumentFragment =          8,
  kCFXMLNodeTypeEntity =                    9,
  kCFXMLNodeTypeEntityReference =          10,
  kCFXMLNodeTypeDocumentType =             11,
  kCFXMLNodeTypeWhitespace =               12,
  kCFXMLNodeTypeNotation =                 13,
  kCFXMLNodeTypeElementTypeDeclaration =   14,
  kCFXMLNodeTypeAttributeListDeclaration = 15
} CFXMLNodeTypeCode;

typedef struct CFXMLExternalID CFXMLExternalID;
struct CFXMLExternalID
{
  CFURLRef systemID;
  CFStringRef publicID;
};

typedef struct CFXMLAttributeDeclarationInfo CFXMLAttributeDeclarationInfo;
struct CFXMLAttributeDeclarationInfo
{
  CFStringRef attributeName;
  CFStringRef typeString;
  CFStringRef defaultString;
};

typedef struct CFXMLAttributeListDeclarationInfo  CFXMLAttributeListDeclarationInfo;
struct CFXMLAttributeListDeclarationInfo
{
  CFIndex numberOfAttributes;
  CFXMLAttributeDeclarationInfo *attributes;
};

typedef struct CFXMLDocumentInfo CFXMLDocumentInfo;
struct CFXMLDocumentInfo
{
  CFURLRef sourceURL;
  CFStringEncoding encoding;
};

typedef struct CFXMLDocumentTypeInfo CFXMLDocumentTypeInfo;
struct CFXMLDocumentTypeInfo
{
  CFXMLExternalID externalID;
};

typedef struct CFXMLElementInfo CFXMLElementInfo;
struct CFXMLElementInfo
{
  CFDictionaryRef attributes;
  CFArrayRef attributeOrder;
  Boolean isEmpty;
};

typedef struct CFXMLElementTypeDeclarationInfo CFXMLElementTypeDeclarationInfo;
struct CFXMLElementTypeDeclarationInfo
{
  CFStringRef contentDescription;
};

typedef struct CFXMLEntityInfo CFXMLEntityInfo;
struct CFXMLEntityInfo
{
  CFXMLEntityTypeCode entityType;
  CFStringRef replacementText;
  CFXMLExternalID entityID;
  CFStringRef notationName;
};

typedef struct CFXMLEntityReferenceInfo CFXMLEntityReferenceInfo;
struct CFXMLEntityReferenceInfo
{
  CFXMLEntityTypeCode entityType;
};

typedef struct CFXMLNotationInfo CFXMLNotationInfo;
struct CFXMLNotationInfo
{
  CFXMLExternalID externalID;
};

typedef struct CFXMLProcessingInstructionInfo CFXMLProcessingInstructionInfo;
struct CFXMLProcessingInstructionInfo
{
  CFStringRef dataString;
};



CF_EXPORT CFTypeID
CFXMLNodeGetTypeID (void);

CF_EXPORT CFXMLNodeRef
CFXMLNodeCreate (CFAllocatorRef alloc, CFXMLNodeTypeCode xmlType,
  CFStringRef dataString, const void *additionalInfoPtr, CFIndex version);

CF_EXPORT CFXMLNodeRef
CFXMLNodeCreateCopy (CFAllocatorRef alloc, CFXMLNodeRef origNode);

CF_EXPORT const void *
CFXMLNodeGetInfoPtr (CFXMLNodeRef node);

CF_EXPORT CFStringRef
CFXMLNodeGetString (CFXMLNodeRef node);

CF_EXPORT CFXMLNodeTypeCode
CFXMLNodeGetTypeCode (CFXMLNodeRef node);

CF_EXPORT CFIndex
CFXMLNodeGetVersion (CFXMLNodeRef node);



/*
 * CFXMLTree
 */
typedef CFTreeRef CFXMLTreeRef;

CF_EXPORT CFXMLTreeRef
CFXMLTreeCreateWithNode (CFAllocatorRef allocator, CFXMLNodeRef node);

CF_EXPORT CFXMLNodeRef
CFXMLTreeGetNode (CFXMLTreeRef xmlTree);

CF_EXTERN_C_END

#endif /* __CFCOREFOUNDATION_CFXMLNODE_H__ */

