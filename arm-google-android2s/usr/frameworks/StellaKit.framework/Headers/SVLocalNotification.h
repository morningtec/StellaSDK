/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"


@interface UILocalNotification : NSObject

@property(nonatomic, copy) NSDate               * fireDate;
@property(nonatomic, copy) NSTimeZone           * timeZone;
@property(nonatomic) NSCalendarUnit               repeatInterval;
@property(nonatomic, copy) NSCalendar           * repeatCalendar;
@property(nonatomic, copy) NSString             * alertBody;
@property(nonatomic, copy) NSString             * alertAction;
@property(nonatomic) BOOL                         hasAction;
@property(nonatomic,copy) NSString              * alertLaunchImage;
@property(nonatomic) NSInteger                    applicationIconBadgeNumber;
@property(nonatomic, copy) NSString             * soundName;
@property(nonatomic, copy) NSDictionary         * userInfo;

@end
