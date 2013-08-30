/*
 * Stella Debut
 * Wenqi Chen 10/2008
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#if defined (__STELLA_PROFILING)
@class SGProfilingTimer;
@interface SGProfiler : NSObject
{
}

+ (SGProfiler *) sharedProfiler;

- (void) enableDumping;
- (void) disableDumping;

- (SGProfilingTimer *) allocTimerIfNeededWithName: (NSString *) name;
- (void) deallocTimer: (SGProfilingTimer *) timer;

- (void) dumpTimersStatus;
@end

@interface SGProfilingTimer : NSObject
{
}

- (void) begin;
- (void) end;

@end

#define SGProfilingEnableDumping()              [[SGProfiler sharedProfiler] enableDumping]
#define SGProfilingDisableDumping()             [[SGProfiler sharedProfiler] disableDumping]
#define SGProfilingBeginTimerNamed(name)        [[[SGProfiler sharedProfiler] allocTimerIfNeededWithName: name] begin]
#define SGProfilingEndTimerNamed(name)          [[[SGProfiler sharedProfiler] allocTimerIfNeededWithName: name] end]



#else
#define SGProfilingEnableDumping()              /**/
#define SGProfilingDisableDumping()             /**/
#define SGProfilingBeginTimerNamed(name)        /**/
#define SGProfilingEndTimerNamed(name)          /**/

#endif