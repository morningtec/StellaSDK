/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"

@class UITextField;

typedef enum {
        UIAlertViewStyleDefault                 = 0,
        UIAlertViewStyleSecureTextInput,
        UIAlertViewStylePlainTextInput,
        UIAlertViewStyleLoginAndPasswordInput
} UIAlertViewStyle;

@protocol UIAlertViewDelegate;
@interface UIAlertView : UIView
{
}

- (id) initWithTitle: (NSString *) title
             message: (NSString *) message
            delegate: (id) delegate
   cancelButtonTitle: (NSString *) cancelButtonTitle
   otherButtonTitles: (NSString *) otherButtonTitles, ...;

- (void) show;

@property(nonatomic, assign) id delegate;
@property(nonatomic, assign) UIAlertViewStyle alertViewStyle;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *message;
@property(nonatomic, readonly, getter=isVisible) BOOL visible;
- (NSInteger) addButtonWithTitle: (NSString *) title;
@property(nonatomic, readonly) NSInteger numberOfButtons;
- (NSString *) buttonTitleAtIndex: (NSInteger) buttonIndex;
- (UITextField *) textFieldAtIndex: (NSInteger) textFieldIndex;
@property(nonatomic) NSInteger cancelButtonIndex;
@property(nonatomic, readonly) NSInteger firstOtherButtonIndex;
- (void) dismissWithClickedButtonIndex: (NSInteger) buttonIndex animated: (BOOL) animated;
/* Apple-begin */
- (id) initWithTitle: (NSString *) title message: (NSString *) message delegate: (id) delegate cancelButtonTitle: (NSString *) cancelButtonTitle otherButtonTitles: (NSString *) otherButtonTitles, ...;
/* Apple-end */
@end


@protocol UIAlertViewDelegate <NSObject>
@optional
- (void) alertView: (UIAlertView *) alertView clickedButtonAtIndex: (NSInteger) buttonIndex;

- (void) willPresentAlertView: (UIAlertView *) alertView;
- (void) didPresentAlertView: (UIAlertView *) alertView;
- (void) alertView: (UIAlertView *) alertView willDismissWithButtonIndex: (NSInteger) buttonIndex;
- (void) alertView: (UIAlertView *) alertView didDismissWithButtonIndex: (NSInteger) buttonIndex;

- (void) alertViewCancel: (UIAlertView *) alertView;
@end



