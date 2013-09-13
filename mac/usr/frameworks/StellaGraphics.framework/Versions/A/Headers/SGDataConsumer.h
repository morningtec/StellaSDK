/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <CoreFoundation/CFData.h>
#import "StellaGraphicsExport.h"

/* Compatibility */
#define CGDataConsumer    SGDataConsumer
#define CGDataConsumerRef SGDataConsumerRef


#define CGDataConsumerCreateWithCFData SGDataConsumerCreateWithCFData
#define CGDataConsumerRelease          SGDataConsumerRelease
#define CGDataConsumerRetain           SGDataConsumerRetain



/* Prototypes */
@class SGDataConsumer;
typedef SGDataConsumer            * SGDataConsumerRef;


STELLA_GRAPHICS_EXPORT SGDataConsumerRef SGDataConsumerCreateWithCFData (CFMutableDataRef data);
STELLA_GRAPHICS_EXPORT void              SGDataConsumerRelease (SGDataConsumerRef self);
STELLA_GRAPHICS_EXPORT SGDataConsumerRef CGDataConsumerRetain (CGDataConsumerRef self);