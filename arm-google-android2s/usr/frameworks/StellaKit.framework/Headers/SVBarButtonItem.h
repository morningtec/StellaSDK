/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVButton.h"
#import "SVBarItem.h"
#import "SVInterface.h"
#import "SVControl.h"
#import "SVGeometry.h"

typedef enum {
        UIBarButtonSystemItemDone,
        UIBarButtonSystemItemCancel,
        UIBarButtonSystemItemEdit,
        UIBarButtonSystemItemSave,
        UIBarButtonSystemItemAdd,
        UIBarButtonSystemItemFlexibleSpace,
        UIBarButtonSystemItemFixedSpace,
        UIBarButtonSystemItemCompose,
        UIBarButtonSystemItemReply,
        UIBarButtonSystemItemAction,
        UIBarButtonSystemItemOrganize,
        UIBarButtonSystemItemBookmarks,
        UIBarButtonSystemItemSearch,
        UIBarButtonSystemItemRefresh,
        UIBarButtonSystemItemStop,
        UIBarButtonSystemItemCamera,
        UIBarButtonSystemItemTrash,
        UIBarButtonSystemItemPlay,
        UIBarButtonSystemItemPause,
        UIBarButtonSystemItemRewind,
        UIBarButtonSystemItemFastForward,
        UIBarButtonSystemItemUndo,
        UIBarButtonSystemItemRedo,
} UIBarButtonSystemItem;


typedef enum {
        UIBarButtonItemStylePlain,
        UIBarButtonItemStyleBordered,
        UIBarButtonItemStyleDone,
} UIBarButtonItemStyle;

typedef enum {
        UIBarMetricsDefault,
        UIBarMetricsLandscapePhone,
} UIBarMetrics;



@class UIColor;
@class UIView;
@class UIImage;
@class UIBarButtonItemButton;
@class SVFlippedView;


@interface UIBarButtonItem : UIBarItem

@property(nonatomic, assign) id                  target;
@property(nonatomic) SEL                         action;
@property(nonatomic) UIBarButtonItemStyle        style;
@property(nonatomic, copy) NSSet               * possibleTitles;
@property(nonatomic) CGFloat                     width;
@property(nonatomic, retain) UIView            * customView;

@property(nonatomic, retain) UIColor           * tintColor;


- (id) initWithBarButtonSystemItem: (UIBarButtonSystemItem) systemItem target: (id) target action: (SEL) action;
- (id) initWithCustomView: (UIView *) customView;
- (id) initWithImage: (UIImage *) image style: (UIBarButtonItemStyle) style target: (id) target action: (SEL) action;
- (id) initWithTitle: (NSString *) title style: (UIBarButtonItemStyle) style target: (id) target action: (SEL) action;
- (id) initWithImage: (UIImage *) image landscapeImagePhone: (UIImage *) landscapeImagePhone style: (UIBarButtonItemStyle) style target: (id) target action: (SEL) action;

- (UIImage *) backButtonBackgroundImageForState: (UIControlState) state barMetrics: (UIBarMetrics) barMetrics;
- (void) setBackButtonBackgroundImage: (UIImage *) backgroundImage forState: (UIControlState) state barMetrics: (UIBarMetrics) barMetrics;
- (UIOffset) backButtonTitlePositionAdjustmentForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setBackButtonTitlePositionAdjustment: (UIOffset) adjustment forBarMetrics: (UIBarMetrics) barMetrics;
- (CGFloat) backButtonBackgroundVerticalPositionAdjustmentForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setBackButtonBackgroundVerticalPositionAdjustment: (CGFloat) adjustment forBarMetrics: (UIBarMetrics) barMetrics;
- (CGFloat) backgroundVerticalPositionAdjustmentForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setBackgroundVerticalPositionAdjustment: (CGFloat) adjustment forBarMetrics: (UIBarMetrics) barMetrics;
- (UIImage *) backgroundImageForState: (UIControlState) state barMetrics: (UIBarMetrics) barMetrics;
- (void) setBackgroundImage: (UIImage *) backgroundImage forState: (UIControlState) state barMetrics: (UIBarMetrics) barMetrics;
- (UIImage *) backgroundImageForState: (UIControlState) state style: (UIBarButtonItemStyle) style barMetrics: (UIBarMetrics) barMetrics;
- (void) setBackgroundImage: (UIImage *) backgroundImage forState: (UIControlState) state style: (UIBarButtonItemStyle) style barMetrics: (UIBarMetrics) barMetrics;
- (UIOffset) titlePositionAdjustmentForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setTitlePositionAdjustment: (UIOffset) adjustment forBarMetrics: (UIBarMetrics) barMetrics;

@end



