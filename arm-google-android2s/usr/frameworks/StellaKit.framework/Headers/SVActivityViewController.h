/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVViewController.h"


typedef void (^UIActivityViewControllerCompletionHandler)(NSString *activityType, BOOL completed);

@interface UIActivityViewController : UIViewController

- (id) initWithActivityItems: (NSArray *) activityItems applicationActivities: (NSArray *) applicationActivities;
@property(nonatomic,copy) UIActivityViewControllerCompletionHandler completionHandler;
@property(nonatomic,copy) NSArray *excludedActivityTypes;

@end
