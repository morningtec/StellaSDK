/* CFBase.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
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


#ifndef __COREFOUNDATION_CFBASE_H__
#define __COREFOUNDATION_CFBASE_H__

#include <stddef.h> /* for intptr_t and uintptr_t */

/* CoreFoundation defineds __LITTLE_ENDIAN__ or __BIG_ENDIAN__ so we'll
 * do the same here for compatibility.
 */
#if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
# if defined(__GNUC__)
#  if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#   define __LITTLE_ENDIAN__ 1
#  elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#   define __BIG_ENDIAN__ 1
#  else
#   error Cannot establish platform endianness!
#  endif
# elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
#  define __LITTLE_ENDIAN__ 1
# else
#  error Cannot establish platform endianness!
# endif
#endif

/* FIXME: These macros are defined here to work around an issue with including
 * GNUstepBase/GSVersionMacros.h when compiling with clang or on Windows.
 */
#ifndef MAC_OS_X_VERSION_10_0
#define MAC_OS_X_VERSION_10_0 100000
#define MAC_OS_X_VERSION_10_1 100100
#define MAC_OS_X_VERSION_10_2 100200
#define MAC_OS_X_VERSION_10_3 100300
#define MAC_OS_X_VERSION_10_4 100400
#define MAC_OS_X_VERSION_10_5 100500
#define MAC_OS_X_VERSION_10_6 100600
#define MAC_OS_X_VERSION_10_7 100700
#endif /* MAC_OS_X_VERSION_10_0 */

#define MAC_OS_X_VERSION_MAX_ALLOWED 100700

/*
 * CoreFoundation types
 */
#if defined(_MSC_VER)
#include <intsafe.h>
typedef UINT8  Boolean;
typedef UINT8  UInt8;
typedef INT8   SInt8;
typedef UINT16 UInt16;
typedef INT16  SInt16;
typedef UINT32 UInt32;
typedef INT32  SInt32;
typedef UINT64 UInt64;
typedef INT64  SInt64;
#else
#include <stdint.h>
typedef uint8_t  Boolean;
typedef uint8_t  UInt8;
typedef int8_t   SInt8;
typedef uint16_t UInt16;
typedef int16_t  SInt16;
typedef uint32_t UInt32;
typedef int32_t  SInt32;
typedef uint64_t UInt64;
typedef int64_t  SInt64;
#endif
typedef SInt32   OSStatus;

typedef float            Float32;
typedef double           Float64;
typedef UInt16           UniChar;
typedef UInt8*           StringPtr;
typedef const StringPtr* ConstStringPtr;
typedef UInt8            Str255[256];
typedef const Str255*    ConstStr255Param;
typedef SInt16           OSErr;
typedef SInt16           RegionCode;
typedef SInt16           LangCode;
typedef SInt16           ScriptCode;
typedef UInt32           FourCharCode;
#ifndef OSTYPE_DECLARED
typedef FourCharCode     OSType;
#define OSTYPE_DECLARED
#endif
typedef UInt8            Byte;
typedef SInt8            SignedByte;

#ifndef UTF32Char
typedef UInt32 UTF32Char;
#endif
typedef UInt16 UTF16Char;
typedef UInt8  UTF8Char;

#if !defined(CF_EXTERN_C_BEGIN)
# if defined(__cplusplus)
#  define CF_EXTERN_C_BEGIN extern "C" {
#  define CF_EXTERN_C_END }
# else
#  define CF_EXTERN_C_BEGIN
#  define CF_EXTERN_C_END
# endif
#endif

#if defined(_WIN32)
# if defined(BUILDING_SELF)
#  if defined(__cplusplus)
#   define CF_EXPORT extern "C" __declspec(dllexport)
#  else
#   define CF_EXPORT extern __declspec(dllexport)
#  endif
# else
#  if defined(__cplusplus)
#   define CF_EXPORT extern "C" __declspec(dllimport)
#  else
#   define CF_EXPORT extern __declspec(dllimport)
#  endif
# endif
#else
# if defined(__cplusplus)
#  define CF_EXPORT extern "C"
# else
#  define CF_EXPORT extern
# endif
#endif

#if !defined(__bool_true_false_are_defined)
# define true 1
# define false 0
#endif

#ifndef TRUE
# define TRUE  1
#endif
#ifndef FALSE
# define FALSE 0
#endif

CF_EXTERN_C_BEGIN

#if !defined(CF_INLINE)
# if defined(__GNUC__) && (__GNUC__ == 4)
#  define CF_INLINE static __inline__ __attribute__((always_inline))
# elif defined(__GNUC__)
#  define CF_INLINE static __inline__
# elif defined(__MWERKS__) || defined(__cplusplus)
#  define CF_INLINE static inline
# elif defined(_MSC_VER)
#  define CF_INLINE static __inline
# elif _WIN32
#  define CF_INLINE static __inline__
# endif
#endif

#if defined(__GNUC__) || defined(__llvm__)
#define GS_PURE_FUNCTION __attribute__((pure))
#else
#define GS_PURE_FUNCTION
#endif

/*
 * CFType types
 */
typedef uintptr_t CFHashCode;
/** @defgroup CFType
    @{
    @class CFType
 */
typedef uintptr_t CFTypeID;
typedef const void *CFTypeRef;
/** @}
 */

/*
 * Base Utilities
 */
typedef uintptr_t CFOptionFlags;
typedef intptr_t CFIndex;

typedef struct {
  CFIndex location;
  CFIndex length;
} CFRange;

/** Creates new range.
    
    @param location The start location.
    @param length The length.
    @return A CFRange structure.
 */
CF_INLINE CFRange
CFRangeMake(CFIndex location, CFIndex length)
{
  CFRange range;

  range.location = location;
  range.length   = length;
  return range;
}

/* Returned by comparison functions */
typedef enum
{
    kCFCompareLessThan = -1,
    kCFCompareEqualTo = 0,
    kCFCompareGreaterThan = 1
} CFComparisonResult;

/* Return when a value is not found */
enum
{
  kCFNotFound = -1
};

/* Definition for standard comparison function callback. */
typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);

/* CoreFoundation version numbers */
CF_EXPORT const double kCFCoreFoundationVersionNumber; 
#define kCFCoreFoundationVersionNumber10_0    196.40
#define kCFCoreFoundationVersionNumber10_0_3  196.50
#define kCFCoreFoundationVersionNumber10_1    226.00
#define kCFCoreFoundationVersionNumber10_1_1  226.00
#define kCFCoreFoundationVersionNumber10_1_2  227.20
#define kCFCoreFoundationVersionNumber10_1_3  227.20
#define kCFCoreFoundationVersionNumber10_1_4  227.30
#define kCFCoreFoundationVersionNumber10_2    263.00
#define kCFCoreFoundationVersionNumber10_2_1  263.10
#define kCFCoreFoundationVersionNumber10_2_2  263.10
#define kCFCoreFoundationVersionNumber10_2_3  263.30
#define kCFCoreFoundationVersionNumber10_2_4  263.30
#define kCFCoreFoundationVersionNumber10_2_5  263.50
#define kCFCoreFoundationVersionNumber10_2_6  263.50
#define kCFCoreFoundationVersionNumber10_2_7  263.50
#define kCFCoreFoundationVersionNumber10_2_8  263.50
#define kCFCoreFoundationVersionNumber10_3    299.00
#define kCFCoreFoundationVersionNumber10_3_1  299.00
#define kCFCoreFoundationVersionNumber10_3_2  299.00
#define kCFCoreFoundationVersionNumber10_3_3  299.30
#define kCFCoreFoundationVersionNumber10_3_4  299.31
#define kCFCoreFoundationVersionNumber10_3_5  299.31
#define kCFCoreFoundationVersionNumber10_3_6  299.32
#define kCFCoreFoundationVersionNumber10_3_7  299.33
#define kCFCoreFoundationVersionNumber10_3_8  299.33
#define kCFCoreFoundationVersionNumber10_3_9  299.35
#define kCFCoreFoundationVersionNumber10_4    368.00
#define kCFCoreFoundationVersionNumber10_4_1  368.10
#define kCFCoreFoundationVersionNumber10_4_2  368.11
#define kCFCoreFoundationVersionNumber10_4_3  368.18
#define kCFCoreFoundationVersionNumber10_4_4_Intel   368.26
#define kCFCoreFoundationVersionNumber10_4_4_PowerPC 368.25
#define kCFCoreFoundationVersionNumber10_4_5_Intel   368.26
#define kCFCoreFoundationVersionNumber10_4_5_PowerPC 368.25
#define kCFCoreFoundationVersionNumber10_4_6_Intel   368.26
#define kCFCoreFoundationVersionNumber10_4_6_PowerPC 368.25
#define kCFCoreFoundationVersionNumber10_4_7  368.27
#define kCFCoreFoundationVersionNumber10_4_8  368.27
#define kCFCoreFoundationVersionNumber10_4_9  368.28
#define kCFCoreFoundationVersionNumber10_4_10 368.28
#define kCFCoreFoundationVersionNumber10_4_11 368.31
#define kCFCoreFoundationVersionNumber10_5    476.00
#define kCFCoreFoundationVersionNumber10_5_1  476.00
#define kCFCoreFoundationVersionNumber10_5_2  476.10
#define kCFCoreFoundationVersionNumber10_5_3  476.13
#define kCFCoreFoundationVersionNumber10_5_4  476.14
#define kCFCoreFoundationVersionNumber10_5_5  476.15
#define kCFCoreFoundationVersionNumber10_5_6  476.17

/*
 *CFPropertyList
 */
typedef CFTypeRef CFPropertyListRef;

/*
 * CFString
 */
#if defined (__OBJC__) && defined (__GNUSTEP_COREBASE_INTERNAL__)
@class NSString;
@class NSMutableString;
typedef NSString * CFStringRef;
typedef NSMutableString * CFMutableStringRef; 
#else
typedef const struct __CFString * CFStringRef;
typedef struct __CFString * CFMutableStringRef;
#endif



/** @defgroup CFAllocator
    @{
    @class CFAllocator
    @extends CFType
    @brief CFAllocator is an opaque type used to allocate and deallocate
    memory.
 */
/** @brief A reference to a CFAllocator object.
 */
typedef const struct __CFAllocator * CFAllocatorRef;

typedef void*       (*CFAllocatorAllocateCallBack)(CFIndex allocSize,
  CFOptionFlags hint, void *info);
typedef void        (*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
typedef void*       (*CFAllocatorReallocateCallBack)(void *ptr,
  CFIndex newsize, CFOptionFlags hint, void *info);
typedef CFIndex     (*CFAllocatorPreferredSizeCallBack)(CFIndex size,
  CFOptionFlags hint, void *info);
typedef const void* (*CFAllocatorRetainCallBack)(const void *info);
typedef void        (*CFAllocatorReleaseCallBack)(const void *info);
typedef CFStringRef        (*CFAllocatorCopyDescriptionCallBack)(const void *info);

struct _CFAllocatorContext
{
  CFIndex version;
  void    *info;
  CFAllocatorRetainCallBack          retain;
  CFAllocatorReleaseCallBack         release;        
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFAllocatorAllocateCallBack        allocate;
  CFAllocatorReallocateCallBack      reallocate;
  CFAllocatorDeallocateCallBack             deallocate;
  CFAllocatorPreferredSizeCallBack   preferredSize;
};
typedef struct _CFAllocatorContext CFAllocatorContext;

/** The default allocator and is equivalent to NULL.
    @see CFAllocatorGetDefault()
    @see CFAllocatorSetDefault()
 */
CF_EXPORT CFAllocatorRef kCFAllocatorDefault;
/** The default system allocator is used internally by GNUstep and is the
    default allocator if none is been defined.
    @see CFAllocatorSetDefault()
 */
CF_EXPORT CFAllocatorRef kCFAllocatorSystemDefault;
/** An allocator that uses the system's malloc, realloc and free functions.
 */
CF_EXPORT CFAllocatorRef kCFAllocatorMalloc;
#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED
/** Equivalent to kCFAllocatorSystemDefault
    @since Mac OS X 10.4
    does not exist on systems other than Darwin.
 */
CF_EXPORT CFAllocatorRef kCFAllocatorMallocZone;
#endif
/** The NULL allocator does perform any operations.  Can be passed as
    a deallocator if you do not want GNUstep to deallocate the data.
 */
CF_EXPORT CFAllocatorRef kCFAllocatorNull;
/** This is a special case allocator directing CFAllocatorCreate() to use
    the given CFAllocatorContext structure to allocate the new allocator.
 */
CF_EXPORT CFAllocatorRef kCFAllocatorUseContext;

/** Create a new CFAllocator.
    
    @param allocator The allocator used to create this allocator or
      kCFAllocatorUseContext to use the functions in @context.
    @param context The new allocator's context functions.
    @return A new CFAllocator or NULL in case of failure.
    @see CFAllocatorContext
 */
CF_EXPORT CFAllocatorRef
CFAllocatorCreate (CFAllocatorRef allocator, CFAllocatorContext *context);

/** Allocate new memory.
    
    @param allocator The CFAllocator to use.
    @param size The number of bytes to allocate.
    @param hint Option flags.  Currently unused and should be 0.
    @return Newly allocated memory of NULL in case of failure.
    @see CFAllocatorDeallocate()
 */
CF_EXPORT void *
CFAllocatorAllocate (CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

/** Deallocate the memory pointed to by @ptr.
    
    @param allocator The CFAllocator to use.
    @param ptr A pointer previously allocated by CFAllocatorAllocate().
    @see CFAllocatorAllocate()
 */
CF_EXPORT void
CFAllocatorDeallocate (CFAllocatorRef allocator, void *ptr);

CF_EXPORT CFIndex
CFAllocatorGetPreferredSizeForSize (CFAllocatorRef allocator, CFIndex size,
  CFOptionFlags hint);

CF_EXPORT void *
CFAllocatorReallocate (CFAllocatorRef allocator, void *ptr, CFIndex newsize,
  CFOptionFlags hint);

CF_EXPORT CFAllocatorRef
CFAllocatorGetDefault (void);

CF_EXPORT void
CFAllocatorSetDefault (CFAllocatorRef allocator);

CF_EXPORT void
CFAllocatorGetContext (CFAllocatorRef allocator, CFAllocatorContext *context);

CF_EXPORT CFTypeID
CFAllocatorGetTypeID (void);
/** @}
 */



/*
 * CFType Functions
 */
/** @ingroup CFType
    @{
 */
/* These function will be implemented in CFRuntime.c since they 
   require runtime support. */
CF_EXPORT CFStringRef
CFCopyDescription (CFTypeRef cf);

CF_EXPORT CFStringRef
CFCopyTypeIDDescription (CFTypeID typeID);

CF_EXPORT Boolean
CFEqual (CFTypeRef cf1, CFTypeRef cf2);

CF_EXPORT CFAllocatorRef
CFGetAllocator (CFTypeRef cf);

CF_EXPORT CFIndex
CFGetRetainCount (CFTypeRef cf);

CF_EXPORT CFTypeID
CFGetTypeID (CFTypeRef cf);

CF_EXPORT CFHashCode
CFHash (CFTypeRef cf);

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT CFTypeRef
CFMakeCollectable (CFTypeRef cf);
#endif

CF_EXPORT void
CFRelease (CFTypeRef cf);

CF_EXPORT CFTypeRef
CFRetain (CFTypeRef cf);
/** @}
 */



/*
 * CFNull
 */
#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
typedef struct __CFNull *CFNullRef;

CF_EXPORT CFNullRef kCFNull;

CFTypeID
CFNullGetTypeID (void);
#endif

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFBASE_H__ */

