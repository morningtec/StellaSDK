/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

#import "SVView.h"
#import "SVColor.h"
#import "SVInterface.h"



@class UIBarButtonItem;

@interface UINavigationItem : NSObject <NSCoding>

@property(nonatomic, copy) NSString                 * title;
@property(nonatomic, copy) NSString                 * prompt;
@property(nonatomic, retain) UIBarButtonItem        * backBarButtonItem;
@property(nonatomic, assign) BOOL                     hidesBackButton;

@property BOOL                                        leftItemsSupplementBackButton;

@property(nonatomic, retain) UIView                 * titleView;
@property(nonatomic, copy) NSArray                  * leftBarButtonItems;
@property(nonatomic, retain) UIBarButtonItem        * leftBarButtonItem;
@property(nonatomic, copy) NSArray                  * rightBarButtonItems;
@property(nonatomic, retain) UIBarButtonItem        * rightBarButtonItem;


- (id) initWithTitle: (NSString *) title;
- (void) setHidesBackButton: (BOOL) hidesBackButton animated: (BOOL) animated;

- (void) setLeftBarButtonItems: (NSArray *) items animated: (BOOL) animated;
- (void) setLeftBarButtonItem: (UIBarButtonItem *) item animated: (BOOL) animated;
- (void) setRightBarButtonItems: (NSArray *) items animated: (BOOL) animated;
- (void) setRightBarButtonItem: (UIBarButtonItem *) item animated: (BOOL) animated;

@end



@class UIColor, UINavigationItem, UINavigationBar;

@protocol UINavigationBarDelegate <NSObject>
@optional
- (BOOL) navigationBar: (UINavigationBar *) navigationBar shouldPushItem: (UINavigationItem *) item;
- (void) navigationBar: (UINavigationBar *) navigationBar didPushItem: (UINavigationItem *) item;
- (BOOL) navigationBar: (UINavigationBar *) navigationBar shouldPopItem: (UINavigationItem *) item;
- (void) navigationBar: (UINavigationBar *) navigationBar didPopItem: (UINavigationItem *) item;
@end

@class UIImage;

@interface UINavigationBar : UIView

@property(nonatomic, assign) UIBarStyle                          barStyle;
@property(nonatomic,retain) UIImage                            * shadowImage;
@property(nonatomic, assign, getter=isTranslucent) BOOL          translucent;

@property(nonatomic, assign) id                                  delegate;

@property(nonatomic, copy) NSArray                             * items;
@property(nonatomic, readonly, retain) UINavigationItem        * topItem;
@property(nonatomic, readonly, retain) UINavigationItem        * backItem;
@property(nonatomic, retain) UIColor                           * tintColor;
@property(nonatomic, copy) NSDictionary                        * titleTextAttributes;


- (void) pushNavigationItem: (UINavigationItem *) item animated: (BOOL) animated;
- (UINavigationItem *) popNavigationItemAnimated: (BOOL) animated;
- (void) setItems: (NSArray *) items animated: (BOOL) animated;


- (UIImage *) backgroundImageForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setBackgroundImage: (UIImage *) backgroundImage forBarMetrics: (UIBarMetrics) barMetrics;
- (CGFloat) titleVerticalPositionAdjustmentForBarMetrics: (UIBarMetrics) barMetrics;
- (void) setTitleVerticalPositionAdjustment: (CGFloat) adjustment forBarMetrics: (UIBarMetrics) barMetrics;

@end




