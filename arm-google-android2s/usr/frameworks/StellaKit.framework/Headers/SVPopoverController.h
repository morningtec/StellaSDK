/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVGeometry.h"

@class UIViewController;
@class UIBarButtonItem;
@class SVPopoverController;
@class UIView;


enum {
    UIPopoverArrowDirectionUp = 1UL << 0,
    UIPopoverArrowDirectionDown = 1UL << 1,
    UIPopoverArrowDirectionLeft = 1UL << 2,
    UIPopoverArrowDirectionRight = 1UL << 3,
    UIPopoverArrowDirectionAny = UIPopoverArrowDirectionUp | UIPopoverArrowDirectionDown |
    UIPopoverArrowDirectionLeft | UIPopoverArrowDirectionRight,
    UIPopoverArrowDirectionUnknown = NSUIntegerMax
};
typedef NSUInteger UIPopoverArrowDirection;


@protocol UIPopoverControllerDelegate <NSObject>

@optional
- (void) popoverControllerDidDismissPopover: (SVPopoverController *) popoverController;
- (BOOL) popoverControllerShouldDismissPopover: (SVPopoverController *) popoverController;

@end

@interface SVPopoverController : NSObject

@property(nonatomic) CGSize                                     popoverContentSize;
@property(nonatomic, readonly) UIPopoverArrowDirection          popoverArrowDirection;
@property(nonatomic, retain) UIViewController                 * contentViewController;
@property(nonatomic, readwrite) UIEdgeInsets                    popoverLayoutMargins;
@property(nonatomic, readwrite, retain) Class                   popoverBackgroundViewClass;
@property(nonatomic, readonly, getter=isPopoverVisible) BOOL    popoverVisible;
@property(nonatomic, copy) NSArray                            * passthroughViews;
@property(nonatomic, assign) id <UIPopoverControllerDelegate>   delegate;


- (void) dismissPopoverAnimated: (BOOL) animated;
- (void) setContentViewController: (UIViewController *) viewController animated: (BOOL) animated;
- (void) presentPopoverFromBarButtonItem: (UIBarButtonItem *) item permittedArrowDirections: (UIPopoverArrowDirection) arrowDirections animated: (BOOL) animated;
- (void) setPopoverContentSize: (CGSize) size animated: (BOOL) animated;
- (id) initWithContentViewController: (UIViewController *) viewController;
- (void) presentPopoverFromRect: (CGRect) rect inView: (UIView *) view permittedArrowDirections: (UIPopoverArrowDirection) arrowDirections animated: (BOOL) animated;

@end
