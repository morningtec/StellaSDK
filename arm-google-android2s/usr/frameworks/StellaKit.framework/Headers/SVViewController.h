/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVApplication.h"
#import "SVView.h"

@class UIResponder;

typedef enum {
        UIModalTransitionStyleCoverVertical     = 0,
        UIModalTransitionStyleFlipHorizontal,
        UIModalTransitionStyleCrossDissolve,
        UIModalTransitionStylePartialCurl,
} UIModalTransitionStyle;

typedef enum {
        UIModalPresentationFullScreen = 0,
        UIModalPresentationPageSheet,
        UIModalPresentationFormSheet,
        UIModalPresentationCurrentContext,
} UIModalPresentationStyle;


@class SVSplitViewController;
@class UITabBarController;
@class UITabBarItem;
@class SVSearchDisplayController;
@class UINavigationItem;
@class UIStoryboard;
@class UINavigationController;
@class UIStoryboardSegue;
@class UIBarButtonItem;

@class UIView;

@interface UIViewController : UIResponder <NSCoding>


@property(nonatomic, readonly, copy) NSString                             * nibName;
@property(nonatomic, readonly, retain) NSBundle                           * nibBundle;
@property(nonatomic, retain) UIView                                       * view;
@property(nonatomic, copy) NSString                                       * title;

@property(nonatomic, readonly, retain) UIStoryboard                       * storyboard;

@property(nonatomic, assign) BOOL                                           wantsFullScreenLayout;

@property(nonatomic, readonly) UIInterfaceOrientation                       interfaceOrientation;

@property(nonatomic, getter=isEditing) BOOL                                 editing;

@property(nonatomic, copy) NSString                                       * restorationIdentifier;
@property(nonatomic, readwrite, assign) id                                  restorationClass;

@property(nonatomic, assign) UIModalTransitionStyle                         modalTransitionStyle;
@property(nonatomic, assign) UIModalPresentationStyle                       modalPresentationStyle;
@property(nonatomic, assign) BOOL                                           definesPresentationContext;
@property(nonatomic, assign) BOOL                                           providesPresentationContextTransitionStyle;

@property(nonatomic, readonly) UIViewController                           * presentingViewController;
@property(nonatomic, readonly) UIViewController                           * presentedViewController;
@property(nonatomic, readonly) UIViewController                           * parentViewController;
@property(nonatomic, readonly, retain) UINavigationController             * navigationController;
@property(nonatomic, readonly, retain) SVSplitViewController              * splitViewController;
@property(nonatomic, readonly, retain) UITabBarController                 * tabBarController;
@property(nonatomic, readonly, retain) SVSearchDisplayController          * searchDisplayController;
@property(nonatomic, readonly) UIViewController                           * modalViewController;

@property(nonatomic, readonly) NSArray                                    * childViewControllers;

@property(nonatomic, readonly, retain) UINavigationItem                   * navigationItem;
@property(nonatomic) BOOL                                                   hidesBottomBarWhenPushed;
@property(nonatomic, retain) NSArray                                      * toolbarItems;

@property(nonatomic, retain) UITabBarItem                                 * tabBarItem;

@property(nonatomic, readwrite) CGSize                                      contentSizeForViewInPopover;
@property(nonatomic, readwrite, getter=isModalInPopover) BOOL               modalInPopover;



- (id) initWithNibName: (NSString *) nibName bundle: (NSBundle *) nibBundle;


- (BOOL) shouldPerformSegueWithIdentifier: (NSString *) identifier sender: (id) sender;
- (void) performSegueWithIdentifier: (NSString *) identifier sender: (id) sender;
- (void) prepareForSegue: (UIStoryboardSegue *) segue sender: (id) sender;
- (BOOL) canPerformUnwindSegueAction: (SEL) action fromViewController: (UIViewController *) fromViewController withSender: (id) sender;


- (BOOL) isViewLoaded;
- (void) loadView;
- (void) viewDidLoad;
- (void) viewDidUnload;

- (void) didReceiveMemoryWarning;

- (void) viewWillAppear: (BOOL) animated;
- (void) viewDidAppear: (BOOL) animated;
- (void) viewWillDisappear: (BOOL) animated;
- (void) viewDidDisappear: (BOOL) animated;
- (void) viewWillLayoutSubviews;
- (void) viewDidLayoutSubviews;


- (BOOL) isMovingFromParentViewController;
- (BOOL) isMovingToParentViewController;
- (BOOL) isBeingPresented;
- (BOOL) isBeingDismissed;


- (void) updateViewConstraints;


- (NSUInteger) supportedInterfaceOrientations;
- (UIInterfaceOrientation) preferredInterfaceOrientationForPresentation;
+ (void) attemptRotationToDeviceOrientation;
- (UIView *) rotatingHeaderView;
- (UIView *) rotatingFooterView;
- (BOOL) shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation) interfaceOrientation;


- (void) willRotateToInterfaceOrientation: (UIInterfaceOrientation) toInterfaceOrientation duration: (NSTimeInterval) duration;
- (void) willAnimateRotationToInterfaceOrientation: (UIInterfaceOrientation) interfaceOrientation duration: (NSTimeInterval) duration;
- (void) didRotateFromInterfaceOrientation: (UIInterfaceOrientation) fromInterfaceOrientation;


- (void) willMoveToParentViewController: (UIViewController *) parent;
- (void) didMoveToParentViewController: (UIViewController *) parent;


- (void) setEditing: (BOOL) editing animated: (BOOL) animated;


- (void) encodeRestorableStateWithCoder: (NSCoder *) coder;
- (void) decodeRestorableStateWithCoder: (NSCoder *) coder;


- (void) presentViewController: (UIViewController *) viewControllerToPresent animated: (BOOL) flag completion: (void (^)(void)) completion;
- (void) dismissViewControllerAnimated: (BOOL) flag completion: (void (^)(void)) completion;
- (BOOL) disablesAutomaticKeyboardDismissal;
- (void) presentModalViewController: (UIViewController *) modalViewController animated: (BOOL) animated;


- (void) addChildViewController: (UIViewController *) childController;
- (void) removeFromParentViewController;
- (BOOL) shouldAutomaticallyForwardRotationMethods;
- (BOOL) shouldAutomaticallyForwardAppearanceMethods;
- (void) transitionFromViewController: (UIViewController *) fromViewController toViewController: (UIViewController *) toViewController duration: (NSTimeInterval) duration options: (UIViewAnimationOptions) options animations: (void (^)(void)) animations completion: (void (^)(BOOL finished)) completion;
- (void) beginAppearanceTransition: (BOOL) isAppearing animated: (BOOL) animated;
- (void) endAppearanceTransition;
- (UIViewController *) viewControllerForUnwindSegueAction: (SEL) action fromViewController: (UIViewController *) fromViewController withSender: (id) sender;
- (UIStoryboardSegue *) segueForUnwindingToViewController: (UIViewController *) toViewController fromViewController: (UIViewController *) fromViewController identifier: (NSString *) identifier;


- (UIBarButtonItem *) editButtonItem;
- (void) setToolbarItems: (NSArray *) toolbarItems animated: (BOOL) animated;



@end

