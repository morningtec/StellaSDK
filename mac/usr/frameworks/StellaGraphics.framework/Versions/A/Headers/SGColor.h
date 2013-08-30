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


STELLA_GRAPHICS_EXPORT SGColorRef      SGColorRetain (SGColorRef self);
STELLA_GRAPHICS_EXPORT void            SGColorRelease (SGColorRef self);

STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreate (SGColorSpaceRef colorSpace, const SGFloat * components);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateCopy (SGColorRef self);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateCopyWithAlpha (SGColorRef self, SGFloat a);
STELLA_GRAPHICS_EXPORT SGColorRef      SGColorCreateWithPattern (SGColorSpaceRef colorSpace, SGPatternRef pattern, const SGFloat * components);

STELLA_GRAPHICS_EXPORT bool            SGColorEqualToColor (SGColorRef self, SGColorRef other);

STELLA_GRAPHICS_EXPORT SGFloat         SGColorGetAlpha (SGColorRef self);
STELLA_GRAPHICS_EXPORT SGColorSpaceRef SGColorGetColorSpace (SGColorRef self);
STELLA_GRAPHICS_EXPORT const SGFloat * SGColorGetComponents (SGColorRef self);
STELLA_GRAPHICS_EXPORT size_t          SGColorGetNumberOfComponents (SGColorRef self);
STELLA_GRAPHICS_EXPORT SGPatternRef    SGColorGetPattern (SGColorRef self);
