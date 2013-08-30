/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import "StellaKitExport.h"

typedef enum {
        UIDeviceBatteryStateUnknown,
        UIDeviceBatteryStateUnplugged,
        UIDeviceBatteryStateCharging,
        UIDeviceBatteryStateFull,
} UIDeviceBatteryState;
@class NSUUID;

typedef enum {
        UIDeviceOrientationUnknown,
        UIDeviceOrientationPortrait,
        UIDeviceOrientationPortraitUpsideDown,
        UIDeviceOrientationLandscapeLeft,
        UIDeviceOrientationLandscapeRight,
        UIDeviceOrientationFaceUp,
        UIDeviceOrientationFaceDown
} UIDeviceOrientation;

typedef enum {
        UIUserInterfaceIdiomPhone,
        UIUserInterfaceIdiomPad,
        UIUserInterfaceIdiomFullScreen,
} UIUserInterfaceIdiom;


/* Prototypes */
#define UI_USER_INTERFACE_IDIOM() ( \
        [[UIDevice currentDevice] respondsToSelector: @selector(userInterfaceIdiom)] ? \
        [[UIDevice currentDevice] userInterfaceIdiom] : \
        UIUserInterfaceIdiomPhone )

@interface UIDevice : NSObject

@property(readonly, nonatomic) NSString                           * systemVersion;

@property(nonatomic, readonly) UIUserInterfaceIdiom                 userInterfaceIdiom;

/* Apple-begin */
@property(nonatomic, readonly) BOOL                                                         proximityState;
@property(nonatomic, readonly) float                                                        batteryLevel;
@property(nonatomic, readonly) UIDeviceOrientation                                          orientation;
@property(nonatomic, getter=isProximityMonitoringEnabled) BOOL                              proximityMonitoringEnabled;
@property(nonatomic, getter=isBatteryMonitoringEnabled) BOOL                                batteryMonitoringEnabled;
@property(nonatomic, readonly) UIDeviceBatteryState                                         batteryState;
@property(nonatomic, readonly, getter=isGeneratingDeviceOrientationNotifications) BOOL      generatesDeviceOrientationNotifications;
@property(nonatomic, readonly, retain) NSUUID                                             * identifierForVendor;
/* Apple-end */

+ (UIDevice *) currentDevice;

@end

