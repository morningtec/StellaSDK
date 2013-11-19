/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

@interface UITextInputMode : NSObject
{
}

@property(nonatomic, readonly, retain) NSString       * primaryLanguage;

+ (UITextInputMode *) currentInputMode;
+ (NSArray *) activeInputModes;

@end

@interface UITextPosition : NSObject
{
}

@end


@interface UITextRange : NSObject
{
}

@property(nonatomic, readonly) UITextPosition           * start;
@property(nonatomic, readonly) UITextPosition           * end;
@property(nonatomic, readonly, getter=isEmpty) BOOL       empty;

@end
