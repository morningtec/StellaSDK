/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVFont.h"
@class UIFont;
/* Compatibility */






/* Prototypes */
typedef enum {
        UILineBreakModeWordWrap = 0,
        UILineBreakModeCharacterWrap,
        UILineBreakModeClip,
        UILineBreakModeHeadTruncation,
        UILineBreakModeTailTruncation,
        UILineBreakModeMiddleTruncation,
} UILineBreakMode;

typedef enum {
        UITextAlignmentLeft,
        UITextAlignmentCenter,
        UITextAlignmentRight,
} UITextAlignment;

typedef enum {
        UIBaselineAdjustmentAlignBaselines,
        UIBaselineAdjustmentAlignCenters,
        UIBaselineAdjustmentNone,
} SVBaselineAdjustment;



@interface NSString (SVStringDrawing)

- (CGSize) sizeWithFont: (UIFont *) font;

- (CGSize) sizeWithFont: (UIFont *) font constrainedToSize: (CGSize) size;
- (CGSize) sizeWithFont: (UIFont *) font constrainedToSize: (CGSize) size lineBreakMode: (UILineBreakMode) lineBreakMode;


- (CGSize) drawInRect: (CGRect) rect withFont: (UIFont *) font;
- (CGSize) drawInRect: (CGRect) rect withFont: (UIFont *) font lineBreakMode: (UILineBreakMode) lineBreakMode;
- (CGSize) drawInRect: (CGRect) rect withFont: (UIFont *) font lineBreakMode: (UILineBreakMode) lineBreakMode alignment: (UITextAlignment) alignment;


@end

