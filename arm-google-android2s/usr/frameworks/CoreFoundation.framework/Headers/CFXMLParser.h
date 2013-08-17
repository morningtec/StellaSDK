/* CFXMLParser.h
   
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

#ifndef __CFCOREFOUNDATION_CFXMLPARSER_H__
#define __CFCOREFOUNDATION_CFXMLPARSER_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFTree.h>
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFXMLNode.h>

CF_EXTERN_C_BEGIN

/*
 * CFXMLParser
 */
typedef struct __CFXMLParser *CFXMLParserRef;

typedef enum
{
  kCFXMLStatusParseNotBegun =                -2,
  kCFXMLStatusParseInProgress =              -1,
  kCFXMLStatusParseSuccessful =               0,
  kCFXMLErrorUnexpectedEOF =                  1,
  kCFXMLErrorUnknownEncoding =                2,
  kCFXMLErrorEncodingConversionFailure =      3,
  kCFXMLErrorMalformedProcessingInstruction = 4,
  kCFXMLErrorMalformedDTD =                   5,
  kCFXMLErrorMalformedName =                  6,
  kCFXMLErrorMalformedCDSect =                7,
  kCFXMLErrorMalformedCloseTag =              8,
  kCFXMLErrorMalformedStartTag =              9,
  kCFXMLErrorMalformedDocument =             10,
  kCFXMLErrorElementlessDocument =           11,
  kCFXMLErrorMalformedComment =              12,
  kCFXMLErrorMalformedCharacterReference =   13,
  kCFXMLErrorMalformedParsedCharacterData =  14,
  kCFXMLErrorNoData =                        15
} CFXMLParserStatusCode;

typedef enum
{
  kCFXMLParserValidateDocument =        (1<<0),
  kCFXMLParserSkipMetaData =            (1<<1),
  kCFXMLParserReplacePhysicalEntities = (1<<2),
  kCFXMLParserSkipWhitespace =          (1<<3),
  kCFXMLParserResolveExternalEntities = (1<<4),
  kCFXMLParserAddImpliedAttributes =    (1<<5),
  kCFXMLParserAllOptions =          0x00FFFFFF,
  kCFXMLParserNoOptions =                    0
} CFXMLParserOptions;

typedef void *(*CFXMLParserCreateXMLStructureCallBack) (CFXMLParserRef parser,
  CFXMLNodeRef nodeDesc, void *info);
typedef void (*CFXMLParserAddChildCallBack) (CFXMLParserRef parser,
  void *parent, void *child, void *info);
typedef void (*CFXMLParserEndXMLStructureCallBack) (CFXMLParserRef parser,
  void *xmlType, void *info);
typedef CFDataRef (*CFXMLParserResolveExternalEntityCallBack) \
  (CFXMLParserRef parser, CFXMLExternalID *extID, void *info);
typedef Boolean (*CFXMLParserHandleErrorCallBack) (CFXMLParserRef parser,
  CFXMLParserStatusCode error, void *info);

typedef CFStringRef (*CFXMLParserCopyDescriptionCallBack) (const void *info);
typedef void (*CFXMLParserReleaseCallBack) (const void *info);
typedef const void *(*CFXMLParserRetainCallBack) (const void *info);

typedef struct CFXMLParserCallBacks CFXMLParserCallBacks;
struct CFXMLParserCallBacks
{
  CFIndex version;
  CFXMLParserCreateXMLStructureCallBack createXMLStructure;
  CFXMLParserAddChildCallBack addChild;
  CFXMLParserEndXMLStructureCallBack endXMLStructure;
  CFXMLParserResolveExternalEntityCallBack resolveExternalEntity;
  CFXMLParserHandleErrorCallBack handleError;
};

typedef struct CFXMLParserContext CFXMLParserContext;
struct CFXMLParserContext
{
  CFIndex version;
  void *info;
  CFXMLParserRetainCallBack retain;
  CFXMLParserReleaseCallBack release;
  CFXMLParserCopyDescriptionCallBack copyDescription;
};



CF_EXPORT CFTypeID
CFXMLParserGetTypeID (void);

CF_EXPORT void
CFXMLParserAbort (CFXMLParserRef parser, CFXMLParserStatusCode errorCode,
  CFStringRef errorDescription);

CF_EXPORT CFStringRef
CFXMLParserCopyErrorDescription (CFXMLParserRef parser);

CF_EXPORT CFXMLParserRef
CFXMLParserCreate (CFAllocatorRef allocator, CFDataRef xmlData,
  CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes,
  CFXMLParserCallBacks *callBacks, CFXMLParserContext *context);

CF_EXPORT CFXMLParserRef
CFXMLParserCreateWithDataFromURL (CFAllocatorRef allocator,
  CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes,
  CFXMLParserCallBacks *callBacks, CFXMLParserContext *context);

CF_EXPORT void
CFXMLParserGetCallBacks (CFXMLParserRef parser,
  CFXMLParserCallBacks *callBacks);

CF_EXPORT void
CFXMLParserGetContext (CFXMLParserRef parser, CFXMLParserContext *context);

CF_EXPORT void *
CFXMLParserGetDocument (CFXMLParserRef parser);

CF_EXPORT CFIndex
CFXMLParserGetLineNumber (CFXMLParserRef parser);

CF_EXPORT CFIndex
CFXMLParserGetLocation (CFXMLParserRef parser);

CF_EXPORT CFURLRef
CFXMLParserGetSourceURL (CFXMLParserRef parser);

CF_EXPORT CFXMLParserStatusCode
CFXMLParserGetStatusCode (CFXMLParserRef parser);

CF_EXPORT Boolean
CFXMLParserParse (CFXMLParserRef parser);



/*
 * CFXMLTree
 */
CF_EXPORT CFXMLTreeRef
CFXMLTreeCreateFromData (CFAllocatorRef allocator, CFDataRef xmlData,
  CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes);

CF_EXPORT CFXMLTreeRef
CFXMLTreeCreateWithDataFromURL (CFAllocatorRef allocator, CFURLRef dataSource,
  CFOptionFlags parseOptions, CFIndex versionOfNodes);

CF_EXPORT CFDataRef
CFXMLTreeCreateXMLData (CFAllocatorRef allocator, CFXMLTreeRef xmlTree);

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFXMLTreeErrorDescription;
CF_EXPORT const CFStringRef kCFXMLTreeErrorLineNumber;
CF_EXPORT const CFStringRef kCFXMLTreeErrorLocation;
CF_EXPORT const CFStringRef kCFXMLTreeErrorStatusCode;

CF_EXPORT CFStringRef
CFXMLCreateStringByEscapingEntities(CFAllocatorRef allocator,
  CFStringRef string, CFDictionaryRef entitiesDictionary);

CF_EXPORT CFStringRef
CFXMLCreateStringByUnescapingEntities(CFAllocatorRef allocator,
  CFStringRef string, CFDictionaryRef entitiesDictionary);

CF_EXPORT CFXMLTreeRef
CFXMLTreeCreateFromDataWithError (CFAllocatorRef allocator, CFDataRef xmlData,
  CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes,
  CFDictionaryRef *errorDict);
#endif /* MAC_OS_X_VERSION_10_3 */

CF_EXTERN_C_END

#endif /* __CFCOREFOUNDATION_CFXMLPARSER_H__ */

