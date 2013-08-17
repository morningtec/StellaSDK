/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import "StellaKitExport.h"
#import "SVView.h"


extern NSString *const UIWindowDidBecomeVisibleNotification;
extern NSString *const UIWindowDidBecomeHiddenNotification;
extern NSString *const UIWindowDidBecomeKeyNotification;
extern NSString *const UIWindowDidResignKeyNotification;

extern NSString *const UIKeyboardWillShowNotification;
extern NSString *const UIKeyboardDidShowNotification;
extern NSString *const UIKeyboardWillHideNotification;
extern NSString *const UIKeyboardDidHideNotification;

extern NSString *const UIKeyboardFrameBeginUserInfoKey;
extern NSString *const UIKeyboardFrameEndUserInfoKey;
extern NSString *const UIKeyboardAnimationDurationUserInfoKey;
extern NSString *const UIKeyboardAnimationCurveUserInfoKey;

// deprecated
extern NSString *const UIKeyboardCenterBeginUserInfoKey;
extern NSString *const UIKeyboardCenterEndUserInfoKey;
extern NSString *const UIKeyboardBoundsUserInfoKey;

/* Prototypes */
@interface UIWindow : UIView
{
}

@property(nonatomic, retain) UIScreen             * screen;
@property(nonatomic, retain) UIViewController     * rootViewController;

- (void) makeKeyAndVisible;

- (CGPoint) convertPoint: (CGPoint) point toWindow: (UIWindow *) window;
- (CGPoint) convertPoint: (CGPoint) point fromWindow: (UIWindow *) window;
- (CGRect) convertRect: (CGRect) point toWindow: (UIWindow *) window;
- (CGRect) convertRect: (CGRect) point fromWindow: (UIWindow *) window;

@end

