/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGColorSpace.h"
#import "SGFunction.h"

/* Compatibility */
#define CGShading             SGShading
#define CGShadingRef          SGShadingRef


#define CGShadingCreateAxial  SGShadingCreateAxial
#define CGShadingCreateRadial SGShadingCreateRadial

#define CGShadingRetain       SGShadingRetain
#define CGShadingRelease      SGShadingRelease



/* Prototypes */
@class SGShading;
typedef SGShading           * SGShadingRef;


STELLA_GRAPHICS_EXPORT SGShadingRef SGShadingCreateAxial (SGColorSpaceRef colorSpace, SGPoint startPoint, SGPoint endPoint, SGFunctionRef function, bool extendStart, bool extendEnd);
STELLA_GRAPHICS_EXPORT SGShadingRef SGShadingCreateRadial (SGColorSpaceRef colorSpace, SGPoint startPoint, float startRadius, SGPoint endPoint, float endRadius, SGFunctionRef function, bool extendStart, bool extendEnd);

STELLA_GRAPHICS_EXPORT SGShadingRef SGShadingRetain (SGShadingRef self);
STELLA_GRAPHICS_EXPORT void         SGShadingRelease (SGShadingRef self);

