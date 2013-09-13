/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <CoreFoundation/CFData.h>
#import "StellaGraphicsExport.h"

/* Compatibility */
#define CGDataProvider    SGDataProvider
#define CGDataProviderRef SGDataProviderRef


#define CGDataProviderCopyData         SGDataProviderCopyData
#define CGDataProviderCreateWithCFData SGDataProviderCreateWithCFData
#define CGDataProviderCreateWithData   SGDataProviderCreateWithData

#define CGDataProviderRelease          SGDataProviderRelease
#define CGDataProviderRetain           SGDataProviderRetain

/* callbacks */
#define CGDataProviderReleaseDataCallback SGDataProviderReleaseDataCallback



/* Prototypes */
@class SGDataProvider;
typedef SGDataProvider            * SGDataProviderRef;

typedef void (*SGDataProviderReleaseDataCallback)(void * info, const void * data, size_t size);


STELLA_GRAPHICS_EXPORT CFDataRef         SGDataProviderCopyData (SGDataProviderRef self);
STELLA_GRAPHICS_EXPORT SGDataProviderRef SGDataProviderCreateWithCFData (CFDataRef data);
STELLA_GRAPHICS_EXPORT SGDataProviderRef SGDataProviderCreateWithData (void * info, const void * data, size_t size, SGDataProviderReleaseDataCallback releaseCallback);


STELLA_GRAPHICS_EXPORT void              SGDataProviderRelease (SGDataProviderRef provider);
STELLA_GRAPHICS_EXPORT SGDataProviderRef SGDataProviderRetain (SGDataProviderRef provider);






