/* CFURL.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Eric Wasylishen  <ewasylishen@gmail.com>
   Date: January, 2010
   
   This file is part of the GNUstep CoreBase Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __COREFOUNDATION_CFURL_H__
#define __COREFOUNDATION_CFURL_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFError.h>
#include <CoreFoundation/CFString.h>

CF_EXTERN_C_BEGIN

#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSURL;
typedef NSURL *CFURLRef;
#else
typedef const struct __CFURL *CFURLRef;
#endif

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
typedef CFOptionFlags CFURLBookmarkCreationOptions;
typedef CFOptionFlags CFURLBookmarkFileCreationOptions;
typedef CFOptionFlags CFURLBookmarkResolutionOptions;
#endif

/*
 * Constants
 */
typedef enum
{
  kCFURLPOSIXPathStyle =   0,
  kCFURLHFSPathStyle =     1,
  kCFURLWindowsPathStyle = 2
} CFURLPathStyle;

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
typedef enum
{
  kCFURLComponentScheme =            1,
  kCFURLComponentNetLocation =       2,
  kCFURLComponentPath =              3,
  kCFURLComponentResourceSpecifier = 4,
  kCFURLComponentUser =              5,
  kCFURLComponentPassword =          6,
  kCFURLComponentUserInfo =          7,
  kCFURLComponentHost =              8,
  kCFURLComponentPort =              9,
  kCFURLComponentParameterString =  10,
  kCFURLComponentQuery =            11,
  kCFURLComponentFragment =         12
} CFURLComponentType;
#endif

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
enum
{
  kCFURLBookmarkCreationPreferFileIDResolutionMask = (1<<8),
  kCFURLBookmarkCreationMinimalBookmarkMask =        (1<<9),
  kCFURLBookmarkCreationSuitableForBookmarkFile =   (1<<10)
};

enum
{
  kCFBookmarkResolutionWithoutUIMask =       (1<<8),
  kCFBookmarkResolutionWithoutMountingMask = (1<<9)
};

/*
 * Common File System Resource Keys
 */
CF_EXPORT const CFStringRef kCFURLNameKey;
CF_EXPORT const CFStringRef kCFURLLocalizedNameKey;
CF_EXPORT const CFStringRef kCFURLIsRegularFileKey;
CF_EXPORT const CFStringRef kCFURLIsDirectoryKey;
CF_EXPORT const CFStringRef kCFURLIsSymbolicLinkKey;
CF_EXPORT const CFStringRef kCFURLIsVolumeKey;
CF_EXPORT const CFStringRef kCFURLIsPackageKey;
CF_EXPORT const CFStringRef kCFURLIsSystemImmutableKey;
CF_EXPORT const CFStringRef kCFURLIsUserImmutableKey;
CF_EXPORT const CFStringRef kCFURLIsHiddenKey;
CF_EXPORT const CFStringRef kCFURLHasHiddenExtensionKey;
CF_EXPORT const CFStringRef kCFURLCreationDateKey;
CF_EXPORT const CFStringRef kCFURLContentAccessDateKey;
CF_EXPORT const CFStringRef kCFURLContentModificationDateKey;
CF_EXPORT const CFStringRef kCFURLAttributeModificationDateKey;
CF_EXPORT const CFStringRef kCFURLLinkCountKey;
CF_EXPORT const CFStringRef kCFURLParentDirectoryURLKey;
CF_EXPORT const CFStringRef kCFURLVolumeURLKey;
CF_EXPORT const CFStringRef kCFURLTypeIdentifierKey;
CF_EXPORT const CFStringRef kCFURLLocalizedTypeDescriptionKey;
CF_EXPORT const CFStringRef kCFURLLabelNumberKey;
CF_EXPORT const CFStringRef kCFURLLabelColorKey;
CF_EXPORT const CFStringRef kCFURLLocalizedLabelKey;
CF_EXPORT const CFStringRef kCFURLEffectiveIconKey;
CF_EXPORT const CFStringRef kCFURLCustomIconKey;
#endif
#if MAC_OS_X_VERSION_10_7 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLFileResourceIdentifierKey;
CF_EXPORT const CFStringRef kCFURLVolumeIdentifierKey;
CF_EXPORT const CFStringRef kCFURLPreferredIOBlockSizeKey;
CF_EXPORT const CFStringRef kCFURLIsReadableKey;
CF_EXPORT const CFStringRef kCFURLIsWritableKey;
CF_EXPORT const CFStringRef kCFURLIsExecutableKey;
CF_EXPORT const CFStringRef kCFURLFileSecurityKey;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeKey;
#endif

/*
 * File Resource Types
 */
#if MAC_OS_X_VERSION_10_7 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLFileResourceTypeBlockSpecial;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeCharacterSpecial;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeDirectory;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeNamedPipe;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeRegular;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeSocket;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeSymbolicLink;
CF_EXPORT const CFStringRef kCFURLFileResourceTypeUnknown;
#endif

/*
 * File Property Keys
 */
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLFileAllocatedSizeKey;
CF_EXPORT const CFStringRef kCFURLFileSizeKey;
CF_EXPORT const CFStringRef kCFURLIsAliasFileKey;
#endif
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLIsMountTriggerKey;
CF_EXPORT const CFStringRef kCFURLTotalFileAllocatedSizeKey;
CF_EXPORT const CFStringRef kCFURLTotalFileSizeKey;
#endif

/*
 * Volume Property Keys
 */
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLVolumeLocalizedFormatDescriptionKey;
CF_EXPORT const CFStringRef kCFURLVolumeTotalCapacityKey;
CF_EXPORT const CFStringRef kCFURLVolumeAvailableCapacityKey;
CF_EXPORT const CFStringRef kCFURLVolumeResourceCountKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsPersistentIDsKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsSymbolicLinksKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsHardLinksKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsJournalingKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsJournalingKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsSparseFilesKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsZeroRunsKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsCaseSensitiveNamesKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsCasePreservedNamesKey;
#endif
#if MAC_OS_X_VERSION_10_7 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLVolumeNameKey;
CF_EXPORT const CFStringRef kCFURLVolumeLocalizedNameKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsRootDirectoryDatesKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsVolumeSizesKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsRenamingKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsAdvisoryFileLockingKey;
CF_EXPORT const CFStringRef kCFURLVolumeSupportsExtendedSecurityKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsBrowsableKey;
CF_EXPORT const CFStringRef kCFURLVolumeMaximumFileSizeKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsEjectableKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsRemovableKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsInternalKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsAutomountedKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsLocalKey;
CF_EXPORT const CFStringRef kCFURLVolumeIsReadOnlyKey;
CF_EXPORT const CFStringRef kCFURLVolumeCreationDateKey;
CF_EXPORT const CFStringRef kCFURLVolumeURLForRemountingKey;
CF_EXPORT const CFStringRef kCFURLVolumeUUIDStringKey;
#endif

/*
 * CFError userInfo Dictionary Keys
 */
#if MAC_OS_X_VERSION_10_7 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFURLKeysOfUnsetValuesKey;
#endif

/*
 * Getting the CFURL Type ID
 */
CF_EXPORT CFTypeID
CFURLGetTypeID (void);

/*
 * Creating a CFURL Object
 */
CF_EXPORT CFURLRef
CFURLCopyAbsoluteURL (CFURLRef relativeURL);

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFURLRef
CFURLCreateAbsoluteURLWithBytes (CFAllocatorRef alloc,
  const UInt8 *relativeURLBytes, CFIndex length, CFStringEncoding encoding,
  CFURLRef baseURL, Boolean useCompatibilityMode);
#endif

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFURLRef
CFURLCreateByResolvingBookmarkData (CFAllocatorRef alloc, CFDataRef bookmark,
  CFURLBookmarkResolutionOptions options, CFURLRef relativeToURL,
  CFArrayRef resourcePropertiesToInclude, Boolean *isStale, CFErrorRef *error);
#endif

CF_EXPORT CFURLRef
CFURLCreateCopyAppendingPathComponent (CFAllocatorRef alloc, CFURLRef url,
  CFStringRef pathComponent, Boolean isDirectory);

CF_EXPORT CFURLRef
CFURLCreateCopyAppendingPathExtension (CFAllocatorRef alloc, CFURLRef url,
  CFStringRef extension);

CF_EXPORT CFURLRef
CFURLCreateCopyDeletingLastPathComponent (CFAllocatorRef alloc, CFURLRef url);

CF_EXPORT CFURLRef
CFURLCreateCopyDeletingPathExtension (CFAllocatorRef alloc, CFURLRef url);

#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFURLRef
CFURLCreateFilePathURL (CFAllocatorRef allocator, CFURLRef url,
  CFErrorRef *error);

CF_EXPORT CFURLRef
CFURLCreateFileReferenceURL (CFAllocatorRef allocator, CFURLRef url,
  CFErrorRef *error);
#endif

CF_EXPORT CFURLRef
CFURLCreateFromFileSystemRepresentation (CFAllocatorRef alloc,
  const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory);

CF_EXPORT CFURLRef
CFURLCreateFromFileSystemRepresentationRelativeToBase (CFAllocatorRef alloc,
  const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory, CFURLRef baseURL);

#if 0 /* No FSRef support */
CF_EXPORT CFURLRef
CFURLCreateFromFSRef (CFAllocatorRef alloc, const struct FSRef *fsRef);
#endif

CF_EXPORT CFURLRef
CFURLCreateWithBytes (CFAllocatorRef alloc, const UInt8 *bytes, CFIndex length,
  CFStringEncoding encoding, CFURLRef baseURL);

CF_EXPORT CFURLRef
CFURLCreateWithFileSystemPath (CFAllocatorRef allocator,
 CFStringRef fileSystemPath, CFURLPathStyle style, Boolean isDirectory);

CF_EXPORT CFURLRef
CFURLCreateWithFileSystemPathRelativeToBase (CFAllocatorRef alloc,
  CFStringRef filePath, CFURLPathStyle style, Boolean isDirectory,
  CFURLRef baseURL);

CF_EXPORT CFURLRef
CFURLCreateWithString (CFAllocatorRef allocator, CFStringRef string,
  CFURLRef baseURL);

/*
 * Accessing the Parts of a URL
 */
CF_EXPORT Boolean
CFURLCanBeDecomposed (CFURLRef url);

CFStringRef
CFURLCopyFileSystemPath (CFURLRef aURL, CFURLPathStyle style);

CF_EXPORT CFStringRef
CFURLCopyFragment (CFURLRef url, CFStringRef charactersToLeaveEscaped);

CF_EXPORT CFStringRef
CFURLCopyHostName (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyLastPathComponent (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyNetLocation (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyParameterString (CFURLRef url, CFStringRef charactersToLeaveEscaped);

CF_EXPORT CFStringRef
CFURLCopyPassword (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyPath (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyPathExtension (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyQueryString (CFURLRef url, CFStringRef charactersToLeaveEscaped);

CF_EXPORT CFStringRef
CFURLCopyResourceSpecifier (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyScheme (CFURLRef url);

CF_EXPORT CFStringRef
CFURLCopyStrictPath (CFURLRef url, Boolean *isAbsolute);

CF_EXPORT CFStringRef
CFURLCopyUserName (CFURLRef url);

CF_EXPORT SInt32
CFURLGetPortNumber (CFURLRef url);

CF_EXPORT Boolean
CFURLHasDirectoryPath (CFURLRef url);

/*
 * Converting URLs to Other Representations
 */
CF_EXPORT CFDataRef
CFURLCreateData (CFAllocatorRef alloc, CFURLRef url, CFStringEncoding encoding,
  Boolean escapeWhiteSpace);

CF_EXPORT CFStringRef
CFURLCreateStringByAddingPercentEscapes (CFAllocatorRef alloc,
  CFStringRef origString, CFStringRef charactersToLeaveUnescaped,
  CFStringRef legalURLCharactersToBeEscaped, CFStringEncoding encoding);

CF_EXPORT CFStringRef
CFURLCreateStringByReplacingPercentEscapes (CFAllocatorRef alloc,
  CFStringRef origString, CFStringRef charactersToLeaveEscaped);

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFStringRef
CFURLCreateStringByReplacingPercentEscapesUsingEncoding (CFAllocatorRef alloc,
  CFStringRef origString, CFStringRef charactersToLeaveEscaped,
  CFStringEncoding encoding);
#endif

CF_EXPORT Boolean
CFURLGetFileSystemRepresentation (CFURLRef url, Boolean resolveAgainstBase,
  UInt8 *buffer, CFIndex bufLen);

#if 0 /* FSRef unsupported */
CF_EXPORT Boolean
CFURLGetFSRef (CFURLRef url, struct FSRef *fsRef);
#endif

CF_EXPORT CFStringRef
CFURLGetString (CFURLRef url);

/*
 * Getting URL Properties
 */
CF_EXPORT CFURLRef
CFURLGetBaseURL (CFURLRef url);

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFIndex
CFURLGetBytes (CFURLRef url, UInt8 *buffer, CFIndex bufLen);

CF_EXPORT CFRange
CFURLGetByteRangeForComponent (CFURLRef url, CFURLComponentType comp,
  CFRange *rangeIncludingSeparators);

CF_EXPORT Boolean
CFURLResourceIsReachable (CFURLRef url, CFErrorRef *error);
#endif

/*
 * Getting and Setting File System Resource Properties
 */
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT void
CFURLClearResourcePropertyCache (CFURLRef url);

CF_EXPORT void
CFURLClearResourcePropertyCacheForKey (CFURLRef url, CFStringRef key);

CF_EXPORT CFDictionaryRef
CFURLCopyResourcePropertiesForKeys (CFURLRef url, CFArrayRef keys,
  CFErrorRef *error);

CF_EXPORT Boolean
CFURLCopyResourcePropertyForKey (CFURLRef url, CFStringRef key,
  void *propertyValueTypeRefPtr, CFErrorRef *error);

CF_EXPORT CFDictionaryRef
CFURLCreateResourcePropertiesForKeysFromBookmarkData (CFAllocatorRef allocator,
  CFArrayRef resourcePropertiesToReturn, CFDataRef bookmark);

CF_EXPORT CFTypeRef
CFURLCreateResourcePropertyForKeyFromBookmarkData (CFAllocatorRef allocator,
  CFStringRef resourcePropertyKey, CFDataRef bookmark);

CF_EXPORT Boolean
CFURLSetResourcePropertiesForKeys (CFURLRef url,
  CFDictionaryRef keyedPropertyValues, CFErrorRef *error);

CF_EXPORT Boolean
CFURLSetResourcePropertyForKey (CFURLRef url, CFStringRef key,
  CFTypeRef propertValue, CFErrorRef *error);

CF_EXPORT void
CFURLSetTemporaryResourcePropertyForKey (CFURLRef url, CFStringRef key,
  CFTypeRef propertyValue);

/*
 * Working with Bookmark Data
 */
CF_EXPORT CFDataRef
CFURLCreateBookmarkData (CFAllocatorRef alloc, CFURLRef url,
  CFURLBookmarkCreationOptions options, CFArrayRef resourcePropertiesToInclude,
  CFURLRef relativeToURL, CFErrorRef *error);

CF_EXPORT CFDataRef
CFURLCreateBookmarkDataFromAliasRecord (CFAllocatorRef alloc,
  CFDataRef aliasRecordDataRef);

CF_EXPORT CFDataRef
CFURLCreateBookmarkDataFromFile (CFAllocatorRef allocator, CFURLRef fileURL,
  CFErrorRef *errorRef);

CF_EXPORT Boolean
CFURLWriteBookmarkDataToFile (CFDataRef bookmarkRef, CFURLRef fileURL,
  CFURLBookmarkFileCreationOptions options, CFErrorRef *errorRef);
#endif

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFURL_H__ */

