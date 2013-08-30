/* CFStream.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Stefan Bidigaray
   Date: January, 2010
   
   This file is part of GNUstep CoreBase Library.
   
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

#ifndef __COREFOUNDATION_CFSTREAM_H__
#define __COREFOUNDATION_CFSTREAM_H__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFError.h>
#include <CoreFoundation/CFRunLoop.h>
#include <CoreFoundation/CFSocket.h>
#include <CoreFoundation/CFURL.h>

CF_EXTERN_C_BEGIN

typedef struct CFWriteStream *CFWriteStreamRef;
typedef struct CFReadStream *CFReadStreamRef;



#if MAC_OS_X_VERSION_10_1 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFStreamPropertyDataWritten;
CF_EXPORT const CFStringRef kCFStreamPropertySocketNativeHandle;
CF_EXPORT const CFStringRef kCFStreamPropertySocketRemoteHostName;
CF_EXPORT const CFStringRef kCFStreamPropertySocketRemotePortNumber;
#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFStreamPropertyAppendToFile;
#endif
#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT const CFStringRef kCFStreamPropertyFileCurrentOffset;
#endif

struct CFStreamClientContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};
typedef struct CFStreamClientContext CFStreamClientContext;

typedef enum
{
  kCFStreamStatusNotOpen = 0,
  kCFStreamStatusOpening,
  kCFStreamStatusOpen,
  kCFStreamStatusReading,
  kCFStreamStatusWriting,
  kCFStreamStatusAtEnd,
  kCFStreamStatusClosed,
  kCFStreamStatusError
} CFStreamStatus;

/* Deprecated  */
typedef enum
{
  kCFStreamErrorDomainCustom = -1,
  kCFStreamErrorDomainPOSIX = 1,
  kCFStreamErrorDomainMacOSStatus
} CFStreamErrorDomain;


struct _CFStreamError
{
  CFStreamErrorDomain domain;
  SInt32 error;
};
typedef struct _CFStreamError CFStreamError;

typedef enum
{
  kCFStreamEventNone = 0,
  kCFStreamEventOpenCompleted = 1,
  kCFStreamEventHasBytesAvailable = 2,
  kCFStreamEventCanAcceptBytes = 4,
  kCFStreamEventErrorOccurred = 8,
  kCFStreamEventEndEncountered = 16
} CFStreamEventType;

typedef void (*CFWriteStreamClientCallBack) (CFWriteStreamRef stream,
  CFStreamEventType eventType, void *clientCallBackInfo);

typedef void (*CFReadStreamClientCallBack) (CFReadStreamRef stream,
  CFStreamEventType eventType, void *clientCallBackInfo);



/*
 * NSStream functions
 */
/* FIXME: need CFSocket suff...
void
CFStreamCreatePairWithSocket (CFAllocatorRef alloc, CFSocketNativeHandle sock,
                              CFReadStreamRef *readStream,
                              CFWriteStreamRef *writeStream);
*/
CF_EXPORT void
CFStreamCreatePairWithSocketToHost (CFAllocatorRef alloc, CFStringRef host,
                                    UInt32 port, CFReadStreamRef *readStream,
                                    CFWriteStreamRef *writeStream);

/*
 * Creating a Write Stream
 */
CF_EXPORT CFWriteStreamRef
CFWriteStreamCreateWithAllocatedBuffers (CFAllocatorRef alloc,
                                         CFAllocatorRef bufferAllocator);

CF_EXPORT CFWriteStreamRef
CFWriteStreamCreateWithBuffer (CFAllocatorRef alloc, UInt8 *buffer,
                               CFIndex bufferCapacity);

CF_EXPORT CFWriteStreamRef
CFWriteStreamCreateWithFile (CFAllocatorRef alloc, CFURLRef fileURL);

/*
 * Opening and Closing a Write Stream
 */
CF_EXPORT void
CFWriteStreamClose (CFWriteStreamRef stream);

CF_EXPORT Boolean
CFWriteStreamOpen (CFWriteStreamRef stream);

/*
 * Writing to a Stream
 */
CF_EXPORT CFIndex
CFWriteStreamWrite (CFWriteStreamRef stream, const UInt8 *buffer,
                    CFIndex bufferLength);

/*
 * Scheduling a Write Stream
 */
CF_EXPORT void
CFWriteStreamScheduleWithRunLoop (CFWriteStreamRef stream,
                                  CFRunLoopRef runLoop,
                                  CFStringRef runLoopMode);

CF_EXPORT void
CFWriteStreamUnscheduleFromRunLoop (CFWriteStreamRef stream,
                                    CFRunLoopRef runLoop,
                                    CFStringRef runLoopMode);

/*
 * Examining Write Stream Properties
 */
CF_EXPORT Boolean
CFWriteStreamCanAcceptBytes (CFWriteStreamRef stream);

CF_EXPORT CFTypeRef
CFWriteStreamCopyProperty (CFWriteStreamRef stream, CFStringRef propertyName);

/* Deprecated function */
CF_EXPORT CFStreamError
CFWriteStreamGetError (CFWriteStreamRef stream);

CF_EXPORT CFStreamStatus
CFWriteStreamGetStatus (CFWriteStreamRef stream);

/*
 * Setting Write Stream Properties
 */
CF_EXPORT Boolean
CFWriteStreamSetClient (CFWriteStreamRef stream, CFOptionFlags streamEvents,
                        CFWriteStreamClientCallBack clientCB,
                        CFStreamClientContext *clientContext);

/*
 * Getting the CFWriteStream Type ID
 */
CF_EXPORT CFTypeID
CFWriteStreamGetTypeID (void);

/*
 * Creating a Read Stream
 */
CF_EXPORT CFReadStreamRef
CFReadStreamCreateWithBytesNoCopy (CFAllocatorRef alloc, const UInt8 *bytes,
                                   CFIndex length, CFAllocatorRef bytesDeallocator);

CF_EXPORT CFReadStreamRef
CFReadStreamCreateWithFile (CFAllocatorRef alloc, CFURLRef fileURL);

/*
 * Opening and Closing a Read Stream
 */
CF_EXPORT void
CFReadStreamClose (CFReadStreamRef stream);

CF_EXPORT Boolean
CFReadStreamOpen (CFReadStreamRef stream);

/*
 * Reading from a Read Stream
 */
CF_EXPORT CFIndex
CFReadStreamRead (CFReadStreamRef stream, UInt8 *buffer, CFIndex bufferLength);

/*
 * Scheduling a Read Stream
 */
CF_EXPORT void
CFReadStreamScheduleWithRunLoop (CFReadStreamRef stream, CFRunLoopRef runLoop,
                                 CFStringRef runLoopMode);

CF_EXPORT void
CFReadStreamUnscheduleFromRunLoop (CFReadStreamRef stream, CFRunLoopRef runLoop,
                                   CFStringRef runLoopMode);

/*
 * Examining Stream Properties
 */
CF_EXPORT CFTypeRef
CFReadStreamCopyProperty (CFReadStreamRef stream, CFStringRef propertyName);

CF_EXPORT const UInt8 *
CFReadStreamGetBuffer (CFReadStreamRef stream, CFIndex maxBytesToRead,
                       CFIndex *numBytesRead);

/* Deprecated function */
CF_EXPORT CFStreamError
CFReadStreamGetError (CFReadStreamRef stream);


CF_EXPORT CFStreamStatus
CFReadStreamGetStatus (CFReadStreamRef stream);

CF_EXPORT Boolean
CFReadStreamHasBytesAvailable (CFReadStreamRef stream);

/*
 * Setting Stream Properties
 */
CF_EXPORT Boolean
CFReadStreamSetClient (CFReadStreamRef stream, CFOptionFlags streamEvents,
                       CFReadStreamClientCallBack clientCB,
                       CFStreamClientContext *clientContext);

/*
 * Getting the CFReadStream Type ID
 */
CF_EXPORT CFTypeID
CFReadStreamGetTypeID (void);



#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT void
CFStreamCreatePairWithPeerSocketSignature (CFAllocatorRef alloc,
                                           const CFSocketSignature *signature,
                                           CFReadStreamRef *readStream,
                                           CFWriteStreamRef *writeStream);

CF_EXPORT Boolean
CFWriteStreamSetProperty (CFWriteStreamRef stream, CFStringRef propertyName,
                          CFTypeRef propertyValue);

CF_EXPORT Boolean
CFReadStreamSetProperty (CFReadStreamRef stream, CFStringRef propertyName,
                         CFTypeRef propertyValue);
#endif

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT void
CFStreamCreateBoundPair (CFAllocatorRef alloc, CFReadStreamRef *readStream,
                         CFWriteStreamRef *writeStream, CFIndex transferBufferSize);

CF_EXPORT CFErrorRef
CFWriteStreamCopyError (CFWriteStreamRef stream);

CF_EXPORT CFErrorRef
CFReadStreamCopyError (CFReadStreamRef stream);
#endif

#endif /* MAC_OS_X_VERSION_10_1 */

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFSTREAM_H__ */

