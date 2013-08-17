/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGColorSpace.h"
#import "SGDataProvider.h"

/* Compatibility */
#define CGImage    SGImage
#define CGImageRef SGImageRef




#undef kCGBitmapByteOrder16Big
#undef kCGBitmapByteOrder32Big
#undef kCGBitmapByteOrder16Host
#undef kCGBitmapByteOrder32Host

#define CGImageAlphaInfo                SGImageAlphaInfo
#define kCGImageAlphaNone               kSGImageAlphaNone
#define kCGImageAlphaPremultipliedLast  kSGImageAlphaPremultipliedLast
#define kCGImageAlphaPremultipliedFirst kSGImageAlphaPremultipliedFirst
#define kCGImageAlphaLast               kSGImageAlphaLast
#define kCGImageAlphaFirst              kSGImageAlphaFirst
#define kCGImageAlphaNoneSkipLast       kSGImageAlphaNoneSkipLast
#define kCGImageAlphaNoneSkipFirst      kSGImageAlphaNoneSkipFirst
#define kCGImageAlphaOnly               kSGImageAlphaOnly

#define CGBitmapInfo                    SGBitmapInfo
#define kCGBitmapAlphaInfoMask          kSGBitmapAlphaInfoMask
#define kCGBitmapFloatComponents        kSGBitmapFloatComponents
#define kCGBitmapByteOrderDefault       kSGBitmapByteOrderDefault
#define kCGBitmapByteOrder16Little      kSGBitmapByteOrder16Little
#define kCGBitmapByteOrder32Little      kSGBitmapByteOrder32Little
#define kCGBitmapByteOrder16Big         kSGBitmapByteOrder16Big
#define kCGBitmapByteOrder32Big         kSGBitmapByteOrder32Big
#define kCGBitmapByteOrderMask          kSGBitmapByteOrderMask
#define kCGBitmapByteOrder16Host        kSGBitmapByteOrder16Host
#define kCGBitmapByteOrder32Host        kSGBitmapByteOrder32Host





#define CGImageCreate                     SGImageCreate
#define CGImageCreateCopy                 SGImageCreateCopy
#define CGImageCreateCopyWithColorSpace   SGImageCreateCopyWithColorSpace
#define CGImageCreateWithJPEGDataProvider SGImageCreateWithJPEGDataProvider
#define CGImageCreateWithPNGDataProvider  SGImageCreateWithPNGDataProvider
#define CGImageCreateWithImageInRect      SGImageCreateWithImageInRect
#define CGImageCreateWithMask             SGImageCreateWithMask
#define CGImageCreateWithMaskingColors    SGImageCreateWithMaskingColors

#define CGImageMaskCreate                 SGImageMaskCreate
#define CGImageRetain                     SGImageRetain
#define CGImageRelease                    SGImageRelease

#define CGImageGetAlphaInfo               SGImageGetAlphaInfo
#define CGImageGetBitmapInfo              SGImageGetBitmapInfo
#define CGImageGetBitsPerComponent        SGImageGetBitsPerComponent
#define CGImageGetBitsPerPixel            SGImageGetBitsPerPixel
#define CGImageGetBytesPerRow             SGImageGetBytesPerRow
#define CGImageGetColorSpace              SGImageGetColorSpace
#define CGImageGetDataProvider            SGImageGetDataProvider
#define CGImageGetDecode                  SGImageGetDecode
#define CGImageGetHeight                  SGImageGetHeight
#define CGImageGetShouldInterpolate       SGImageGetShouldInterpolate
#define CGImageGetRenderingIntent         SGImageGetRenderingIntent
#define CGImageGetWidth                   SGImageGetWidth
#define CGImageIsMask                     SGImageIsMask









/* Prototypes */
@class SGImage;
typedef SGImage           * SGImageRef;

enum _SGImageAlphaInfo {
        kSGImageAlphaNone,
        kSGImageAlphaPremultipliedLast,
        kSGImageAlphaPremultipliedFirst,
        kSGImageAlphaLast,
        kSGImageAlphaFirst,
        kSGImageAlphaNoneSkipLast,
        kSGImageAlphaNoneSkipFirst,
        kSGImageAlphaOnly,
};
typedef enum _SGImageAlphaInfo      SGImageAlphaInfo;


enum _SGBitmapInfo {
        kSGBitmapAlphaInfoMask          = 0x1F,
        kSGBitmapFloatComponents        = 0x100,

        kSGBitmapByteOrderMask          = 0x7000,
        kSGBitmapByteOrderDefault       = 0x0000,
        kSGBitmapByteOrder16Little      = 0x1000,
        kSGBitmapByteOrder32Little      = 0x2000,
        kSGBitmapByteOrder16Big         = 0x3000,
        kSGBitmapByteOrder32Big         = 0x4000,


    #ifdef __BIG_ENDIAN__
        kSGBitmapByteOrder16Host    = kSGBitmapByteOrder16Big,
        kSGBitmapByteOrder32Host    = kSGBitmapByteOrder32Big,
    #else
        kSGBitmapByteOrder16Host    = kSGBitmapByteOrder16Little,
        kSGBitmapByteOrder32Host    = kSGBitmapByteOrder32Little,
    #endif
};
typedef uint32_t SGBitmapInfo;



STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreate (size_t width, size_t height, size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow, SGColorSpaceRef colorSpace, SGBitmapInfo bitmapInfo, SGDataProviderRef dataProvider, const SGFloat * decode, bool interpolate, SGColorRenderingIntent renderingIntent);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateCopy (SGImageRef self);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateCopyWithColorSpace (SGImageRef self, SGColorSpaceRef colorSpace);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateWithImageInRect (SGImageRef self, SGRect rect);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateWithJPEGDataProvider (SGDataProviderRef jpegProvider, const SGFloat * decode, bool interpolate, SGColorRenderingIntent renderingIntent);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateWithPNGDataProvider (SGDataProviderRef pngProvider, const SGFloat * decode, bool interpolate, SGColorRenderingIntent renderingIntent);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateWithMask (SGImageRef self, SGImageRef mask);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageCreateWithMaskingColors (SGImageRef self, const SGFloat * components);

STELLA_GRAPHICS_EXPORT SGImageRef             SGImageMaskCreate (size_t width, size_t height, size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow, SGDataProviderRef dataProvider, const SGFloat * decode, bool interpolate);
STELLA_GRAPHICS_EXPORT SGImageRef             SGImageRetain (SGImageRef image);
STELLA_GRAPHICS_EXPORT void                   SGImageRelease (SGImageRef image);

STELLA_GRAPHICS_EXPORT SGImageAlphaInfo       SGImageGetAlphaInfo (SGImageRef self);
STELLA_GRAPHICS_EXPORT SGBitmapInfo           SGImageGetBitmapInfo (SGImageRef self);
STELLA_GRAPHICS_EXPORT size_t                 SGImageGetBitsPerComponent (SGImageRef self);
STELLA_GRAPHICS_EXPORT size_t                 SGImageGetBitsPerPixel (SGImageRef self);
STELLA_GRAPHICS_EXPORT size_t                 SGImageGetBytesPerRow (SGImageRef self);
STELLA_GRAPHICS_EXPORT SGColorSpaceRef        SGImageGetColorSpace (SGImageRef self);
STELLA_GRAPHICS_EXPORT SGDataProviderRef      SGImageGetDataProvider (SGImageRef self);
STELLA_GRAPHICS_EXPORT const SGFloat *        SGImageGetDecode (SGImageRef self);
STELLA_GRAPHICS_EXPORT size_t                 SGImageGetHeight (SGImageRef self);
STELLA_GRAPHICS_EXPORT bool                   SGImageGetShouldInterpolate (SGImageRef self);
STELLA_GRAPHICS_EXPORT SGColorRenderingIntent SGImageGetRenderingIntent (SGImageRef self);
STELLA_GRAPHICS_EXPORT size_t                 SGImageGetWidth (SGImageRef self);
STELLA_GRAPHICS_EXPORT bool                   SGImageIsMask (SGImageRef self);




