/*
 * Copyright (c) 2011 Yeecco Limited
 */
#import "AVFoundationExport.h"
#import <Foundation/Foundation.h>
#import <CoreFoundation/CFBase.h>

AV_FOUNDATION_EXPORT NSString * const     AVAudioSessionCategoryAmbient;
AV_FOUNDATION_EXPORT NSString * const     AVAudioSessionCategorySoloAmbient;
AV_FOUNDATION_EXPORT NSString * const     AVAudioSessionCategoryPlayback;
AV_FOUNDATION_EXPORT NSString * const     AVAudioSessionCategoryRecord;
AV_FOUNDATION_EXPORT NSString * const     AVAudioSessionCategoryPlayAndRecord;
AV_FOUNDATION_EXPORT NSString  *const     AVAudioSessionCategoryAudioProcessing;

enum {
	    AVAudioSessionInterruptionFlags_ShouldResume    = 1
};

enum {
	    AVAudioSessionSetActiveFlags_NotifyOthersOnDeactivation     = 1
};

enum AudioSessionProperties {
        kAudioSessionProperty_OtherAudioIsPlaying,
        kAudioSessionProperty_AudioRoute
};

@protocol AVAudioSessionDelegate;

@interface AVAudioSession : NSObject
{
}

@property(assign) id<AVAudioSessionDelegate>    delegate;

+ (id) sharedInstance;

- (BOOL) setActive: (BOOL) beActive error: (NSError**) outError;
- (BOOL) setCategory: (NSString *) theCategory error: (NSError **) outError;

@end


@protocol AVAudioSessionDelegate <NSObject>
@optional
- (void) beginInterruption;
- (void) endInterruptionWithFlags:(NSUInteger)flags;
- (void) endInterruption;
- (void) inputIsAvailableChanged:(BOOL)isInputAvailable;
@end

AV_FOUNDATION_EXPORT OSStatus AudioSessionGetProperty (UInt32 inID, UInt32 * ioDataSize, void * outData);


