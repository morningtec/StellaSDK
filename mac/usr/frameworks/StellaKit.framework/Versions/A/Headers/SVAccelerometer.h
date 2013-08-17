/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

/* Compatibility */



/* Prototypes */
@protocol UIAccelerometerDelegate;
@interface UIAccelerometer : NSObject
{
}

@property(nonatomic) NSTimeInterval                         updateInterval;
@property(nonatomic, assign) id<UIAccelerometerDelegate>    delegate;

+ (UIAccelerometer *)sharedAccelerometer;

@end



@class UIAcceleration;
@protocol UIAccelerometerDelegate <NSObject>
@optional
- (void)accelerometer:(UIAccelerometer *) accelerometer didAccelerate:(UIAcceleration *)acceleration;
@end


