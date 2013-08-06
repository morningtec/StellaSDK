//
//  SVTextRange.h
//  StellaKit-android2s
//
//  Created by ymm on 13-2-17.
//
//

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

#define UITextRange         SVTextRange


@class SVTextPosition;
@interface SVTextRange : NSObject

@property(nonatomic, readonly) SVTextPosition           * start;
@property(nonatomic, readonly) SVTextPosition           * end;
@property(nonatomic, readonly, getter=isEmpty) BOOL       empty;
@end