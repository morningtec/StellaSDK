/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGColorSpace.h"


/* Compatibility */
#define CGGradient    SGGradient
#define CGGradientRef SGGradientRef



#define CGGradientCreateWithColorComponents SGGradientCreateWithColorComponents
#define CGGradientCreateWithColors          SGGradientCreateWithColors
#define CGGradientRelease                   SGGradientRelease
#define CGGradientRetain                    SGGradientRetain

#define CGGradientDrawingOptions            SGGradientDrawingOptions
#define kCGGradientDrawsBeforeStartLocation kSGGradientDrawsBeforeStartLocation
#define kCGGradientDrawsAfterEndLocation    kSGGradientDrawsAfterEndLocation



/* Prototypes */
@class SGGradient;
typedef SGGradient            * SGGradientRef;

typedef enum {
        kSGGradientDrawsBeforeStartLocation     = 0x01,
        kSGGradientDrawsAfterEndLocation        = 0x02
} SGGradientDrawingOptions;

SGGradientRef SGGradientCreateWithColorComponents (SGColorSpaceRef colorSpace, const SGFloat components[], const SGFloat locations[], size_t count);
SGGradientRef SGGradientCreateWithColors (SGColorSpaceRef colorSpace, CFArrayRef colors, const SGFloat locations[]);

void          SGGradientRelease (SGGradientRef self);
SGGradientRef SGGradientRetain (SGGradientRef self);
