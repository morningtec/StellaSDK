/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <CoreFoundation/CFDictionary.h>
#import "StellaGraphicsExport.h"
#import "SGImage.h"

/* Compatibility */
#define CGImageSource    SGImageSource
#define CGImageSourceRef SGImageSourceRef


#define CGImageSourceCreateWithData        SGImageSourceCreateWithData

#define CGImageSourceCreateImageAtIndex    SGImageSourceCreateImageAtIndex

#define CGImageSourceGetCount              SGImageSourceGetCount
#define CGImageSourceCopyPropertiesAtIndex SGImageSourceCopyPropertiesAtIndex





/* Prototypes */
@class SGImageSource;
typedef SGImageSource           * SGImageSourceRef;


STELLA_GRAPHICS_EXPORT SGImageSourceRef SGImageSourceCreateWithData (CFDataRef data, CFDictionaryRef options);

STELLA_GRAPHICS_EXPORT SGImageRef       SGImageSourceCreateImageAtIndex (SGImageSourceRef self, size_t index, CFDictionaryRef options);

STELLA_GRAPHICS_EXPORT size_t           SGImageSourceGetCount (SGImageSourceRef self);
STELLA_GRAPHICS_EXPORT CFDictionaryRef  SGImageSourceCopyPropertiesAtIndex (SGImageSourceRef self, size_t index, CFDictionaryRef options);
