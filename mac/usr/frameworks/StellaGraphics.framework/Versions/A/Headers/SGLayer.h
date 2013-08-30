/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGContext.h"

/* Compatibility */
#define CGLayer    SGLayer
#define CGLayerRef SGLayerRef


#define CGLayerCreateWithContext SGLayerCreateWithContext

#define CGLayerRelease           SGLayerRelease
#define CGLayerRetain            SGLayerRetain

#define CGLayerGetSize           SGLayerGetSize
#define CGLayerGetContext        SGLayerGetContext




/* Prototypes */
@class SGLayer;
typedef SGLayer           * SGLayerRef;

STELLA_GRAPHICS_EXPORT SGLayerRef   SGLayerCreateWithContext (SGContextRef context, SGSize size, id unused);

STELLA_GRAPHICS_EXPORT void         SGLayerRelease (SGLayerRef self);
STELLA_GRAPHICS_EXPORT SGLayerRef   SGLayerRetain (SGLayerRef self);

STELLA_GRAPHICS_EXPORT SGSize       SGLayerGetSize (SGLayerRef self);
STELLA_GRAPHICS_EXPORT SGContextRef SGLayerGetContext (SGLayerRef self);

