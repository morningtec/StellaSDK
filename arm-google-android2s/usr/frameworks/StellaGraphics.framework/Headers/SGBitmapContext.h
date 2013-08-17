/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGColorSpace.h"
#import "SGImage.h"
#import "SGContext.h"


/* Compatibility */
#define CGBitmapContext                    SGBitmapContext
#define CGBitmapContextRef                 SGBitmapContextRef


#define CGBitmapContextCreate              SGBitmapContextCreate
#define CGBitmapContextCreateImage         SGBitmapContextCreateImage

#define CGBitmapContextGetBitmapInfo       SGBitmapContextGetBitmapInfo
#define CGBitmapContextGetAlphaInfo        SGBitmapContextGetAlphaInfo
#define CGBitmapContextGetBitsPerComponent SGBitmapContextGetBitsPerComponent
#define CGBitmapContextGetBitsPerPixel     SGBitmapContextGetBitsPerPixel
#define CGBitmapContextGetBytesPerRow      SGBitmapContextGetBytesPerRow
#define CGBitmapContextGetColorSpace       SGBitmapContextGetColorSpace
#define CGBitmapContextGetData             SGBitmapContextGetData
#define CGBitmapContextGetHeight           SGBitmapContextGetHeight
#define CGBitmapContextGetWidth            SGBitmapContextGetWidth

#define CGBitmapContextReleaseDataCallback SGBitmapContextReleaseDataCallback




/* Prototypes */
@class SGBitmapContext;
typedef SGBitmapContext            * SGBitmapContextRef;

/* callbacks */
typedef void (*SGBitmapContextReleaseDataCallback)(void * userInfo, void  * data);


STELLA_GRAPHICS_EXPORT SGContextRef     SGBitmapContextCreate (void * data, size_t width, size_t height, size_t bitsPerComponent, size_t bytesPerRow, SGColorSpaceRef colorSpace, SGBitmapInfo bitmapInfo);
STELLA_GRAPHICS_EXPORT SGImageRef       SGBitmapContextCreateImage (SGContextRef self);

STELLA_GRAPHICS_EXPORT SGBitmapInfo     SGBitmapContextGetBitmapInfo (SGContextRef self);
STELLA_GRAPHICS_EXPORT SGImageAlphaInfo SGBitmapContextGetAlphaInfo (SGContextRef self);
STELLA_GRAPHICS_EXPORT size_t           SGBitmapContextGetBitsPerComponent (SGContextRef self);
STELLA_GRAPHICS_EXPORT size_t           SGBitmapContextGetBitsPerPixel (SGContextRef self);
STELLA_GRAPHICS_EXPORT size_t           SGBitmapContextGetBytesPerRow (SGContextRef self);
STELLA_GRAPHICS_EXPORT SGColorSpaceRef  SGBitmapContextGetColorSpace (SGContextRef self);
STELLA_GRAPHICS_EXPORT void *           SGBitmapContextGetData (SGContextRef self);
STELLA_GRAPHICS_EXPORT size_t           SGBitmapContextGetHeight (SGContextRef self);
STELLA_GRAPHICS_EXPORT size_t           SGBitmapContextGetWidth (SGContextRef self);




