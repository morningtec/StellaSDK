/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVImage.h"
#import "SVGeometry.h"
#import "SVImage.h"
#import "SVControl.h"



@interface UIBarItem : NSObject

@property(nonatomic, getter=isEnabled) BOOL     enabled;
@property(nonatomic, retain) UIImage          * image;
@property(nonatomic, retain) UIImage          * landscapeImagePhone;
@property(nonatomic) UIEdgeInsets               imageInsets;
@property(nonatomic) UIEdgeInsets               landscapeImagePhoneInsets;
@property(nonatomic, copy) NSString           * title;
@property(nonatomic) NSInteger                  tag;

- (void) setTitleTextAttributes: (NSDictionary *) attributes forState: (UIControlState) state;
- (NSDictionary *) titleTextAttributesForState: (UIControlState)state;

@end
