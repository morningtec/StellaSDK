/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"
#import "SGContext.h"


/* Compatibility */
#define CGPattern    SGPattern
#define CGPatternRef SGPatternRef

#if 0
#define CGContext    SGContext
#define CGContextRef SGContextRef
#endif


#define CGPatternTiling                                  SGPatternTiling
#define kCGPatternTilingNoDistortion                     kSGPatternTilingNoDistortion
#define kCGPatternTilingConstantSpacingMinimalDistortion kSGPatternTilingConstantSpacingMinimalDistortion
#define kCGPatternTilingConstantSpacing                  kSGPatternTilingConstantSpacing


#define CGPatternCreate              SGPatternCreate
#define CGPatternRetain              SGPatternRetain
#define CGPatternRelease             SGPatternRelease

#define CGPatternCallbacks           SGPatternCallbacks
#define CGPatternDrawPatternCallback SGPatternDrawPatternCallback
#define CGPatternReleaseInfoCallback CGPatternReleaseInfoCallback



/* Prototypes */
@class SGPattern;
typedef SGPattern     * SGPatternRef;

#if 0
@class SGContext;
typedef SGContext     * SGContextRef;
#endif

typedef void (*SGPatternDrawPatternCallback)(
        void          * info,
        SGContextRef context
        );

typedef void (*SGPatternReleaseInfoCallback)(
        void      * info
        );


typedef struct {
        unsigned int version;
        SGPatternDrawPatternCallback drawPattern;
        SGPatternReleaseInfoCallback releaseInfo;
} SGPatternCallbacks;

typedef enum  {
        kSGPatternTilingNoDistortion,
        kSGPatternTilingConstantSpacingMinimalDistortion,
        kSGPatternTilingConstantSpacing,
} SGPatternTiling;


// STELLA_GRAPHICS_EXPORT SGPatternRef SGPatternCreate (void * info,SGRect bounds, SGAffineTransform matrix, SGFloat xstep, SGFloat ystep,SGPatternTiling tiling,bool isColored,const SGPatternCallbacks *callbacks);

STELLA_GRAPHICS_EXPORT SGPatternRef SGPatternRetain (SGPatternRef self);
STELLA_GRAPHICS_EXPORT void         SGPatternRelease (SGPatternRef self);

