/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVViewController.h"
#import "SVTabBar.h"
#import "SVNavigationController.h"



@class UITabBarController;

@protocol UITabBarControllerDelegate <NSObject>

- (BOOL) tabBarController: (UITabBarController *) tabBarController shouldSelectViewController: (UIViewController *) viewController;
- (void) tabBarController: (UITabBarController *) tabBarController didSelectViewController: (UIViewController *) viewController;
- (void) tabBarController: (UITabBarController *) tabBarController willBeginCustomizingViewControllers: (NSArray *) viewControllers;
- (void) tabBarController: (UITabBarController *) tabBarController willEndCustomizingViewControllers: (NSArray *) viewControllers changed:(BOOL)changed;
- (void) tabBarController: (UITabBarController *) tabBarController didEndCustomizingViewControllers: (NSArray *) viewControllers changed:(BOOL)changed;

@end

@interface UITabBarController : UIViewController <UITabBarDelegate>

@property(nonatomic, assign) id<UITabBarControllerDelegate>           delegate;
@property(nonatomic,readonly) UITabBar                              * tabBar;

@property(nonatomic, copy) NSArray                                  * viewControllers;
@property(nonatomic, copy) NSArray                                  * customizableViewControllers;
@property(nonatomic, readonly) UINavigationController               * moreNavigationController;

@property(nonatomic, assign) UIViewController                       * selectedViewController;
@property(nonatomic) NSUInteger                                       selectedIndex;

- (void) setViewControllers: (NSArray *) viewControllers animated: (BOOL) animated;


@end
