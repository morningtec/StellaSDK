/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVImage.h"



STELLA_KIT_EXPORT CGContextRef UIGraphicsGetCurrentContext ();
STELLA_KIT_EXPORT void         UIGraphicsPopContext ();
STELLA_KIT_EXPORT void         UIGraphicsPushContext (CGContextRef ctx);

STELLA_KIT_EXPORT void         UIGraphicsBeginImageContext (CGSize size);
STELLA_KIT_EXPORT void         UIGraphicsBeginImageContextWithOptions (CGSize size, BOOL opaque, CGFloat scale);
STELLA_KIT_EXPORT UIImage    * UIGraphicsGetImageFromCurrentImageContext ();
STELLA_KIT_EXPORT void         UIGraphicsEndImageContext ();

