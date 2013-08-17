/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "SVStringDrawing.h"
#import "SVScrollView.h"
#import "SVDataDetectors.h"
#import "SVTextInputTraits.h"

extern NSString *const UITextViewTextDidBeginEditingNotification;
extern NSString *const UITextViewTextDidChangeNotification;
extern NSString *const UITextViewTextDidEndEditingNotification;

@class UIColor, UIFont, UITextLayer, UITextView;

@protocol UITextViewDelegate <NSObject, UIScrollViewDelegate>
@optional
- (BOOL) textViewShouldBeginEditing: (UITextView *) textView;
- (void) textViewDidBeginEditing: (UITextView *) textView;
- (BOOL) textViewShouldEndEditing: (UITextView *) textView;
- (void) textViewDidEndEditing: (UITextView *) textView;
- (BOOL) textView: (UITextView *) textView shouldChangeTextInRange:(NSRange) range replacementText:(NSString *) text;
- (void) textViewDidChange: (UITextView *) textView;
- (void) textViewDidChangeSelection: (UITextView *) textView;
@end

@interface UITextView : UIScrollView <NSCoding, UITextInputTraits>

- (void)scrollRangeToVisible: (NSRange) range;


@property (nonatomic) UITextAlignment   textAlignment; // stub, not yet implemented!
@property (nonatomic) NSRange           selectedRange;
@property (nonatomic, getter=isEditable) BOOL editable;
@property (nonatomic, copy) NSString      * text;
@property (nonatomic, retain) UIColor     * textColor;
@property (nonatomic, retain) UIFont      * font;
@property (nonatomic) UIDataDetectorTypes   dataDetectorTypes;
@property (nonatomic, assign) id<UITextViewDelegate>    delegate;

@property (nonatomic, readwrite, retain) UIView       * inputAccessoryView;
@property (nonatomic, readwrite, retain) UIView       * inputView;

- (BOOL)hasText;

@end
