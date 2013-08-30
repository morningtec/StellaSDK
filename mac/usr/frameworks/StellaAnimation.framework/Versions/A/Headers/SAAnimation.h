/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>
#import "SAMediaTiming.h"
#import "SALayer.h"

/* Compatibility */
#define CAAnimation                         SAAnimation
#define CABasicAnimation                    SABasicAnimation
#define CAPropertyAnimation                 SAPropertyAnimation
#define CATransition                        SATransition
#define CAAnimationDelegate                 SAAnimationDelegate

#define kCATransitionFade                   kSATransitionFade
#define kCATransitionMoveIn                 kSATransitionMoveIn
#define kCATransitionPush                   kSATransitionPush
#define kCATransitionReveal                 kSATransitionReveal

#define kCATransitionFromRight              kSATransitionFromRight
#define kCATransitionFromLeft               kSATransitionFromLeft
#define kCATransitionFromTop                kSATransitionFromTop
#define kCATransitionFromBottom             kSATransitionFromBottom


STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionFade;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionMoveIn;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionPush;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionReveal;

STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionFromRight;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionFromLeft;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionFromTop;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransitionFromBottom;

@protocol SAAction;
@class SAMediaTimingFunction;

@interface SAAnimation : NSObject <NSCopying, SAMediaTiming, SAAction>
{
}
@property (getter=isRemovedOnCompletion) BOOL       removedOnCompletion;
@property (retain) SAMediaTimingFunction          * timingFunction;

@property (retain) id                               delegate;

+ (id) animation;
@end


@interface SAPropertyAnimation : SAAnimation
{
}

@property(copy) NSString                  * keyPath;
@property(getter=isCumulative) BOOL         cumulative;
@property(getter=isAdditive) BOOL           additive;

+ (id) animationWithKeyPath: (NSString *) keyPath;
@end

@interface SABasicAnimation : SAPropertyAnimation
{
}

@property(retain) id        fromValue;
@property(retain) id        toValue;
@property(retain) id        byValue;
@end

@interface SATransition : SAAnimation
{
}

@property float                 startProgress;
@property float                 endProgress;

@property(copy) NSString      * type;
@property(copy) NSString      * subtype;

@end




@interface NSObject (SAAnimationDelegate)
- (void) animationDidStart: (SAAnimation *) animation;
- (void) animationDidStop: (SAAnimation *) animation finished: (BOOL) finished;
@end
