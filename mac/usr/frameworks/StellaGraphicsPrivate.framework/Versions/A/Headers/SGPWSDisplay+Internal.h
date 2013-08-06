/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/SGGeometry.h>

#import "SGPWSWindow+Internal.h"

@class SGEvent;

@protocol SGTextureBackedLayer;

enum _SGInterfaceIdiom {
        SGInterfaceIdiomPhone,
        SGInterfaceIdiomPad,
        SGInterfaceIdiomFullScreen,
};
typedef NSUInteger      SGInterfaceIdiom;


@interface SGPWSDisplay : NSObject
{
}

@property(readonly, nonatomic) SGInterfaceIdiom         userInterfaceIdiom;
@property(readonly, nonatomic) SGContext              * context;
@property(nonatomic, readonly) SGFloat                  canvasScale;

+ (SGPWSDisplay *) sharedDisplay;

- (SGEvent *) nextEventMatchingMask: (NSUInteger) mask  untilDate: (NSDate *) untilDate inMode: (NSString *) mode dequeue: (BOOL) dequeue;
                            
- (SGPWSWindow *) allocPWSWindowWithFrame: (SGRect) frame;
- (void) deallocPWSWindow: (SGPWSWindow *) window;
- (void) flushPWSWindow: (SGPWSWindow *) window;

- (SGRect) screenBounds;


- (BOOL) renderTextureBackedLayer: (id<SGTextureBackedLayer>) layer;

- (void) updateDisplay;

- (void) setAcceleration: (double) accelX: (double) accelY : (double) accelZ;
- (void) getAcceleration: (double *) accelXRet: (double *) accelYRet : (double *) accelZRet;

- (void) getAcceleration: (double *) accelXRet: (double *) accelYRet :(double *) accelZRet isChanged: (BOOL *) isChanged;


-(void) writeAudioPlaybackEndPipe;


@end

@interface NSObject (SGPWSWindowDelegate)
- (void) pwsWindowWillClose: (SGPWSWindow *) sender;
- (void) pwsWindowBecomeActive: (SGPWSWindow *) sender;
- (void) pwsWindowResignActive: (SGPWSWindow *) sender;
- (void) pwsWindowWillTerminate: (SGPWSWindow *) sender;
@end

@protocol SGTextureBackedLayer
@end


