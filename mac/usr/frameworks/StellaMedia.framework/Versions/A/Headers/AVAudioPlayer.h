/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "AVFoundationExport.h"
#import <Foundation/Foundation.h>

@protocol AVAudioPlayerDelegate;
@interface AVAudioPlayer : NSObject
{
}

@property (readonly, getter=isPlaying) BOOL         playing;
@property float                                     volume;
@property float                                     pan;
@property NSInteger                                 numberOfLoops;
@property (assign) id<AVAudioPlayerDelegate>        delegate;

@property (readonly) NSUInteger                     numberOfChannels;
@property (readonly) NSTimeInterval                 duration;
@property NSTimeInterval                            currentTime;
@property (readonly) NSTimeInterval                 deviceCurrentTime; 
@property (readonly) NSURL                        * url;
@property (readonly) NSData                       * data;

@property (getter=isMeteringEnabled) BOOL           meteringEnabled;


- (id) initWithContentsOfURL: (NSURL *) theUrl error: (NSError **) outError;
- (id) initWithData: (NSData *) theData error: (NSError **) outError;

- (BOOL) play;	 
- (BOOL) playAtTime: (NSTimeInterval) time; 
- (void) pause;	
- (void) stop;	
- (BOOL) prepareToPlay;	

- (float) averagePowerForChannel: (NSUInteger) channelNumber; 
- (float) peakPowerForChannel: (NSUInteger) channelNumber;
- (void) updateMeters; 

@end



@protocol AVAudioPlayerDelegate <NSObject>
@optional 
- (void) audioPlayerDidFinishPlaying: (AVAudioPlayer *) player successfully: (BOOL) flag;
- (void) audioPlayerDecodeErrorDidOccur: (AVAudioPlayer *) player error: (NSError *) error;
@end



