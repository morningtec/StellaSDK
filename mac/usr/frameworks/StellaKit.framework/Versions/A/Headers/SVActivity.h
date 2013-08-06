/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVViewController.h"
#import "SVImage.h"

/* Compatibility */

@interface UIActivity : NSObject

- (NSString *) activityType;
- (NSString *) activityTitle;
- (UIImage *) activityImage;
- (BOOL) canPerformWithActivityItems: (NSArray *) activityItems;
- (void) prepareWithActivityItems: (NSArray *) activityItems;
- (UIViewController *) activityViewController;
- (void) performActivity;
- (void) activityDidFinish: (BOOL) completed;

@end
