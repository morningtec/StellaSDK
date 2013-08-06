/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

/* Compatibility */



/* Prototypes */
typedef double UIAccelerationValue;

@interface UIAcceleration : NSObject
{
        UIAccelerationValue     _x;
        UIAccelerationValue     _y;
        UIAccelerationValue     _z;
        NSTimeInterval          _timestamp;
}

@property(nonatomic, readonly) UIAccelerationValue  x;
@property(nonatomic, readonly) UIAccelerationValue  y;
@property(nonatomic, readonly) UIAccelerationValue  z;
@property(nonatomic, readonly) NSTimeInterval  timestamp;


@end




