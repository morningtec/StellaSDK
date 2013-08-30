/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVColor.h"
#import "SVImage.h"
#import "SVInterface.h"
#import "SVBarButtonItem.h"

typedef enum {
        UIToolbarPositionAny        = 0,
        UIToolbarPositionBottom     = 1,
        UIToolbarPositionTop        = 2,
} UIToolbarPosition;


@interface UIToolbar : NSObject

@property(nonatomic) UIBarStyle barStyle;
@property(nonatomic, assign, getter=isTranslucent) BOOL translucent;
@property(nonatomic, copy) NSArray *items;
@property(nonatomic, retain) UIColor *tintColor;

- (void) setItems: (NSArray *) items animated: (BOOL) animated;
- (UIImage *) backgroundImageForToolbarPosition: (UIToolbarPosition) topOrBottom barMetrics: (UIBarMetrics) barMetrics;
- (void) setBackgroundImage: (UIImage *) backgroundImage forToolbarPosition: (UIToolbarPosition) topOrBottom barMetrics: (UIBarMetrics) barMetrics;
- (UIImage *) shadowImageForToolbarPosition: (UIToolbarPosition) topOrBottom;
- (void) setShadowImage: (UIImage *) shadowImage forToolbarPosition: (UIToolbarPosition) topOrBottom;

@end
