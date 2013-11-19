/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"


enum {
        UIControlEventTouchDown             = 1 <<  0,
        UIControlEventTouchDownRepeat       = 1 <<  1,
        UIControlEventTouchDragInside       = 1 <<  2,
        UIControlEventTouchDragOutside      = 1 <<  3,
        UIControlEventTouchDragEnter        = 1 <<  4,
        UIControlEventTouchDragExit         = 1 <<  5,
        UIControlEventTouchUpInside         = 1 <<  6,
        UIControlEventTouchUpOutside        = 1 <<  7,
        UIControlEventTouchCancel           = 1 <<  8,

        UIControlEventValueChanged          = 1 << 12,

        UIControlEventEditingDidBegin       = 1 << 16,
        UIControlEventEditingChanged        = 1 << 17,
        UIControlEventEditingDidEnd         = 1 << 18,
        UIControlEventEditingDidEndOnExit   = 1 << 19,

        UIControlEventAllTouchEvents        = 0x00000FFF,
        UIControlEventAllEditingEvents      = 0x000F0000,
        UIControlEventApplicationReserved   = 0x0F000000,
        UIControlEventSystemReserved        = 0xF0000000,
        UIControlEventAllEvents             = 0xFFFFFFFF
};
typedef NSUInteger UIControlEvents;

enum {
        UIControlStateNormal               = 0,
        UIControlStateHighlighted          = 1 << 0,
        UIControlStateDisabled             = 1 << 1,
        UIControlStateSelected             = 1 << 2,
        UIControlStateApplication          = 0x00FF0000,
        UIControlStateReserved             = 0xFF000000
};
typedef NSUInteger  UIControlState;


typedef enum {
        UIControlContentVerticalAlignmentCenter     = 0,
        UIControlContentVerticalAlignmentTop        = 1,
        UIControlContentVerticalAlignmentBottom     = 2,
        UIControlContentVerticalAlignmentFill       = 3,
} UIControlContentVerticalAlignment;

typedef enum {
        UIControlContentHorizontalAlignmentCenter   = 0,
        UIControlContentHorizontalAlignmentLeft     = 1,
        UIControlContentHorizontalAlignmentRight    = 2,
        UIControlContentHorizontalAlignmentFill     = 3,
} UIControlContentHorizontalAlignment;

@class UIEvent;
@class UITouch;

@interface UIControl : UIView
{
}

@property(nonatomic, readonly) UIControlState               state;
@property(nonatomic, getter=isEnabled) BOOL                 enabled;
@property(nonatomic, getter=isSelected) BOOL                selected;
@property(nonatomic, getter=isHighlighted) BOOL             highlighted;
@property(nonatomic) UIControlContentVerticalAlignment      contentVerticalAlignment;
@property(nonatomic) UIControlContentHorizontalAlignment    contentHorizontalAlignment;

@property(nonatomic, readonly, getter=isTracking) BOOL      tracking;
@property(nonatomic, readonly, getter=isTouchInside) BOOL   touchInside;


- (void) sendAction: (SEL) action to: (id) target forEvent: (UIEvent *) event;

- (void) addTarget: (id) target action: (SEL) action forControlEvents: (UIControlEvents) controlEvents;


- (BOOL) beginTrackingWithTouch: (UITouch *) touch withEvent: (UIEvent *) event;
- (BOOL) continueTrackingWithTouch: (UITouch *) touch withEvent: (UIEvent *) event;
- (void) endTrackingWithTouch: (UITouch *) touch withEvent: (UIEvent *) event;
- (void) cancelTrackingWithEvent: (UIEvent *) event;

/* Apple-begin */
- (void) removeTarget: (id) target action: (SEL) action forControlEvents: (UIControlEvents) controlEvents;
- (NSArray *) actionsForTarget: (id) target forControlEvent: (UIControlEvents) controlEvent;
- (UIControlEvents) allControlEvents;
- (void) sendActionsForControlEvents: (UIControlEvents) controlEvents;
- (NSSet *) allTargets;
/* Apple-end */

@end

