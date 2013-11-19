/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>

@class UIView;
@class UITouch;
@class UIEvent;

typedef enum {
        UIGestureRecognizerStatePossible,
        UIGestureRecognizerStateBegan,
        UIGestureRecognizerStateChanged,
        UIGestureRecognizerStateEnded,
        UIGestureRecognizerStateCancelled,
        UIGestureRecognizerStateFailed,
        UIGestureRecognizerStateRecognized      = UIGestureRecognizerStateEnded
} UIGestureRecognizerState;

@protocol UIGestureRecognizerDelegate;

@interface UIGestureRecognizer : NSObject
{
}

@property(nonatomic, readonly) UIGestureRecognizerState         state;
@property(nonatomic, readonly) UIView                         * view;
@property(nonatomic, getter=isEnabled) BOOL                     enabled;

@property(nonatomic) BOOL                                       cancelsTouchesInView;
@property(nonatomic) BOOL                                       delaysTouchesBegan;
@property(nonatomic) BOOL                                       delaysTouchesEnded;


@property(nonatomic, assign) id<UIGestureRecognizerDelegate>    delegate;


- (id) initWithTarget: (id) target action: (SEL) action;


- (void) addTarget: (id) target action: (SEL) action;
- (void) removeTarget: (id) target action: (SEL) action;

- (CGPoint) locationInView: (UIView *) view;
- (CGPoint) locationOfTouch: (NSUInteger) touchIndex inView: (UIView *) view;
- (NSUInteger) numberOfTouches;

- (void) _setState: (UIGestureRecognizerState) state;
- (void) _setView: (UIView *) view;

- (void) requireGestureRecognizerToFail: (UIGestureRecognizer *) otherGestureRecognizer;

- (void) setDelegate: (id<UIGestureRecognizerDelegate>) delegate;


- (BOOL) _shouldAttemptToRecognize;
- (void) _recognizeTouches: (NSSet *) touches withEvent: (UIEvent *) event;


- (void) touchesBegan: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesMoved: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesEnded: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesCancelled: (NSSet *) touches withEvent: (UIEvent *) event;

- (void) reset;
- (void) ignoreTouch: (UITouch *) touch forEvent: (UIEvent *) event;
- (BOOL) canBePreventedByGestureRecognizer: (UIGestureRecognizer *) preventingGestureRecognizer;
- (BOOL) canPreventGestureRecognizer: (UIGestureRecognizer *) preventedGestureRecognizer;

@end


@protocol UIGestureRecognizerDelegate <NSObject>

@optional
- (BOOL) gestureRecognizerShouldBegin: (UIGestureRecognizer *) gestureRecognizer;
- (BOOL) gestureRecognizer: (UIGestureRecognizer *) gestureRecognizer shouldReceiveTouch: (UITouch *) touch;
- (BOOL) gestureRecognizer: (UIGestureRecognizer *) gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer: (UIGestureRecognizer *) otherGestureRecognizer;

@end

