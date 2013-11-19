/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGBase.h"

#import <stdbool.h>

/* Compatibility */
#define CGRect      SGRect
#define CGPoint     SGPoint
#define CGSize      SGSize

#undef CGPointEqualToPoint
#undef CGSizeEqualToSize
#undef CGRectEqualToRect

#define CGPointMake          SGPointMake
#define CGSizeMake           SGSizeMake
#define CGRectMake           SGRectMake

#define CGRectInset             SGRectInset
#define CGRectIntegral          SGRectIntegral
#define CGRectIntersection      SGRectIntersection
#define CGRectOffset            SGRectOffset
#define CGRectStandardize       SGRectStandardize
#define CGRectUnion             SGRectUnion

#define CGPointEqualToPoint  SGPointEqualToPoint
#define CGSizeEqualToSize    SGSizeEqualToSize
#define CGRectEqualToRect    SGRectEqualToRect
#define CGRectIntersectsRect SGRectIntersectsRect

#define CGRectContainsPoint  SGRectContainsPoint
#define CGRectContainsRect   SGRectContainsRect

#define CGRectGetMinX        SGRectGetMinX
#define CGRectGetMinY        SGRectGetMinY
#define CGRectGetMidX        SGRectGetMidX
#define CGRectGetMidY        SGRectGetMidY
#define CGRectGetMaxX        SGRectGetMaxX
#define CGRectGetMaxY        SGRectGetMaxY


#define CGRectGetWidth       SGRectGetWidth
#define CGRectGetHeight      SGRectGetHeight

#define CGRectIsEmpty        SGRectIsEmpty
#define CGRectIsNull         SGRectIsNull
#define CGRectIsInfinite     SGRectIsInfinite



#define CGRectInfinite          SGRectInfinite
#define CGRectNull              SGRectNull

#define CGRectZero              SGRectZero
#define CGPointZero             SGPointZero
#define CGSizeZero              SGSizeZero




/* Prototypes */
typedef NSPoint         SGPoint;
typedef NSSize          SGSize;
typedef NSRect          SGRect;

STELLA_GRAPHICS_EXPORT SGPoint SGPointMake (SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT SGSize  SGSizeMake (SGFloat width, SGFloat height);
STELLA_GRAPHICS_EXPORT SGRect  SGRectMake (SGFloat x, SGFloat y, SGFloat width, SGFloat height);

STELLA_GRAPHICS_EXPORT SGRect SGRectInset (SGRect rect, SGFloat dx, SGFloat dy);
STELLA_GRAPHICS_EXPORT SGRect SGRectIntegral (SGRect rect);
STELLA_GRAPHICS_EXPORT SGRect SGRectIntersection (SGRect r1, SGRect r2) ;
STELLA_GRAPHICS_EXPORT SGRect SGRectOffset (SGRect rect, SGFloat dx, SGFloat dy);
STELLA_GRAPHICS_EXPORT SGRect SGRectStandardize (SGRect rect);
STELLA_GRAPHICS_EXPORT SGRect SGRectUnion (SGRect r1, SGRect r2);

STELLA_GRAPHICS_EXPORT BOOL    SGPointEqualToPoint (SGPoint point1, SGPoint point2);
STELLA_GRAPHICS_EXPORT BOOL    SGSizeEqualToSize (SGSize size1, SGSize size2);
STELLA_GRAPHICS_EXPORT BOOL    SGRectEqualToRect (SGRect rect1, SGRect rect2);
STELLA_GRAPHICS_EXPORT BOOL    SGRectIntersectsRect (SGRect rect1, SGRect rect2);

STELLA_GRAPHICS_EXPORT BOOL     SGRectContainsPoint (SGRect rect, SGPoint point);
STELLA_GRAPHICS_EXPORT BOOL     SGRectContainsRect (SGRect rect1, SGRect rect2);

STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMinX (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMaxX (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMidX (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMidY (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMinY (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetMaxY (SGRect rect);

STELLA_GRAPHICS_EXPORT SGFloat SGRectGetWidth (SGRect rect);
STELLA_GRAPHICS_EXPORT SGFloat SGRectGetHeight (SGRect rect);

STELLA_GRAPHICS_EXPORT BOOL    SGRectIsEmpty (SGRect rect);
STELLA_GRAPHICS_EXPORT BOOL    SGRectIsNull (SGRect rect);
STELLA_GRAPHICS_EXPORT BOOL    SGRectIsInfinity (SGRect rect);


STELLA_GRAPHICS_EXPORT const SGRect     SGRectZero;
STELLA_GRAPHICS_EXPORT const SGSize     SGSizeZero;
STELLA_GRAPHICS_EXPORT const SGRect     SGRectNull;

STELLA_GRAPHICS_EXPORT const SGRect     SGRectInfinite;
STELLA_GRAPHICS_EXPORT const SGPoint    SGPointZero;

