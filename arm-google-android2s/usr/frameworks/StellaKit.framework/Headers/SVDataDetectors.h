/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>


enum {
    UIDataDetectorTypePhoneNumber   = 1 << 0,
    UIDataDetectorTypeLink          = 1 << 1,
    UIDataDetectorTypeAddress       = 1 << 2,
    UIDataDetectorTypeCalendarEvent = 1 << 3,
    UIDataDetectorTypeNone          = 0,
    UIDataDetectorTypeAll           = NSUIntegerMax
};
typedef NSUInteger UIDataDetectorTypes;

