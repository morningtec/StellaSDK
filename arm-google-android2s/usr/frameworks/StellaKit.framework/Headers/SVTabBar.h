/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVTabBarItem.h"
#import "SVImage.h"
#import "SVColor.h"


@class UITabBar;
@protocol UITabBarDelegate <NSObject>

@optional
- (void) tabBar: (UITabBar *) tabBar willBeginCustomizingItems: (NSArray *) items;
- (void) tabBar: (UITabBar *) tabBar didBeginCustomizingItems: (NSArray *) items;
- (void) tabBar: (UITabBar *) tabBar willBeginCustomizingItems: (NSArray *) items;
- (void) tabBar: (UITabBar *) tabBar didEndCustomizingItems: (NSArray *) items changed: (BOOL) changed;
@required
- (void) tabBar: (UITabBar *) tabBar didSelectItem: (UITabBarItem *) item;

@end

@interface UITabBar : UIView
@property(nonatomic, assign) id<UITabBarDelegate>       delegate;
@property(nonatomic, copy) NSArray                    * items;
@property(nonatomic, assign) UITabBarItem             * selectedItem;

@property(nonatomic, retain) UIImage                  * backgroundImage;
@property(nonatomic, retain) UIColor                  * selectedImageTintColor;
@property(nonatomic, retain) UIImage                  * selectionIndicatorImage;
@property(nonatomic,retain) UIImage                   * shadowImage;
@property(nonatomic, retain) UIColor                  * tintColor;

- (void) setItems: (NSArray *) items animated: (BOOL) animated;

- (void) beginCustomizingItems: (NSArray *) items;
- (BOOL) endCustomizingAnimated: (BOOL) animated;
- (BOOL) isCustomizing;



@end
