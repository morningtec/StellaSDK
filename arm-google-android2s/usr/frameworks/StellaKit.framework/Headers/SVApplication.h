/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVDevice.h"
#import "SVResponder.h"
#import "SVTouch.h"
#import "SVLocalNotification.h"

/* Apple-begin */
@class UIImage;
/* Apple-end */

/* Compatibility */
#if defined (__ANDROID__)
#define main            main_android
#define main_handroid   main_android
#define main_nandroid   main_android
#endif


#if defined (__STELLA_WEBOS_PDK)
#define main            main_webos
#endif

/* Prototypes */
typedef enum {
        UIInterfaceOrientationPortrait           = UIDeviceOrientationPortrait,
        UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
        UIInterfaceOrientationLandscapeLeft      = UIDeviceOrientationLandscapeRight,
        UIInterfaceOrientationLandscapeRight     = UIDeviceOrientationLandscapeLeft
} UIInterfaceOrientation;

typedef enum {
        UIStatusBarStyleDefault,
        UIStatusBarStyleBlackTranslucent,
        UIStatusBarStyleBlackOpaque,
} UIStatusBarStyle;


#define UIInterfaceOrientationIsPortrait(orientation) (\
    (orientation) == UIInterfaceOrientationPortrait || \
    (orientation) == UIInterfaceOrientationPortraitUpsideDown )

#define UIInterfaceOrientationIsLandscape(orientation) (\
    (orientation) == UIInterfaceOrientationLandscapeLeft || \
    (orientation) == UIInterfaceOrientationLandscapeRight )


STELLA_KIT_EXPORT NSString * const      UIApplicationDidBecomeActiveNotification;
STELLA_KIT_EXPORT NSString * const      UIApplicationWillResignActiveNotification;


typedef enum {
        UIRemoteNotificationTypeNone    = 0,
        UIRemoteNotificationTypeBadge   = 1 << 0,
        UIRemoteNotificationTypeSound   = 1 << 1,
        UIRemoteNotificationTypeAlert   = 1 << 2,
        UIRemoteNotificationTypeNewsstandContentAvailability = 1 << 3
} UIRemoteNotificationType;

typedef enum {
        UIApplicationStateActive,
        UIApplicationStateInactive,
        UIApplicationStateBackground
} UIApplicationState;


typedef NSUInteger UIBackgroundTaskIdentifier;


typedef enum {
        UIStatusBarAnimationNone,
        UIStatusBarAnimationFade,
        UIStatusBarAnimationSlide,
} UIStatusBarAnimation;


typedef enum {
        UIUserInterfaceLayoutDirectionLeftToRight,
        UIUserInterfaceLayoutDirectionRightToLeft,
} UIUserInterfaceLayoutDirection;

@protocol UIApplicationDelegate;
@interface UIApplication : UIResponder
{
}

@property(nonatomic, assign) id<UIApplicationDelegate>          delegate;

@property(nonatomic, readonly) UIWindow                       * keyWindow;
@property(nonatomic, readonly) NSArray                        * windows;


@property(nonatomic, getter=isStatusBarHidden) BOOL             statusBarHidden;
@property(nonatomic) UIStatusBarStyle                           statusBarStyle;
@property(nonatomic, readonly) CGRect                           statusBarFrame;

@property(nonatomic, assign) BOOL                               idleTimerDisabled;


@property(nonatomic) BOOL                                                 applicationSupportsShakeToEdit;
@property(nonatomic, getter=isProximitySensingEnabled) BOOL               proximitySensingEnabled;
@property(nonatomic, readonly) UIApplicationState                         applicationState;
@property(nonatomic, readonly) NSTimeInterval                             backgroundTimeRemaining;
@property(nonatomic, copy) NSArray                                      * scheduledLocalNotifications;
@property(nonatomic, readonly, getter=isProtectedDataAvailable) BOOL      protectedDataAvailable;
@property(nonatomic) UIInterfaceOrientation                               statusBarOrientation;
@property(nonatomic, readonly) NSTimeInterval                             statusBarOrientationAnimationDuration;
@property(nonatomic, getter=isNetworkActivityIndicatorVisible) BOOL       networkActivityIndicatorVisible;
@property(nonatomic) NSInteger                                            applicationIconBadgeNumber;
@property(nonatomic, readonly) UIUserInterfaceLayoutDirection             userInterfaceLayoutDirection;

#pragma mark -
+ (UIApplication *) sharedApplication;

- (void) sendEvent: (UIEvent *) event;
- (BOOL) sendAction: (SEL) action to: (id) target from: (id) sender forEvent: (UIEvent *) event;

- (BOOL) openURL: (NSURL *) url;
- (BOOL) canOpenURL: (NSURL *) url;
#pragma mark - Dummy function ref: Apple

- (NSUInteger) supportedInterfaceOrientationsForWindow: (UIWindow *) window;
- (void) beginIgnoringInteractionEvents;
- (void) endIgnoringInteractionEvents;
- (void) registerForRemoteNotificationTypes: (UIRemoteNotificationType) types;
- (void) unregisterForRemoteNotifications;
- (UIRemoteNotificationType) enabledRemoteNotificationTypes;

- (UIBackgroundTaskIdentifier) beginBackgroundTaskWithExpirationHandler: (void (^)(void)) handler;
- (void) endBackgroundTask: (UIBackgroundTaskIdentifier) identifier;
- (BOOL) setKeepAliveTimeout: (NSTimeInterval) timeout handler: (void (^)(void)) keepAliveHandler;
- (void) clearKeepAliveTimeout;
- (void) extendStateRestoration;
- (void) completeStateRestoration;
- (void) scheduleLocalNotification: (UILocalNotification *) notification;
- (void) presentLocalNotificationNow: (UILocalNotification *) notification;
- (void) cancelLocalNotification: (UILocalNotification *) notification;
- (void) cancelAllLocalNotifications;
- (void) beginReceivingRemoteControlEvents;
- (void) endReceivingRemoteControlEvents;
- (void) setStatusBarOrientation: (UIInterfaceOrientation) interfaceOrientation animated: (BOOL) animated;
- (void) setStatusBarHidden: (BOOL) hidden withAnimation: (UIStatusBarAnimation) animation;
- (void) setStatusBarStyle: (UIStatusBarStyle) statusBarStyle animated: (BOOL) animated;
- (void) setNewsstandIconImage: (UIImage *) image;
- (BOOL) isIgnoringInteractionEvents;

@end




@protocol UIApplicationDelegate <NSObject>
@optional
- (BOOL) application: (UIApplication *) application didFinishLaunchingWithOptions: (NSDictionary *) launchOptions;
- (void) applicationDidFinishLaunching: (UIApplication *) application;
- (void) applicationDidBecomeActive: (UIApplication *) application;
- (void) applicationWillResignActive: (UIApplication *) application;
- (void) applicationWillTerminate: (UIApplication *) application;

- (BOOL) application: (UIApplication *) application willFinishLaunchingWithOptions: (NSDictionary *) launchOptions;
- (void) applicationDidEnterBackground: (UIApplication *) application;
- (void) applicationWillEnterForeground: (UIApplication *) application;
- (BOOL) application: (UIApplication *) application shouldSaveApplicationState: (NSCoder *) coder;
- (BOOL) application: (UIApplication *) application shouldRestoreApplicationState: (NSCoder *) coder;
- (UIViewController *) application: (UIApplication *) application viewControllerWithRestorationIdentifierPath: (NSArray *) identifierComponents coder: (NSCoder *) coder;
- (void) application: (UIApplication *) application willEncodeRestorableStateWithCoder: (NSCoder *) coder;
- (void) application: (UIApplication *) application didDecodeRestorableStateWithCoder: (NSCoder *) coder;
- (BOOL) application: (UIApplication *) application openURL: (NSURL *) url sourceApplication: (NSString *) sourceApplication annotation: (id) annotation;
- (BOOL) application: (UIApplication *) application handleOpenURL: (NSURL *) url;
- (void) application: (UIApplication *) application willChangeStatusBarOrientation: (UIInterfaceOrientation) newStatusBarOrientation duration: (NSTimeInterval) duration;
- (void) application: (UIApplication *) application didChangeStatusBarOrientation: (UIInterfaceOrientation) oldStatusBarOrientation;
- (void) application: (UIApplication *) application willChangeStatusBarFrame: (CGRect) newStatusBarFrame;
- (void) application: (UIApplication *) application didChangeStatusBarFrame: (CGRect) oldStatusBarFrame;
- (void) applicationDidReceiveMemoryWarning: (UIApplication *) application;
- (void) applicationSignificantTimeChange: (UIApplication *) application;
- (void) application: (UIApplication *) application didReceiveRemoteNotification: (NSDictionary *) userInfo;
- (void) application: (UIApplication *) application didRegisterForRemoteNotificationsWithDeviceToken: (NSData *) deviceToken;
- (void) application: (UIApplication *) application didFailToRegisterForRemoteNotificationsWithError: (NSError *) error;
- (void) application: (UIApplication *) application didReceiveLocalNotification: (UILocalNotification *) notification;
- (void) applicationProtectedDataWillBecomeUnavailable: (UIApplication *) application;
- (void) applicationProtectedDataDidBecomeAvailable: (UIApplication *) application;

@end



/* functions */
STELLA_KIT_EXPORT int UIApplicationMain (int argc, char * argv[], NSString * principleClassName, NSString * delegateClassName);

