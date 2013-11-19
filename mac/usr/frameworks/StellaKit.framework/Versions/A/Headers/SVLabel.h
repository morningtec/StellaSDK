/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVStringDrawing.h"

@class UIFont, UIColor;

@interface UILabel : UIView
{
}

@property(nonatomic, copy) NSString                       * text;
@property(nonatomic,copy) NSAttributedString              * attributedText;
@property(nonatomic, retain) UIFont                       * font;
@property(nonatomic, retain) UIColor                      * textColor;
@property(nonatomic) UITextAlignment                        textAlignment;
@property(nonatomic) UILineBreakMode                        lineBreakMode;
@property(nonatomic, getter=isEnabled) BOOL                 enabled;

@property(nonatomic) BOOL                                   adjustsFontSizeToFitWidth;
@property(nonatomic) BOOL                                   adjustsLetterSpacingToFitWidth;
@property(nonatomic) SVBaselineAdjustment                   baselineAdjustment;
@property(nonatomic) CGFloat                                minimumScaleFactor;
@property(nonatomic) CGFloat                                minimumFontSize;
@property(nonatomic) NSInteger                              numberOfLines;

@property(nonatomic, retain) UIColor                      * highlightedTextColor;
@property(nonatomic, getter=isHighlighted) BOOL             highlighted;

@property(nonatomic, retain) UIColor                      * shadowColor;
@property(nonatomic) CGSize                                 shadowOffset;

@property(nonatomic, getter=isUserInteractionEnabled) BOOL  userInteractionEnabled;

@property(nonatomic) CGFloat                                preferredMaxLayoutWidth;

@end



