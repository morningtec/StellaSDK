/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaAnimation/StellaAnimation.h>
#import "StellaKitExport.h"
#import "SVResponder.h"
#import "SVGestureRecognizer.h"

enum {
        UIViewAutoresizingNone                 = 0,
        UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,
        UIViewAutoresizingFlexibleWidth        = 1 << 1,
        UIViewAutoresizingFlexibleRightMargin  = 1 << 2,
        UIViewAutoresizingFlexibleTopMargin    = 1 << 3,
        UIViewAutoresizingFlexibleHeight       = 1 << 4,
        UIViewAutoresizingFlexibleBottomMargin = 1 << 5
};
typedef NSUInteger UIViewAutoresizing;

typedef enum {
        UIViewContentModeScaleToFill,
        UIViewContentModeScaleAspectFit,
        UIViewContentModeScaleAspectFill,
        UIViewContentModeRedraw,
        UIViewContentModeCenter,
        UIViewContentModeTop,
        UIViewContentModeBottom,
        UIViewContentModeLeft,
        UIViewContentModeRight,
        UIViewContentModeTopLeft,
        UIViewContentModeTopRight,
        UIViewContentModeBottomLeft,
        UIViewContentModeBottomRight,
} UIViewContentMode;

enum {
        UIViewAnimationOptionLayoutSubviews            = 1 <<  0,
        UIViewAnimationOptionAllowUserInteraction      = 1 <<  1,
        UIViewAnimationOptionBeginFromCurrentState     = 1 <<  2,
        UIViewAnimationOptionRepeat                    = 1 <<  3,
        UIViewAnimationOptionAutoreverse               = 1 <<  4,
        UIViewAnimationOptionOverrideInheritedDuration = 1 <<  5,
        UIViewAnimationOptionOverrideInheritedCurve    = 1 <<  6,
        UIViewAnimationOptionAllowAnimatedContent      = 1 <<  7,
        UIViewAnimationOptionShowHideTransitionViews   = 1 <<  8,

        UIViewAnimationOptionCurveEaseInOut            = 0 << 16,
        UIViewAnimationOptionCurveEaseIn               = 1 << 16,
        UIViewAnimationOptionCurveEaseOut              = 2 << 16,
        UIViewAnimationOptionCurveLinear               = 3 << 16,

        UIViewAnimationOptionTransitionNone            = 0 << 20,
        UIViewAnimationOptionTransitionFlipFromLeft    = 1 << 20,
        UIViewAnimationOptionTransitionFlipFromRight   = 2 << 20,
        UIViewAnimationOptionTransitionCurlUp          = 3 << 20,
        UIViewAnimationOptionTransitionCurlDown        = 4 << 20,
        UIViewAnimationOptionTransitionCrossDissolve   = 5 << 20,
        UIViewAnimationOptionTransitionFlipFromTop     = 6 << 20,
        UIViewAnimationOptionTransitionFlipFromBottom  = 7 << 20,
};
typedef NSUInteger UIViewAnimationOptions;

typedef enum {
        UIViewAnimationCurveEaseInOut,
        UIViewAnimationCurveEaseIn,
        UIViewAnimationCurveEaseOut,
        UIViewAnimationCurveLinear
} UIViewAnimationCurve;

typedef enum {
    UIViewAnimationTransitionNone,
    UIViewAnimationTransitionFlipFromLeft,
    UIViewAnimationTransitionFlipFromRight,
    UIViewAnimationTransitionCurlUp,
    UIViewAnimationTransitionCurlDown,
} UIViewAnimationTransition;

/* Apple-end */

@class UIColor;
@class UIEvent;
@class UIWindow;
@class UIViewController;

@class UIGestureRecognizer;

@interface UIView : UIResponder <NSCoding>
{
}

@property(nonatomic, copy) UIColor                * backgroundColor;
@property(nonatomic, getter=isHidden) BOOL          hidden;
@property(nonatomic) CGFloat                        alpha;
@property(nonatomic, getter=isOpaque) BOOL          opaque;
@property(nonatomic) BOOL                           clipsToBounds;
@property(nonatomic) BOOL                           clearsContextBeforeDrawing;
@property(nonatomic, readonly, retain) CALayer    * layer;

@property(nonatomic, getter=isUserInteractionEnabled) BOOL      userInteractionEnabled;
@property(nonatomic, getter=isMultipleTouchEnabled) BOOL        multipleTouchEnabled;
@property(nonatomic, getter=isExclusiveTouch) BOOL              exclusiveTouch;

@property(nonatomic) CGRect                         frame;
@property(nonatomic) CGRect                         bounds;
@property(nonatomic) CGPoint                        center;
@property(nonatomic) CGAffineTransform              transform;

@property(nonatomic) UIViewAutoresizing             autoresizingMask;
@property(nonatomic) BOOL                           autoresizesSubviews;
@property(nonatomic) UIViewContentMode              contentMode;
@property(nonatomic) CGRect                         contentStretch;

@property(nonatomic) CGFloat                        contentScaleFactor;

@property(nonatomic, readonly) UIView             * superview;
@property(nonatomic, readonly, copy) NSArray      * subviews;
@property(nonatomic, readonly) UIWindow           * window;

@property(nonatomic) NSInteger                      tag;

/* Apple-begin */
@property(nonatomic, copy) NSArray          * gestureRecognizers;
@property(nonatomic, copy) NSString         * restorationIdentifier;
/* Apple-end */

- (id) initWithFrame: (CGRect) frame;


- (void) addSubview: (UIView *) subview;
- (void) removeFromSuperview;
- (void) insertSubview: (UIView *) subview atIndex: (NSInteger) index;
- (void) insertSubview: (UIView *) subview belowSubview: (UIView *) below;
- (void) insertSubview: (UIView *) subview aboveSubview: (UIView *) above;
- (BOOL) isDescendantOfView: (UIView *) view;

- (CGSize) sizeThatFits: (CGSize) size;
- (void) sizeToFit;

- (void) layoutSubviews;
- (void) setNeedsLayout;
- (void) layoutIfNeeded;

- (void) drawRect: (CGRect) rect;
- (void) setNeedsDisplay;
- (void) setNeedsDisplayInRect: (CGRect) rect;

- (void) addGestureRecognizer: (UIGestureRecognizer *) gestureRecognizer;
- (void) removeGestureRecognizer: (UIGestureRecognizer *) gestureRecognizer;
- (NSArray *) gestureRecognizers;
- (void) setGestureRecognizers: (NSArray *) gestureRecognizers;

+ (void) animateWithDuration: (NSTimeInterval) duration
                       delay: (NSTimeInterval) delay
                     options: (UIViewAnimationOptions) options
                  animations: (void (^)(void)) animations
                  completion: (void (^)(BOOL finished)) completion;
+ (void) animateWithDuration: (NSTimeInterval) duration
                  animations: (void (^)(void)) animations
                  completion: (void (^)(BOOL finished)) completion;
+ (void) animateWithDuration: (NSTimeInterval) duration
                  animations: (void (^)(void)) animations;
+ (void) transitionWithView: (UIView *) view
                   duration: (NSTimeInterval) duration
                    options: (UIViewAnimationOptions) options
                 animations: (void (^)(void)) animations
                 completion: (void (^)(BOOL finished)) completion;
+ (void) transitionFromView: (UIView *) fromView
                     toView: (UIView *) toView
                   duration: (NSTimeInterval) duration
                    options: (UIViewAnimationOptions) options
                 completion: (void (^)(BOOL finished)) completion;


- (UIView *) viewWithTag: (NSInteger) tag;

- (CGPoint) convertPoint: (CGPoint) point toView: (UIView *) view;
- (CGPoint) convertPoint: (CGPoint) point fromView: (UIView *) view;
- (CGRect) convertRect: (CGRect) point toView: (UIView *) view;
- (CGRect) convertRect: (CGRect) point fromView: (UIView *) view;

- (UIView *) hitTest: (CGPoint) point withEvent: (UIEvent *) event;
- (BOOL) pointInside: (CGPoint) point withEvent: (UIEvent *) event;

- (void) didAddSubview: (UIView *) subview;
- (void) didMoveToSuperview;
- (void) didMoveToWindow;
- (void) willMoveToSuperview: (UIView *) newSuperview;
- (void) willMoveToWindow: (UIWindow *) newWindow;
- (void) willRemoveSubview: (UIView *) subview;




@end

