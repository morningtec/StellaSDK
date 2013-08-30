/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"


@class UITextRange;

@interface UITextSelectionRect : NSObject

@property (nonatomic, readonly) CGRect                rect;
@property (nonatomic, readonly) UITextRange         * range;


@end
