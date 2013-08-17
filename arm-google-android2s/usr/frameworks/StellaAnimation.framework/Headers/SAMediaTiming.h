/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#define SAMediaTiming       CAMedingTiming

@protocol SAMediaTiming
@property CFTimeInterval        beginTime;
@property CFTimeInterval        timeOffset;

@property float                 repeatCount;
@property CFTimeInterval        repeatDuration;

@property CFTimeInterval        duration;
@property float                 speed;

@property BOOL                  autoreverses;
@property(copy) NSString      * fillMode;
@end