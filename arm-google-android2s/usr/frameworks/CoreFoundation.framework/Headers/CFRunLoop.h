/* CFRunLoop.h
   
   Copyright (C) 2012 Free Software Foundation, Inc.
   
   Author: Stefan Bidigaray <stefanbidi@gmail.com>
   Date: August, 2012
   
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

#ifndef __COREFOUNDATION_CFRUNLOOP_H__
#define __COREFOUNDATION_CFRUNLOOP_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFError.h>

CF_EXTERN_C_BEGIN

typedef struct __CFRunLoop * CFRunLoopRef;
typedef struct __CFRunLoopSource * CFRunLoopSourceRef;
typedef struct __CFRunLoopObserver * CFRunLoopObserverRef;
typedef struct __CFRunLoopTimer * CFRunLoopTimerRef;

typedef enum
{
  kCFRunLoopEntry =         (1 << 0),
  kCFRunLoopBeforeTimers =  (1 << 1),
  kCFRunLoopBeforeSources = (1 << 2),
  kCFRunLoopBeforeWaiting = (1 << 5),
  kCFRunLoopAfterWaiting =  (1 << 6),
  kCFRunLoopExit =          (1 << 7),
  kCFRunLoopAllActivities = 0x0FFFFFFFU
} CFRunLoopActivity;

enum
{
  kCFRunLoopRunFinished =      1,
  kCFRunLoopRunStopped =       2,
  kCFRunLoopRunTimedOut =      3,
  kCFRunLoopRunHandledSource = 4
};


CF_EXPORT const CFStringRef kCFRunLoopCommonModes;
CF_EXPORT const CFStringRef kCFRunLoopDefaultMode;

/*
 * Callbacks
 */
typedef void (*CFRunLoopCancelCallBack) (void *info, CFRunLoopRef rl,
                                         CFStringRef mode);
typedef Boolean (*CFRunLoopEqualCallBack) (const void *info1,
                                           const void *info2);
typedef CFHashCode (*CFRunLoopHashCallBack) (const void *info);
#if 0 /* No mach_port_t support */
typedef mach_port_t (*CFRunLoopGetPortCallBack) (void *info);
typedef void *(*CFRunLoopMachPerformCallBack) (void *msg, CFIndex size,
                                               CFAllocatorRef  alloc,
                                               void *info);
#endif
typedef void (*CFRunLoopPerformCallBack) (void *info);
typedef void (*CFRunLoopScheduleCallBack) (void *info, CFRunLoopRef rl,
                                           CFStringRef mode);

typedef void (*CFRunLoopObserverCallBack) (CFRunLoopObserverRef observer,
                                           CFRunLoopActivity activity,
                                           void *info);

typedef void (*CFRunLoopTimerCallBack) (CFRunLoopTimerRef timer, void *info);

typedef struct CFRunLoopSourceContext CFRunLoopSourceContext;
struct CFRunLoopSourceContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFRunLoopEqualCallBack equal;
  CFRunLoopHashCallBack hash;
  CFRunLoopScheduleCallBack schedule;
  CFRunLoopCancelCallBack cancel;
  CFRunLoopPerformCallBack perform;
};

#if 0 /* No mach_port_t support */
typedef struct CFRunLoopSourceContext1 CFRunLoopSourceContext1;
struct CFRunLoopSourceContext1
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFRunLoopEqualCallBack equal;
  CFRunLoopHashCallBack hash;
  CFRunLoopGetPortCallBack getPort;
  CFRunLoopMachPerformCallBack perform;
};
#endif

typedef struct CFRunLoopObserverContext CFRunLoopObserverContext;
struct CFRunLoopObserverContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};

typedef struct CFRunLoopTimerContext CFRunLoopTimerContext;
struct CFRunLoopTimerContext
{
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
};



/*
 * Getting the CFRunLoop Type ID
 */
CF_EXPORT CFTypeID
CFRunLoopGetTypeID (void);

CF_EXPORT CFTypeID
CFRunLoopSourceGetTypeID (void);

CF_EXPORT CFTypeID
CFRunLoopObserverGetTypeID (void);

CF_EXPORT CFTypeID
CFRunLoopTimerGetTypeID (void);

/*
 * Getting a Run Loop
 */
CF_EXPORT CFRunLoopRef
CFRunLoopGetCurrent (void);

CF_EXPORT CFRunLoopRef
CFRunLoopGetMain (void);

/*
 * Starting and Stopping a Run Loop
 */
CF_EXPORT void
CFRunLoopRun (void);

CF_EXPORT SInt32
CFRunLoopRunInMode (CFStringRef mode, CFTimeInterval seconds,
                    Boolean returnAfterSourceHandled);

CF_EXPORT void
CFRunLoopWakeUp (CFRunLoopRef rl);

CF_EXPORT void
CFRunLoopStop (CFRunLoopRef rl);

CF_EXPORT Boolean
CFRunLoopIsWaiting (CFRunLoopRef rl);

/*
 * Managing Run Loop Modes
 */
CF_EXPORT void
CFRunLoopAddCommonMode (CFRunLoopRef rl, CFStringRef mode);

CF_EXPORT CFArrayRef
CFRunLoopCopyAllModes (CFRunLoopRef rl);

CF_EXPORT CFStringRef
CFRunLoopCopyCurrentMode (CFRunLoopRef rl);

/*
 * Scheduling Blocks
 */
#if __BLOCKS__
#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED
CF_EXPORT void
CFRunLoopPerformBlock (CFRunLoopRef rl, CFTypeRef mode, void (^block)(void));
#endif
#endif

/*
 * Managing Sources
 */
CF_EXPORT void
CFRunLoopAddSource (CFRunLoopRef rl, CFRunLoopSourceRef source,
                    CFStringRef mode);

CF_EXPORT Boolean
CFRunLoopContainsSource (CFRunLoopRef rl, CFRunLoopSourceRef source,
                         CFStringRef mode);

CF_EXPORT void
CFRunLoopRemoveSource (CFRunLoopRef rl, CFRunLoopSourceRef source,
                       CFStringRef mode);

CF_EXPORT CFRunLoopSourceRef
CFRunLoopSourceCreate (CFAllocatorRef  alloc, CFIndex order,
                       CFRunLoopSourceContext *context);

CF_EXPORT void
CFRunLoopSourceGetContext (CFRunLoopSourceRef source,
                           CFRunLoopSourceContext *context);

CF_EXPORT CFIndex
CFRunLoopSourceGetOrder (CFRunLoopSourceRef source);

CF_EXPORT void
CFRunLoopSourceInvalidate (CFRunLoopSourceRef source);

CF_EXPORT Boolean
CFRunLoopSourceIsValid (CFRunLoopSourceRef source);

CF_EXPORT void
CFRunLoopSourceSignal (CFRunLoopSourceRef source);


/*
 * Managing Observers
 */
CF_EXPORT void
CFRunLoopAddObserver (CFRunLoopRef rl, CFRunLoopObserverRef observer,
                      CFStringRef mode);

CF_EXPORT Boolean
CFRunLoopContainsObserver (CFRunLoopRef rl, CFRunLoopObserverRef observer,
                           CFStringRef mode);

CF_EXPORT void
CFRunLoopRemoveObserver (CFRunLoopRef rl, CFRunLoopObserverRef observer,
                         CFStringRef mode);

CF_EXPORT CFRunLoopObserverRef
CFRunLoopObserverCreate (CFAllocatorRef  alloc, CFOptionFlags activities,
                         Boolean repeats, CFIndex order,
                         CFRunLoopObserverCallBack  callback,
                         CFRunLoopObserverContext *context);

CF_EXPORT Boolean
CFRunLoopObserverDoesRepeat (CFRunLoopObserverRef observer);

CF_EXPORT CFOptionFlags
CFRunLoopObserverGetActivities (CFRunLoopObserverRef observer);

CF_EXPORT void
CFRunLoopObserverGetContext (CFRunLoopObserverRef observer,
                             CFRunLoopObserverContext *context);

CF_EXPORT CFIndex
CFRunLoopObserverGetOrder (CFRunLoopObserverRef observer);

CF_EXPORT void
CFRunLoopObserverInvalidate (CFRunLoopObserverRef observer);

CF_EXPORT Boolean
CFRunLoopObserverIsValid (CFRunLoopObserverRef observer);

/*
 * Managing Timers
 */
CF_EXPORT void
CFRunLoopAddTimer (CFRunLoopRef rl, CFRunLoopTimerRef timer,
                   CFStringRef mode);

CF_EXPORT CFAbsoluteTime
CFRunLoopGetNextTimerFireDate (CFRunLoopRef rl, CFStringRef mode);

CF_EXPORT void
CFRunLoopRemoveTimer (CFRunLoopRef rl, CFRunLoopTimerRef timer,
                      CFStringRef mode);

CF_EXPORT Boolean
CFRunLoopContainsTimer (CFRunLoopRef rl, CFRunLoopTimerRef timer,
                        CFStringRef mode);

CF_EXPORT CFRunLoopTimerRef
CFRunLoopTimerCreate (CFAllocatorRef  alloc, CFAbsoluteTime fireDate,
                      CFTimeInterval interval, CFOptionFlags flags,
                      CFIndex order, CFRunLoopTimerCallBack  callback,
                      CFRunLoopTimerContext *context);

CF_EXPORT Boolean
CFRunLoopTimerDoesRepeat (CFRunLoopTimerRef timer);

CF_EXPORT void
CFRunLoopTimerGetContext (CFRunLoopTimerRef timer,
                          CFRunLoopTimerContext *context);

CF_EXPORT CFTimeInterval
CFRunLoopTimerGetInterval (CFRunLoopTimerRef timer);

CF_EXPORT CFAbsoluteTime
CFRunLoopTimerGetNextFireDate (CFRunLoopTimerRef timer);

CF_EXPORT CFIndex
CFRunLoopTimerGetOrder (CFRunLoopTimerRef timer);

CF_EXPORT void
CFRunLoopTimerInvalidate (CFRunLoopTimerRef timer);

CF_EXPORT Boolean
CFRunLoopTimerIsValid (CFRunLoopTimerRef timer);

CF_EXPORT void
CFRunLoopTimerSetNextFireDate (CFRunLoopTimerRef timer,
                                CFAbsoluteTime fireDate);

CF_EXTERN_C_END

#endif /* __COREFOUNDATION_CFRUNLOOP_H__ */

