/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVResponder.h"
#import "SVEvent.h"

/* Compatibility */



/* Prototypes */
@class UIEvent;
@interface UIResponder : NSObject <NSCoding>
{
}

@property(readonly, retain) UIView    * inputView;
@property(readonly, retain) UIView    * inputAccessoryView;
@property(readonly) NSUndoManager     * undoManager;

- (UIResponder *) nextResponder;
- (BOOL) isFirstResponder;
- (BOOL) canBecomeFirstResponder;
- (BOOL) becomeFirstResponder;
- (BOOL) canResignFirstResponder;
- (BOOL) resignFirstResponder;

- (void) reloadInputViews;

- (void) touchesBegan: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesMoved: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesEnded: (NSSet *) touches withEvent: (UIEvent *) event;
- (void) touchesCancelled: (NSSet *) touches withEvent: (UIEvent *) event;

- (void) motionBegan: (UIEventSubtype) motion withEvent: (UIEvent *) event;
- (void) motionEnded: (UIEventSubtype) motion withEvent: (UIEvent *) event;
- (void) motionCancelled: (UIEventSubtype) motion withEvent: (UIEvent *) event;

- (void) remoteControlReceivedWithEvent: (UIEvent *) event;

- (BOOL) canPerformAction: (SEL) action withSender: (id) sender;

@end

