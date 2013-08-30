/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVPopoverController.h"
#import "SVGeometry.h"


@interface UIPopoverBackgroundView : NSObject

@property(nonatomic, readwrite) CGFloat                     arrowOffset;
@property(nonatomic, readwrite) UIPopoverArrowDirection     arrowDirection;

+ (BOOL) wantsDefaultContentAppearance;
+ (CGFloat) arrowHeight;
+ (CGFloat) arrowBase;
+ (UIEdgeInsets) contentViewInsets;

@end
