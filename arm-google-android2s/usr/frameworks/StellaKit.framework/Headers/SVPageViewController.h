/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVViewController.h"




enum {
    UIPageViewControllerSpineLocationNone   = 0,
    UIPageViewControllerSpineLocationMin    = 1,
    UIPageViewControllerSpineLocationMid    = 2,
    UIPageViewControllerSpineLocationMax    = 3
};
typedef NSInteger UIPageViewControllerSpineLocation;

enum {
    UIPageViewControllerTransitionStylePageCurl = 0,
    UIPageViewControllerTransitionStyleScroll = 1
};
typedef NSInteger UIPageViewControllerTransitionStyle;


enum {
    UIPageViewControllerNavigationOrientationHorizontal = 0,
    UIPageViewControllerNavigationOrientationVertical = 1
};
typedef NSInteger UIPageViewControllerNavigationOrientation;


enum {
    UIPageViewControllerNavigationDirectionForward,
    UIPageViewControllerNavigationDirectionReverse
};
typedef NSInteger UIPageViewControllerNavigationDirection;



@class UIPageViewController;

@protocol UIPageViewControllerDataSource <NSObject>

@optional
- (UIViewController *) pageViewController: (UIPageViewController *) pageViewController viewControllerBeforeViewController: (UIViewController *) viewController;
- (UIViewController *) pageViewController: (UIPageViewController *) pageViewController viewControllerAfterViewController: (UIViewController *) viewController;
- (NSInteger) presentationCountForPageViewController: (UIPageViewController *) pageViewController;
- (NSInteger) presentationIndexForPageViewController: (UIPageViewController *) pageViewController;

@end

@protocol UIPageViewControllerDelegate <NSObject>

@optional
- (void) pageViewController: (UIPageViewController *) pageViewController willTransitionToViewControllers: (NSArray *) pendingViewControllers;
- (void) pageViewController: (UIPageViewController *) pageViewController didFinishAnimating: (BOOL) finished previousViewControllers: (NSArray *) previousViewControllers;
- (UIPageViewControllerSpineLocation) pageViewController: (UIPageViewController *) pageViewController spineLocationForInterfaceOrientation: (UIInterfaceOrientation) orientation;

@end

@interface UIPageViewController : UIViewController

- (id) initWithTransitionStyle: (UIPageViewControllerTransitionStyle) style navigationOrientation: (UIPageViewControllerNavigationOrientation) navigationOrientation options: (NSDictionary *) options;

@property(nonatomic, assign) id<UIPageViewControllerDataSource>             dataSource;
@property(nonatomic, assign) id<UIPageViewControllerDelegate>               delegate;

- (void) setViewControllers: (NSArray *) viewControllers direction: (UIPageViewControllerNavigationDirection) direction animated: (BOOL) animated completion: (void (^)(BOOL finished)) completion;

@property(nonatomic, readonly) NSArray                                    * viewControllers;
@property(nonatomic, readonly) NSArray                                    * gestureRecognizers;
@property(nonatomic, readonly) UIPageViewControllerNavigationOrientation    navigationOrientation;
@property(nonatomic, readonly) UIPageViewControllerSpineLocation            spineLocation;
@property(nonatomic, readonly) UIPageViewControllerTransitionStyle          transitionStyle;
@property(nonatomic, getter=isDoubleSided) BOOL                             doubleSided;

@end
