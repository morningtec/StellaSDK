/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"

/* Compatibility */
#undef CGAffineTransformMake
#undef CGPointApplyAffineTransform
#undef CGSizeApplyAffineTransform
#undef CGRectApplyAffineTransform
#undef CGAffineTransformIdentity

#define CGAffineTransform SGAffineTransform


#define CGAffineTransformIdentity        SGAffineTransformIdentity


#define CGAffineTransformMake            SGAffineTransformMake
#define CGAffineTransformMakeRotation    SGAffineTransformMakeRotation
#define CGAffineTransformMakeScale       SGAffineTransformMakeScale
#define CGAffineTransformMakeTranslation SGAffineTransformMakeTranslation

#define CGAffineTransformTranslate       SGAffineTransformTranslate
#define CGAffineTransformScale           SGAffineTransformScale
#define CGAffineTransformRotate          SGAffineTransformRotate
#define CGAffineTransformInvert          SGAffineTransformInvert
#define CGAffineTransformConcat          SGAffineTransformConcat

#define CGPointApplyAffineTransform      SGPointApplyAffineTransform
#define CGSizeApplyAffineTransform       SGSizeApplyAffineTransform
#define CGRectApplyAffineTransform       SGRectApplyAffineTransform





typedef struct {
        SGFloat a;
        SGFloat b;
        SGFloat c;
        SGFloat d;
        SGFloat tx;
        SGFloat ty;
} SGAffineTransform;

STELLA_GRAPHICS_EXPORT const SGAffineTransform SGAffineTransformIdentity;


STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformMake (SGFloat a, SGFloat b, SGFloat c, SGFloat d, SGFloat tx, SGFloat ty);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformMakeRotation (SGFloat radians);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformMakeScale (SGFloat scalex, SGFloat scaley);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformMakeTranslation (SGFloat tx, SGFloat ty);

STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformTranslate (SGAffineTransform xform, SGFloat tx, SGFloat ty);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformScale (SGAffineTransform xform, SGFloat scalex, SGFloat scaley);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformRotate (SGAffineTransform xform, SGFloat radians);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformInvert (SGAffineTransform xform);
STELLA_GRAPHICS_EXPORT SGAffineTransform SGAffineTransformConcat (SGAffineTransform xform, SGAffineTransform append);

STELLA_GRAPHICS_EXPORT SGPoint           SGPointApplyAffineTransform (SGPoint point, SGAffineTransform xform);
STELLA_GRAPHICS_EXPORT SGSize            SGSizeApplyAffineTransform (SGSize size, SGAffineTransform xform);
STELLA_GRAPHICS_EXPORT SGRect            SGRectApplyAffineTransform (SGRect rect, SGAffineTransform xform);

