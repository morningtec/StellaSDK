/* CFSocket.h
   
   Copyright (C) 2012 Free Software Foundation, Inc.
   
   Author: Stefan Bidigaray <stefanbidi@gmail.com>
   Date: September, 2012
   
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

#ifndef __COREFOUNDATION_CFSOCKET_H__
#define __COREFOUNDATION_CFSOCKET_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFDate.h>

CF_EXTERN_C_BEGIN

typedef struct __CFSocket * CFSocketRef;

#if defined(_WIN32)
#include <winsock2.h>
typedef SOCKET CFSocketNativeHandle;
#else
typedef int CFSocketNativeHandle;
#endif

typedef struct CFSocketContext CFSocketContext;
struct CFSocketContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};

typedef struct CFSocketSignature CFSocketSignature;
struct CFSocketSignature
{
  SInt32 protocolFamily;
  SInt32 socketType;
  SInt32 protocol;
  CFDataRef address;
};

typedef enum
{
  kCFSocketNoCallBack =      0,
  kCFSocketReadCallBack =    1,
  kCFSocketAcceptCallBack =  2,
  kCFSocketDataCallBack =    3,
  kCFSocketConnectCallBack = 4
#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
  ,
  kCFSocketWriteCallBack =   8
#endif
} CFSocketCallBackType;

#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
enum
{
  kCFSocketAutomaticallyReenableReadCallBack =   1,
  kCFSocketAutomaticallyReenableAcceptCallBack = 2,
  kCFSocketAutomaticallyReenableDataCallBack =   3,
  kCFSocketAutomaticallyReenableWriteCallBack =  8,
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED
  kCFSocketLeaveErrors = 64,
#endif
  kCFSocketCloseOnInvalidate = 128
};
#endif

typedef enum
{
  kCFSocketSuccess =  0,
  kCFSocketError =   -1,
  kCFSocketTimeout = -2
} CFSocketError;

typedef void (*CFSocketCallBack) (CFSocketRef s,
                                  CFSocketCallBackType callbackType,
                                  CFDataRef address,
                                  const void *data,
                                  void *info);

CF_EXPORT const CFStringRef kCFSocketCommandKey;
CF_EXPORT const CFStringRef kCFSocketNameKey;
CF_EXPORT const CFStringRef kCFSocketValueKey;
CF_EXPORT const CFStringRef kCFSocketResultKey;
CF_EXPORT const CFStringRef kCFSocketErrorKey;
CF_EXPORT const CFStringRef kCFSocketRegisterCommand;
CF_EXPORT const CFStringRef kCFSocketRetrieveCommand;



CF_EXPORT CFTypeID
CFSocketGetTypeID (void);

/*
 * Creating Sockets
 */
CF_EXPORT CFSocketRef
CFSocketCreate (CFAllocatorRef allocator, SInt32 protocolFamily,
                SInt32 socketType, SInt32 protocol,
                CFOptionFlags callBackTypes, CFSocketCallBack callout,
                const CFSocketContext *context);

CF_EXPORT CFSocketRef
CFSocketCreateConnectedToSocketSignature (CFAllocatorRef allocator,
                                          const CFSocketSignature *signature,
                                          CFOptionFlags callBackTypes,
                                          CFSocketCallBack callout,
                                          const CFSocketContext *context,
                                          CFTimeInterval timeout);

CF_EXPORT CFSocketRef
CFSocketCreateWithNative (CFAllocatorRef allocator, CFSocketNativeHandle sock,
                          CFOptionFlags callBackTypes,
                          CFSocketCallBack callout,
                          const CFSocketContext *context);

CF_EXPORT CFSocketRef
CFSocketCreateWithSocketSignature (CFAllocatorRef allocator,
                                   const CFSocketSignature *signature,
                                   CFOptionFlags callBackTypes,
                                   CFSocketCallBack callout,
                                   const CFSocketContext *context);

/*
 * Configuring Sockets
 */
CF_EXPORT CFDataRef
CFSocketCopyAddress (CFSocketRef s);

CF_EXPORT CFDataRef
CFSocketCopyPeerAddress (CFSocketRef s);

CF_EXPORT void
CFSocketGetContext (CFSocketRef s, CFSocketContext *context);

CF_EXPORT CFSocketNativeHandle
CFSocketGetNative (CFSocketRef s);

CF_EXPORT CFSocketError
CFSocketSetAddress (CFSocketRef s, CFDataRef address);

#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT void
CFSocketDisableCallBacks (CFSocketRef s, CFOptionFlags callBackTypes);

CF_EXPORT void
CFSocketEnableCallBacks (CFSocketRef s, CFOptionFlags callBackTypes);

CF_EXPORT CFOptionFlags
CFSocketGetSocketFlags (CFSocketRef s);

CF_EXPORT void
CFSocketSetSocketFlags (CFSocketRef s, CFOptionFlags flags);
#endif

/*
 * Using Sockets
 */
CF_EXPORT CFSocketError
CFSocketConnectToAddress (CFSocketRef s, CFDataRef address,
                          CFTimeInterval timeout);

CF_EXPORT CFRunLoopSourceRef
CFSocketCreateRunLoopSource (CFAllocatorRef allocator, CFSocketRef s,
                             CFIndex order);

CF_EXPORT void
CFSocketInvalidate (CFSocketRef s);

CF_EXPORT Boolean
CFSocketIsValid (CFSocketRef s);

CF_EXPORT CFSocketError
CFSocketSendData (CFSocketRef s, CFDataRef address, CFDataRef data,
                  CFTimeInterval timeout);

/*
 * Socket Name Server Utilities
 */
CF_EXPORT CFSocketError
CFSocketCopyRegisteredSocketSignature (const CFSocketSignature *nameServerSignature,
                                       CFTimeInterval timeout,
                                       CFStringRef name,
                                       CFSocketSignature *signature,
                                       CFDataRef *nameServerAddress);

CF_EXPORT CFSocketError
CFSocketCopyRegisteredValue (const CFSocketSignature *nameServerSignature,
                             CFTimeInterval timeout,
                             CFStringRef name,
                             CFPropertyListRef *value,
                             CFDataRef *nameServerAddress);

CF_EXPORT UInt16
CFSocketGetDefaultNameRegistryPortNumber (void);

CF_EXPORT CFSocketError
CFSocketRegisterSocketSignature (const CFSocketSignature *nameServerSignature,
                                 CFTimeInterval timeout,
                                 CFStringRef name,
                                 const CFSocketSignature *signature);

CF_EXPORT CFSocketError
CFSocketRegisterValue (const CFSocketSignature *nameServerSignature,
                       CFTimeInterval timeout,
                       CFStringRef name,
                       CFPropertyListRef value);

CF_EXPORT void
CFSocketSetDefaultNameRegistryPortNumber (UInt16 port);

CF_EXPORT CFSocketError
CFSocketUnregister (const CFSocketSignature *nameServerSignature,
                    CFTimeInterval timeout, CFStringRef name);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFSOCKET_H__ */

