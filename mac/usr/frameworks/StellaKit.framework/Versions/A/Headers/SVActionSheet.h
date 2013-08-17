/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVTabBar.h"
#import "SVBarButtonItem.h"
#import "SVToolbar.h"

/* Compatibility */


/* Prototypes */

typedef enum {
    UIActionSheetStyleAutomatic        = -1,
    UIActionSheetStyleDefault          = UIBarStyleDefault,
    UIActionSheetStyleBlackTranslucent = UIBarStyleBlackTranslucent,
    UIActionSheetStyleBlackOpaque      = UIBarStyleBlackOpaque,
} UIActionSheetStyle;

@protocol UIActionSheetDelegate;
@interface UIActionSheet : UIView

@property(nonatomic, assign) id<UIActionSheetDelegate>      delegate;
@property(nonatomic, copy) NSString                       * title;
@property(nonatomic, readonly, getter=isVisible) BOOL       visible;
@property(nonatomic, assign) UIActionSheetStyle             actionSheetStyle;
@property(nonatomic, readonly) NSInteger                    numberOfButtons;
@property(nonatomic) NSInteger                              cancelButtonIndex;
@property(nonatomic) NSInteger                              destructiveButtonIndex;
@property(nonatomic, readonly) NSInteger                    firstOtherButtonIndex;

- (id) initWithTitle: (NSString *) title delegate: (id<UIActionSheetDelegate>) delegate cancelButtonTitle: (NSString *) cancelButtonTitle destructiveButtonTitle: (NSString *) destructiveButtonTitle otherButtonTitles: (NSString *) otherButtonTitles, ...;

- (void) showFromTabBar: (UITabBar *) view;
- (void) showFromToolbar: (UIToolbar *) view;
- (void) showInView: (UIView *) view;
- (void) showFromBarButtonItem: (UIBarButtonItem *) item animated: (BOOL) animated;
- (void) showFromRect: (CGRect) rect inView: (UIView *) view animated: (BOOL) animated;
- (void) dismissWithClickedButtonIndex: (NSInteger) buttonIndex animated: (BOOL) animated;

/* private initialisers */
- (id) copyWithZone: (NSZone *) zone;
- (id) init;
- (void) dealloc;

@end


@protocol UIActionSheetDelegate<NSObject>
@optional
- (void) actionSheet: (UIActionSheet *) actionSheet clickedButtonAtIndex: (NSInteger) buttonIndex;
- (void) willPresentActionSheet: (UIActionSheet *) actionSheet;
- (void) didPresentActionSheet: (UIActionSheet *) actionSheet;
- (void) actionSheet: (UIActionSheet *) actionSheet willDismissWithButtonIndex: (NSInteger) buttonIndex;
- (void) actionSheet: (UIActionSheet *) actionSheet didDismissWithButtonIndex: (NSInteger) buttonIndex;
- (void) actionSheetCancel: (UIActionSheet *) actionSheet;
@end
