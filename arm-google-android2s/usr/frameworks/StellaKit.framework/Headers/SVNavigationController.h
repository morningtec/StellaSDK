/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVViewController.h"
#import "SVNavigationBar.h"
/* Apple-begin */
@class UIToolbar;
/* Apple-end */


@protocol UINavigationControllerDelegate <NSObject>
@optional
@end


@interface UINavigationController : UIViewController
{
}

@property(nonatomic, readonly, retain) UIViewController               * topViewController;
@property(nonatomic, readonly, retain) UIViewController               * visibleViewController;
@property(nonatomic, copy) NSArray                                    * viewControllers;

@property(nonatomic, readonly) UINavigationBar                        * navigationBar;
@property(nonatomic, getter=isNavigationBarHidden) BOOL                 navigationBarHidden;

@property(nonatomic, assign) id<UINavigationControllerDelegate>         delegate;

@property(nonatomic,readonly) UIToolbar                               * toolbar;
@property(nonatomic,getter=isToolbarHidden) BOOL                        toolbarHidden;


- (id) initWithRootViewController: (UIViewController *) rootViewController;
- (id) initWithNavigationBarClass: (Class) navigationBarClass toolbarClass: (Class) toolbarClass;

- (UIViewController *) topViewController;
- (void) setViewControllers: (NSArray *) viewControllers animated: (BOOL) animated;

- (void) pushViewController: (UIViewController *) viewController animated: (BOOL) animated;
- (UIViewController *) popViewControllerAnimated: (BOOL) animated;
- (NSArray *) popToRootViewControllerAnimated: (BOOL) animated;
- (NSArray *) popToViewController: (UIViewController *) viewController animated: (BOOL) animated;


- (void) setNavigationBarHidden: (BOOL) hidden animated: (BOOL) animated;
- (void) setToolbarHidden: (BOOL) hidden animated: (BOOL) animated;

@end


