/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaKitExport.h"
#import <Foundation/Foundation.h>

/* Compatibility */





typedef enum {
        UITouchPhaseBegan,
        UITouchPhaseMoved,
        UITouchPhaseStationary,
        UITouchPhaseEnded,
        UITouchPhaseCancelled,
        UITouchPhaseHovered,
        UITouchPhaseScrolled,
        UITouchPhaseRightClicked
} UITouchPhase;


/* Prototypes */
@class UIView;
@interface UITouch : NSObject
{
}

@property(nonatomic, readonly, retain) UIView  *view;
@property(nonatomic, readonly, retain) UIWindow  *window;

@property(nonatomic, readonly) NSUInteger  tapCount;
@property(nonatomic, readonly) NSTimeInterval  timestamp;
@property(nonatomic, readonly) UITouchPhase  phase;

- (CGPoint) locationInView: (UIView *)view;
- (CGPoint) previousLocationInView:(UIView *)view;

@end



