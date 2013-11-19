/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVControl.h"
#import "SVGeometry.h"

@class UIImageView;

typedef enum {
        UIButtonTypeCustom              = 0,
        UIButtonTypeSystem,
        UIButtonTypeDetailDisclosure,
        UIButtonTypeInfoLight,
        UIButtonTypeInfoDark,
        UIButtonTypeContactAdd,
        UIButtonTypeRoundedRect
} UIButtonType;

@class UIColor;
@class UIImage;
@class UILabel;

@interface UIButton : UIControl
{
}

@property(nonatomic,readonly,retain) UILabel              * titleLabel;
@property(nonatomic) BOOL                                   reversesTitleShadowWhenHighlighted;

@property(nonatomic) BOOL                                   adjustsImageWhenHighlighted;
@property(nonatomic) BOOL                                   adjustsImageWhenDisabled;
@property(nonatomic) BOOL                                   showsTouchWhenHighlighted;
@property(nonatomic, retain) UIColor                      * tintColor;

@property(nonatomic) UIEdgeInsets                           contentEdgeInsets;
@property(nonatomic) UIEdgeInsets                           titleEdgeInsets;
@property(nonatomic) UIEdgeInsets                           imageEdgeInsets;

@property(nonatomic, readonly) UIButtonType                 buttonType;
@property(nonatomic, readonly, retain) NSString           * currentTitle;
@property(nonatomic, readonly, retain) NSAttributedString * currentAttributedTitle;
@property(nonatomic, readonly, retain) UIColor            * currentTitleColor;
@property(nonatomic, readonly, retain) UIColor            * currentTitleShadowColor;
@property(nonatomic, readonly, retain) UIImage            * currentImage;
@property(nonatomic, readonly, retain) UIImage            * currentBackgroundImage;
@property(nonatomic, readonly, retain) UIImageView        * imageView;


+ (id) buttonWithType: (UIButtonType) buttonType;

- (void) setTitle: (NSString *) title forState: (UIControlState) state;
- (void) setAttributedTitle: (NSAttributedString *) title forState: (UIControlState) state;
- (void) setTitleColor: (UIColor *) color forState: (UIControlState) state;
- (void) setTitleShadowColor: (UIColor *) color forState: (UIControlState) state;
- (UIColor *) titleColorForState: (UIControlState) state;
- (NSString *) titleForState: (UIControlState) state;
- (NSAttributedString *) attributedTitleForState: (UIControlState) state;
- (UIColor *) titleShadowColorForState: (UIControlState) state;

- (UIImage *) backgroundImageForState: (UIControlState) state;
- (UIImage *) imageForState: (UIControlState) state;
- (void) setBackgroundImage: (UIImage *) image forState: (UIControlState) state;
- (void) setImage: (UIImage *) image forState: (UIControlState) state;

- (NSString *) currentTitle;
- (UIColor *) currentTitleColor;
- (UIColor *) currentTitleShadowColor;
- (UIImage *) currentImage;
- (UIImage *) currentBackgroundImage;

- (CGRect) backgroundRectForBounds: (CGRect) bounds;
- (CGRect) contentRectForBounds: (CGRect) bounds;
- (CGRect) titleRectForContentRect: (CGRect) contentRect;
- (CGRect) imageRectForContentRect: (CGRect) contentRect;

@end


