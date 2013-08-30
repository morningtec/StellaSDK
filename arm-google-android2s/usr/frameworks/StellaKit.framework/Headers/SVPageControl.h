/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVControl.h"
#import "SVColor.h"

@interface UIPageControl : UIControl
{
}

@property(nonatomic) NSInteger              currentPage;
@property(nonatomic) NSInteger              numberOfPages;
@property(nonatomic) BOOL                   hidesForSinglePage;

@property(nonatomic,retain) UIColor       * pageIndicatorTintColor;
@property(nonatomic,retain) UIColor       * currentPageIndicatorTintColor;
@property(nonatomic) BOOL                   defersCurrentPageDisplay;

- (void) updateCurrentPageDisplay;

- (CGSize) sizeForNumberOfPages: (NSInteger) pageCount;

@end
