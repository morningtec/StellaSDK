/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"


/* Compatibility */
#define CGFunction    SGFunction
#define CGFunctionRef SGFunctionRef

/* callbacks */
#define CGFunctionCallbacks           SGFunctionCallbacks
#define CGFunctionEvaluateCallback    SGFunctionEvaluateCallback
#define CGFunctionReleaseInfoCallback SGFunctionReleaseInfoCallback


#define CGFunctionRetain              SGFunctionRetain
#define CGFunctionRelease             SGFunctionRelease
#define CGFunctionCreate              SGFunctionCreate




/* Prototypes */
@class SGFunction;
typedef SGFunction            * SGFunctionRef;

/* callbacks */
typedef void (*SGFunctionEvaluateCallback)(void * info, const float * inData, float * outData);
typedef void (*SGFunctionReleaseInfoCallback)(void * info);

typedef struct {
        unsigned version;
        SGFunctionEvaluateCallback evaluate;
        SGFunctionReleaseInfoCallback releaseInfo;
} SGFunctionCallbacks;


STELLA_GRAPHICS_EXPORT SGFunctionRef SGFunctionRetain (SGFunctionRef self);
STELLA_GRAPHICS_EXPORT void          SGFunctionRelease (SGFunctionRef self);

STELLA_GRAPHICS_EXPORT SGFunctionRef SGFunctionCreate (void * info, size_t domainDimension, const SGFloat * domain, size_t rangeDimension, const SGFloat * range, const SGFunctionCallbacks * callbacks);
