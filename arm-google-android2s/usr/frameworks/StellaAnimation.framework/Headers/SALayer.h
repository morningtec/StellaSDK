/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>
#import "SATransform3D.h"

/* Compatibility */
#define CALayer                 SALayer
#define CALayerDelegate         SALayerDelegate
#define CALayoutManager         SALayoutManager

#define kCAOnOrderIn            kSAOnOrderIn
#define kCAOnOrderOut           kSAOnOrderOut
#define kCATransition           kSATransition

#define CAAction                SAAction


STELLA_GRAPHICS_EXPORT NSString * const     kSAOnOrderIn;
STELLA_GRAPHICS_EXPORT NSString * const     kSAOnOrderOut;
STELLA_GRAPHICS_EXPORT NSString * const     kSATransition;


@protocol SAAction
@required
- (void) runActionForKey: (NSString *) key object: (id) object arguments: (NSDictionary *) arguments;
@end

@class SAAnimation;

@interface SALayer : NSObject
{
}

@property(assign) id                        delegate;

@property(retain) id                        contents;
@property SGRect                            contentsRect;
@property SGRect                            contentsCenter;

@property float                             opacity;
@property(getter=isHidden) BOOL             hidden;
@property(assign) BOOL                      masksToBounds;
@property CGFloat                           borderWidth;
@property(retain) CGColorRef                borderColor;
@property(retain) CGColorRef                backgroundColor;

@property(getter=isOpaque) BOOL             opaque;

@property CGRect                            frame;
@property CGRect                            bounds;
@property CGPoint                           position;
@property CGPoint                           anchorPoint;
@property SGFloat                           contentsScale;
@property SATransform3D                     transform;
@property SATransform3D                     sublayerTransform;

@property(readonly) SALayer               * superlayer;
@property(copy) NSArray                   * sublayers;

@property(copy) NSDictionary              * actions;

@property(retain) id                        layoutManager;


+ (id) layer;
- (id) init;

- (id) presentationLayer;
- (id) modelLayer;

- (NSArray *) sublayers;
- (void) setSublayers: (NSArray *) sublayers;
- (void) addSublayer: (SALayer *) layer;
- (void) removeFromSuperlayer;
- (void) insertSublayer: (SALayer *) layer atIndex: (NSUInteger) index;
- (void) insertSublayer: (SALayer *) layer below: (SALayer *) sibling;
- (void) insertSublayer: (SALayer *) layer above: (SALayer *) sibling;
- (void) replaceSublayer: (SALayer *) oldLayer with: (SALayer *) newLayer;

- (void) setNeedsDisplay;
- (void) displayIfNeeded;
- (BOOL) needsDisplay;
- (void) setNeedsDisplayInRect: (SGRect) rect;

+ (id<SAAction>) defaultActionForKey: (NSString *)key;
- (id<SAAction>) actionForKey: (NSString *) key;

- (void) addAnimation:(SAAnimation *) animation forKey: (NSString *) key;
- (SAAnimation *) animationForKey: (NSString *) key;
- (void) removeAllAnimations;
- (void) removeAnimationForKey: (NSString *) key;
- (NSArray *) animationKeys;

- (void) setNeedsLayout;
- (void) layoutIfNeeded;

- (CGPoint) convertPoint: (CGPoint) point fromLayer: (SALayer *) layer;
- (CGPoint) convertPoint: (CGPoint) point toLayer: (SALayer *) layer;

- (SALayer *) hitTest: (SGPoint) point;
- (BOOL) containsPoint: (SGPoint) point;

@end


@interface NSObject (SALayerDelegate)

- (void) displayLayer: (SALayer *)layer;
- (void) drawLayer: (SALayer *) layer inContext: (SGContextRef)context;

- (void) layoutSublayersOfLayer: (SALayer *) layer;

- (id<SAAction>) actionForLayer: (SALayer *)layer forKey: (NSString *) key;
@end


@interface NSObject (SALayoutManager)
- (void) layoutSublayersOfLayer: (SALayer *) layer;
@end

