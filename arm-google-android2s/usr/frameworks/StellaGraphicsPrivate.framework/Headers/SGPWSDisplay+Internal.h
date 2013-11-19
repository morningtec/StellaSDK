/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/SGGeometry.h>

#import "SGPWSWindow+Internal.h"

@class SGEvent;

@protocol SGTextureBackedLayer;

enum {
        SGInterfaceIdiomPhone,
        SGInterfaceIdiomPad,
        SGInterfaceIdiomFullScreen,
};
typedef NSUInteger      SGInterfaceIdiom;

enum {
        SGScreenBestEmulationMode,
        SGScreenIPhone3GEmulationMode,
};
typedef NSUInteger  SGScreenEmulationMode;



@interface SGPWSDisplay : NSObject
{
}

@property(nonatomic, readonly) SGInterfaceIdiom         userInterfaceIdiom;
@property(nonatomic, readonly) SGContext              * context;

@property(nonatomic, readonly) SGSize                   canvasSize;
@property(nonatomic, readonly) SGFloat                  dpi;


// @property(nonatomic, copy) NSString                   * publishingLicenceKey;

+ (SGScreenEmulationMode) screenEmulationMode;
+ (void) setScreenEmulationMode: (SGScreenEmulationMode) mode;

+ (SGPWSDisplay *) sharedDisplay;

- (SGEvent *) nextEventMatchingMask: (NSUInteger) mask  untilDate: (NSDate *) untilDate inMode: (NSString *) mode dequeue: (BOOL) dequeue;

- (SGPWSWindow *) allocPWSWindowWithFrame: (SGRect) frame;
- (void) deallocPWSWindow: (SGPWSWindow *) window;
- (void) flushPWSWindow: (SGPWSWindow *) window;


- (BOOL) renderTextureBackedLayer: (id<SGTextureBackedLayer>) layer;

- (void) updateDisplay;

- (void) setAcceleration: (double) accelX : (double) accelY : (double) accelZ;
- (void) getAcceleration: (double *) accelXRet : (double *) accelYRet : (double *) accelZRet;

- (void) getAcceleration: (double *) accelXRet : (double *) accelYRet :(double *) accelZRet isChanged: (BOOL *) isChanged;


- (void) setPublishingLicenceKey: (NSString *) publishingLicenceKey;

- (void) writeAudioPlaybackEndPipe;

- (SGFloat) resolutionScale;
- (SGSize) deviceScreenSizePX;
- (SGRect) userScreenBoundsPT;

@end

@interface NSObject (SGPWSWindowDelegate)
- (void) pwsWindowWillClose: (SGPWSWindow *) sender;
- (void) pwsWindowBecomeActive: (SGPWSWindow *) sender;
- (void) pwsWindowResignActive: (SGPWSWindow *) sender;
- (void) pwsWindowWillTerminate: (SGPWSWindow *) sender;
@end

@protocol SGTextureBackedLayer
@end


