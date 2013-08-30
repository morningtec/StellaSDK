/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

@interface UIScreenMode : NSObject

@property(readonly,nonatomic) CGSize    size;
@property(readonly,nonatomic) CGFloat   pixelAspectRatio;

@end
