/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGAffineTransform.h"


/* Compatibility */
#define CGPath                SGPath
#define CGPathRef             SGPathRef

#define CGMutablePath         SGMutablePath
#define CGMutablePathRef      SGMutablePathRef
#define CGPathApplierFunction SGPathApplierFunction
#define CGPathElement         SGPathElement



#define CGPathElementType                 SGPathElementType
#define kCGPathElementMoveToPoint         kSGPathElementMoveToPoint
#define kCGPathElementAddLineToPoint      kSGPathElementAddLineToPoint
#define kCGPathElementAddQuadCurveToPoint kSGPathElementAddQuadCurveToPoint
#define kCGPathElementAddCurveToPoint     kSGPathElementAddCurveToPoint
#define kCGPathElementCloseSubpath        kSGPathElementCloseSubpath




#define CGPathCreateMutable             SGPathCreateMutable
#define CGPathCreateWithRect            SGPathCreateWithRect
#define CGPathCreateWithRoundedRect     SGPathCreateWithRoundedRect
#define CGPathCreateCopy                SGPathCreateCopy
#define CGPathCreateMutableCopy         SGPathCreateMutableCopy
#define CGPathRelease                   SGPathRelease
#define CGPathRetain                    SGPathRetain

#define CGPathAddArc              SGPathAddArc
#define CGPathAddArcToPoint       SGPathAddArcToPoint
#define CGPathAddCurveToPoint     SGPathAddCurveToPoint
#define CGPathAddLines            SGPathAddLines
#define CGPathAddLineToPoint      SGPathAddLineToPoint
#define CGPathAddPath             SGPathAddPath
#define CGPathAddQuadCurveToPoint SGPathAddQuadCurveToPoint
#define CGPathAddRect             SGPathAddRect
#define CGPathAddRects            SGPathAddRects
#define CGPathAddRounded          SGPathAddRoundedRect
#define CGPathApply               SGPathApply
#define CGPathMoveToPoint         SGPathMoveToPoint
#define CGPathCloseSubpath        SGPathCloseSubpath
#define CGPathAddEllipseInRect    SGPathAddEllipseInRect

#define CGPathEqualToPath         SGPathEqualToPath
#define CGPathGetBoundingBox      SGPathGetBoundingBox
#define CGPathGetCurrentPoint     SGPathGetCurrentPoint
#define CGPathIsEmpty             SGPathIsEmpty
#define CGPathIsRect              SGPathIsRect
#define CGPathContainsPoint       SGPathContainsPoint





/* Prototypes */
@class SGPath;
typedef SGPath            * SGPathRef;

@class SGMutablePath;
typedef SGMutablePath     * SGMutablePathRef;


typedef enum {
        kSGPathElementMoveToPoint,
        kSGPathElementAddLineToPoint,
        kSGPathElementAddQuadCurveToPoint,
        kSGPathElementAddCurveToPoint,
        kSGPathElementCloseSubpath,
} SGPathElementType;

typedef struct {
        SGPathElementType type;
        SGPoint               * points;
} SGPathElement;

typedef void (*SGPathApplierFunction)(void * info, const SGPathElement * element);


STELLA_GRAPHICS_EXPORT SGMutablePathRef SGPathCreateMutable ();
STELLA_GRAPHICS_EXPORT SGPathRef        SGPathCreateWithRect (SGRect rect, const SGAffineTransform * xform);
STELLA_GRAPHICS_EXPORT SGPathRef        SGPathCreateWithRoundedRect (SGRect rect, SGFloat cornerWidth, SGFloat cornerHeight, const SGAffineTransform * xform);
STELLA_GRAPHICS_EXPORT SGPathRef        SGPathCreateCopy (SGPathRef self);
STELLA_GRAPHICS_EXPORT SGMutablePathRef SGPathCreateMutableCopy (SGPathRef self);
STELLA_GRAPHICS_EXPORT void             SGPathRelease (SGPathRef self);
STELLA_GRAPHICS_EXPORT SGPathRef        SGPathRetain (SGPathRef self);

STELLA_GRAPHICS_EXPORT void             SGPathAddArc (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat x, SGFloat y, SGFloat radius, SGFloat startRadian, SGFloat endRadian, bool clockwise);
STELLA_GRAPHICS_EXPORT void             SGPathAddArcToPoint (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat tx1, SGFloat ty1, SGFloat tx2, SGFloat ty2, SGFloat radius);
STELLA_GRAPHICS_EXPORT void             SGPathAddCurveToPoint (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat cp1x, SGFloat cp1y, SGFloat cp2x, SGFloat cp2y, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void             SGPathAddLines (SGMutablePathRef self, const SGAffineTransform * xform, const SGPoint * points, size_t count);
STELLA_GRAPHICS_EXPORT void             SGPathAddLineToPoint (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void             SGPathAddPath (SGMutablePathRef self, const SGAffineTransform * xform, SGPathRef other);
STELLA_GRAPHICS_EXPORT void             SGPathAddQuadCurveToPoint (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat cpx, SGFloat cpy, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void             SGPathAddRect (SGMutablePathRef self, const SGAffineTransform * xform, SGRect rect);
STELLA_GRAPHICS_EXPORT void             SGPathAddRects (SGMutablePathRef self, const SGAffineTransform * xform, const SGRect * rects, size_t count);
STELLA_GRAPHICS_EXPORT void             SGPathAddRoundedRect (SGMutablePathRef path, const SGAffineTransform * xform, SGRect rect, SGFloat cornerWidth, SGFloat cornerHeight);
STELLA_GRAPHICS_EXPORT void             SGPathApply (SGPathRef self, void * info, SGPathApplierFunction function);
STELLA_GRAPHICS_EXPORT void             SGPathMoveToPoint (SGMutablePathRef self, const SGAffineTransform * xform, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void             SGPathAddEllipseInRect (SGMutablePathRef self, const SGAffineTransform * xform, SGRect rect);
STELLA_GRAPHICS_EXPORT void             SGPathCloseSubpath (SGMutablePathRef self);

STELLA_GRAPHICS_EXPORT bool             SGPathEqualToPath (SGPathRef self, SGPathRef other);
STELLA_GRAPHICS_EXPORT SGRect           SGPathGetBoundingBox (SGPathRef self);
STELLA_GRAPHICS_EXPORT SGPoint          SGPathGetCurrentPoint (SGPathRef self);
STELLA_GRAPHICS_EXPORT bool             SGPathIsEmpty (SGPathRef self);
STELLA_GRAPHICS_EXPORT bool             SGPathIsRect (SGPathRef self, SGRect * rect);
STELLA_GRAPHICS_EXPORT bool             SGPathContainsPoint (SGPathRef self, const SGAffineTransform * xform, SGPoint point, bool evenOdd);





