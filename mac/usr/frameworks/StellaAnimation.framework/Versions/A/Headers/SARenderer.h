/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#import "SALayer.h"

#define CARenderer          SARenderer
#define CVTimeStamp         SVTimeStamp

typedef struct _SVTimeStamp
{
        uint32_t        version;
        uint32_t        videoTimeScale;
        int64_t         videoTime;
        uint64_t        hostTime;
        double          rateScalar;
        int64_t         videoRefreshPeriod;
        char            smpteTime[160];     /* smpte time not supported, should be a struct: CVSMPTETime */
        uint64_t        flags;
        uint64_t        reserved;
} SVTimeStamp;


@interface SARenderer : NSObject
{
}

@property (retain) SALayer    * layer;

+ (SARenderer *) rendererWithCGLContext: (void *) ctx options: (NSDictionary *) dict;

- (void) beginFrameAtTime: (CFTimeInterval) timeInterval timeStamp: (SVTimeStamp *) timeStamp;
- (SGRect) updateBounds;
- (void) addUpdateRect: (SGRect) rect;
- (void) render;
- (CFTimeInterval) nextFrameTime;
- (void) endFrame;

@end

