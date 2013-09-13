/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"

/* Compatibility */
#define CGColorSpace    SGColorSpace
#define CGColorSpaceRef SGColorSpaceRef


#define CGColorRenderingIntent                 SGColorRenderingIntent
#define kCGRenderingIntentDefault              kSGRenderingIntentDefault
#define kCGRenderingIntentAbsoluteColorimetric kSGRenderingIntentAbsoluteColorimetric
#define kCGRenderingIntentRelativeColorimetric kSGRenderingIntentRelativeColorimetric
#define kCGRenderingIntentSaturation           kSGRenderingIntentSaturation
#define kCGRenderingIntentPerceptual           kSGRenderingIntentPerceptual

#define CGColorSpaceModel                      SGColorSpaceModel
#define kCGColorSpaceModelMonochrome           kSGColorSpaceModelMonochrome
#define kCGColorSpaceModelRGB                  kSGColorSpaceModelRGB
#define kCGColorSpaceModelCMYK                 kSGColorSpaceModelCMYK
#define kCGColorSpaceModelLab                  kSGColorSpaceModelLab
#define kCGColorSpaceModelDeviceN              kSGColorSpaceModelDeviceN
#define kCGColorSpaceModelIndexed              kSGColorSpaceModelIndexed
#define kCGColorSpaceModelPattern              kSGColorSpaceModelPattern


#define CGColorSpaceCreateDeviceCMYK      SGColorSpaceCreateDeviceCMYK
#define CGColorSpaceCreateDeviceGray      SGColorSpaceCreateDeviceGray
#define CGColorSpaceCreateDeviceRGB       SGColorSpaceCreateDeviceRGB

#define CGColorSpaceCreatePattern         SGColorSpaceCreatePattern

#define CGColorSpaceGetNumberOfComponents SGColorSpaceGetNumberOfComponents
#define CGColorSpaceGetModel              SGColorSpaceGetModel

#define CGColorSpaceRelease               SGColorSpaceRelease
#define CGColorSpaceRetain                SGColorSpaceRetain




/* Prototypes */
@class SGColorSpace;
typedef SGColorSpace      * SGColorSpaceRef;

typedef enum {
        kSGRenderingIntentDefault,
        kSGRenderingIntentAbsoluteColorimetric,
        kSGRenderingIntentRelativeColorimetric,
        kSGRenderingIntentSaturation,
        kSGRenderingIntentPerceptual,
} SGColorRenderingIntent;

typedef enum {
        kSGColorSpaceModelMonochrome,
        kSGColorSpaceModelRGB,
        kSGColorSpaceModelCMYK,
        kSGColorSpaceModelLab,
        kSGColorSpaceModelDeviceN,
        kSGColorSpaceModelIndexed,
        kSGColorSpaceModelPattern,
} SGColorSpaceModel;



STELLA_GRAPHICS_EXPORT SGColorSpaceRef   SGColorSpaceCreateDeviceCMYK ();
STELLA_GRAPHICS_EXPORT SGColorSpaceRef   SGColorSpaceCreateDeviceGray ();
STELLA_GRAPHICS_EXPORT SGColorSpaceRef   SGColorSpaceCreateDeviceRGB ();

STELLA_GRAPHICS_EXPORT SGColorSpaceRef   SGColorSpaceCreatePattern (SGColorSpaceRef baseSpace);

STELLA_GRAPHICS_EXPORT size_t            SGColorSpaceGetNumberOfComponents (SGColorSpaceRef self);
STELLA_GRAPHICS_EXPORT SGColorSpaceModel SGColorSpaceGetModel (SGColorSpaceRef self);

STELLA_GRAPHICS_EXPORT void              SGColorSpaceRelease (SGColorSpaceRef colorSpace);
STELLA_GRAPHICS_EXPORT SGColorSpaceRef   SGColorSpaceRetain (SGColorSpaceRef colorSpace);
