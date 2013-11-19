/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGColorSpace.h"
#import "SGPattern.h"

/* Compatibility */
#define CGColor                      SGColor
#define CGColorRef                   SGColorRef


#define CGColorRetain                SGColorRetain
#define CGColorRelease               SGColorRelease
#define CGColorCreate                SGColorCreate
#define CGColorCreateCopy            SGColorCreateCopy
#define CGColorCreateCopyWithAlpha   SGColorCreateCopyWithAlpha
#define CGColorCreateWithPattern     SGColorCreateWithPattern

#define CGColorEqualToColor          SGColorEqualToColor

#define CGColorGetAlpha              SGColorGetAlpha
#define CGColorGetColorSpace         SGColorGetColorSpace
#define CGColorGetComponents         SGColorGetComponents
#define CGColorGetNumberOfComponents SGColorGetNumberOfComponents
#define CGColorGetPattern            SGColorGetPattern





/* Prototypes */
@class SGColor;
typedef SGColor     * SGColorRef;


STELLA_GRAPHICS_EXPORT SGColorRef      SGColorRetain (SGColorRef color);
STELLA_GRAPHICS_EXPORT void            SGColorRelease (SGColorRef color);

STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreate (SGColorSpaceRef colorspace, const SGFloat * components);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateCopy (SGColorRef color);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateCopyWithAlpha (SGColorRef color, SGFloat alpha);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateWithPattern (SGColorSpaceRef colorspace, SGPatternRef pattern, const SGFloat * components);

STELLA_GRAPHICS_EXPORT BOOL            SGColorEqualToColor (SGColorRef color, SGColorRef other);
STELLA_GRAPHICS_EXPORT SGFloat         SGColorGetAlpha (SGColorRef color);
STELLA_GRAPHICS_EXPORT SGColorSpaceRef SGColorGetColorSpace (SGColorRef color);
STELLA_GRAPHICS_EXPORT const SGFloat * SGColorGetComponents (SGColorRef color);
STELLA_GRAPHICS_EXPORT size_t          SGColorGetNumberOfComponents (SGColorRef color);
STELLA_GRAPHICS_EXPORT SGPatternRef    SGColorGetPattern (SGColorRef color);
