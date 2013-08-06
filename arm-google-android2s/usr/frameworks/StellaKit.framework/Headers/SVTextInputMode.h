//
//  SVTextInputMode.h
//  StellaKit-android2s
//
//  Created by ymm on 13-2-17.
//
//

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

#define UITextInputMode             SVTextInputMode

@interface SVTextInputMode : NSObject

+ (SVTextInputMode *) currentInputMode;
+ (NSArray *) activeInputModes;
@property (nonatomic, readonly, retain) NSString * primaryLanguage;


@end
