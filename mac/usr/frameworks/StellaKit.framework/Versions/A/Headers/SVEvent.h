/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import "StellaKitExport.h"
#import <Foundation/Foundation.h>

typedef enum {
        UIEventTypeTouches,
        UIEventTypeMotion,
        _UIEventTypeKeyPress,
} UIEventType;

typedef enum {
        UIEventSubtypeNone        = 0,
        UIEventSubtypeMotionShake = 1,
} UIEventSubtype;


@class UIView;
@class UIWindow;

@interface UIEvent : NSObject
{
}

- (NSSet *)allTouches;
- (NSSet *)touchesForView:(UIView *)view;
- (NSSet *)touchesForWindow:(UIWindow *)window;

@property(nonatomic, readonly) NSTimeInterval  timestamp;
@property(nonatomic, readonly) UIEventType  type;
@property(nonatomic, readonly) UIEventSubtype  subtype;


@end

