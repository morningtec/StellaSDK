/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVGeometry.h"
#import "SVEvent.h"

typedef enum {
        UIScrollViewIndicatorStyleDefault,
        UIScrollViewIndicatorStyleBlack,
        UIScrollViewIndicatorStyleWhite
} UIScrollViewIndicatorStyle;

STELLA_KIT_EXPORT const float      UIScrollViewDecelerationRateNormal;
STELLA_KIT_EXPORT const float      UIScrollViewDecelerationRateFast;

@protocol UIScrollViewDelegate;

@interface UIScrollView : UIView

@property(nonatomic) CGPoint                                contentOffset;
@property(nonatomic) CGSize                                 contentSize;
@property(nonatomic) UIEdgeInsets                           contentInset;

@property(nonatomic, getter=isScrollEnabled) BOOL           scrollEnabled;
@property(nonatomic, getter=isDirectionalLockEnabled) BOOL  directionalLockEnabled;
@property(nonatomic) BOOL                                   scrollsToTop;
@property(nonatomic, getter=isPagingEnabled) BOOL           pagingEnabled;
@property(nonatomic) BOOL                                   bounces;
@property(nonatomic) BOOL                                   alwaysBounceVertical;
@property(nonatomic) BOOL                                   alwaysBounceHorizontal;
@property(nonatomic) BOOL                                   canCancelContentTouches;
@property(nonatomic) BOOL                                   delaysContentTouches;
@property(nonatomic) float                                  decelerationRate;
@property(nonatomic, readonly, getter=isDragging) BOOL      dragging;
@property(nonatomic, readonly, getter=isTracking) BOOL      tracking;
@property(nonatomic, readonly, getter=isDecelerating) BOOL  decelerating;

@property(nonatomic) UIScrollViewIndicatorStyle             indicatorStyle;
@property(nonatomic) UIEdgeInsets                           scrollIndicatorInsets;
@property(nonatomic) BOOL                                   showsHorizontalScrollIndicator;
@property(nonatomic) BOOL                                   showsVerticalScrollIndicator;

@property(nonatomic, readonly) id                           panGestureRecognizer;
@property(nonatomic, readonly) id                           pinchGestureRecognizer;
@property(nonatomic) float                                  zoomScale;
@property(nonatomic) float                                  maximumZoomScale;
@property(nonatomic) float                                  minimumZoomScale;
@property(nonatomic, readonly, getter=isZoomBouncing) BOOL  zoomBouncing;
@property(nonatomic, readonly, getter=isZooming) BOOL       zooming;
@property(nonatomic) BOOL                                   bouncesZoom;

@property(nonatomic, assign) id<UIScrollViewDelegate>       delegate;

- (void) setContentOffset: (CGPoint) contentOffset animated: (BOOL) animated;

- (void) scrollRectToVisible: (CGRect) rect animated: (BOOL) animated;
- (BOOL) touchesShouldBegin: (NSSet *) touches withEvent: (UIEvent *) event inContentView: (UIView *) view;
- (BOOL) touchesShouldCancelInContentView: (UIView *) view;

- (void) flashScrollIndicators;

- (void) zoomToRect: (CGRect) rect animated: (BOOL) animated;
- (void) setZoomScale: (float) scale animated: (BOOL) animated;

@end


@protocol UIScrollViewDelegate <NSObject>

@optional
- (void) scrollViewDidScroll: (UIScrollView *) scrollView;
- (void) scrollViewWillBeginDragging: (UIScrollView *) scrollView;
- (void) scrollViewWillEndDragging: (UIScrollView *) scrollView withVelocity: (CGPoint) velocity targetContentOffset: (inout CGPoint *) targetContentOffset;
- (void) scrollViewDidEndDragging: (UIScrollView *) scrollView willDecelerate: (BOOL) decelerate;
- (BOOL) scrollViewShouldScrollToTop: (UIScrollView *) scrollView;
- (void) scrollViewDidScrollToTop: (UIScrollView *) scrollView;
- (void) scrollViewWillBeginDecelerating: (UIScrollView *) scrollView;
- (void) scrollViewDidEndDecelerating: (UIScrollView *) scrollView;
- (void) scrollViewWillEndDragging: (UIScrollView *) scrollView withVelocity: (CGPoint) velocity targetContentOffset: (inout CGPoint *) targetContentOffset;
- (void) scrollViewWillBeginZooming: (UIScrollView *) scrollView withView: (UIView *) view;
- (void) scrollViewDidEndZooming: (UIScrollView *) scrollView withView: (UIView *) view atScale: (float) scale;
- (void) scrollViewDidZoom: (UIScrollView *) scrollView;
- (void) scrollViewDidEndScrollingAnimation: (UIScrollView *) scrollView;

@end



