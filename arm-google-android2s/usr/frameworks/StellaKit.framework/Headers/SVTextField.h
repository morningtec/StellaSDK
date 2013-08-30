/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVTextInputTraits.h"
#import "SVControl.h"
#import "SVFont.h"
#import "SVColor.h"
#import "SVImage.h"
#import "SVView.h"

typedef enum {
        UITextBorderStyleNone,
        UITextBorderStyleLine,
        UITextBorderStyleBezel,
        UITextBorderStyleRoundedRect
} UITextBorderStyle;

typedef enum {
        UITextFieldViewModeNever,
        UITextFieldViewModeWhileEditing,
        UITextFieldViewModeUnlessEditing,
        UITextFieldViewModeAlways
} UITextFieldViewMode;

@protocol UITextFieldDelegate;
@interface UITextField : UIControl<UITextInputTraits>

@property(nonatomic, copy) NSString                           * text;
@property(nonatomic,copy) NSAttributedString                  * attributedText;
@property(nonatomic, copy) NSString                           * placeholder;
@property(nonatomic,copy) NSAttributedString                  * attributedPlaceholder;
@property(nonatomic, retain) UIFont                           * font;
@property(nonatomic, retain) UIColor                          * textColor;
@property(nonatomic,copy) NSDictionary                        * typingAttributes;

@property(nonatomic) BOOL                                       adjustsFontSizeToFitWidth;
@property(nonatomic) CGFloat                                    minimumFontSize;

@property(nonatomic, readonly, getter=isEditing) BOOL           editing;
@property(nonatomic) BOOL                                       clearsOnBeginEditing;
@property(nonatomic) BOOL                                       clearsOnInsertion;
@property(nonatomic) BOOL                                       allowsEditingTextAttributes;

@property(nonatomic) UITextBorderStyle                          borderStyle;
@property(nonatomic, retain) UIImage                          * background;
@property(nonatomic, retain) UIImage                          * disabledBackground;

@property(nonatomic) UITextFieldViewMode                        clearButtonMode;
@property(nonatomic, retain) UIView                           * leftView;
@property(nonatomic) UITextFieldViewMode                        leftViewMode;
@property(nonatomic, retain) UIView                           * rightView;
@property(nonatomic) UITextFieldViewMode                        rightViewMode;

@property(nonatomic, assign) id<UITextFieldDelegate>            delegate;

@property(readwrite, retain) UIView                           * inputView;
@property(readwrite, retain) UIView                           * inputAccessoryView;


- (CGRect) textRectForBounds: (CGRect) bounds;
- (void) drawTextInRect: (CGRect) rect;
- (CGRect) placeholderRectForBounds: (CGRect) bounds;
- (void) drawPlaceholderInRect: (CGRect) rect;
- (CGRect) borderRectForBounds: (CGRect) bounds;
- (CGRect) editingRectForBounds: (CGRect) bounds;
- (CGRect) clearButtonRectForBounds: (CGRect) bounds;
- (CGRect) leftViewRectForBounds: (CGRect) bounds;
- (CGRect) rightViewRectForBounds: (CGRect) bounds;

@end


@protocol UITextFieldDelegate <NSObject>
@optional
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;
- (void)textFieldDidBeginEditing:(UITextField *)textField;
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;
- (void)textFieldDidEndEditing:(UITextField *)textField;

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange: (NSRange) range replacementString: (NSString *) string;
- (BOOL)textFieldShouldClear:(UITextField *)textField;
- (BOOL)textFieldShouldReturn:(UITextField *)textField;
@end





