/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVImage.h"


@interface UIImageView : UIView
{
}

@property(nonatomic, retain) UIImage                          * image;
@property(nonatomic, retain) UIImage                          * highlightedImage;

@property(nonatomic, copy) NSArray                            * animationImages;
@property(nonatomic, copy) NSArray                            * highlightedAnimationImages;
@property(nonatomic) NSTimeInterval                             animationDuration;
@property(nonatomic) NSInteger                                  animationRepeatCount;

@property(nonatomic, getter=isUserInteractionEnabled) BOOL      userInteractionEnabled;
@property(nonatomic, getter=isHighlighted) BOOL                 highlighted;
@property(nonatomic, retain) UIColor                          * tintColor;

- (id) initWithImage: (UIImage *) image;
- (id) initWithImage: (UIImage *) image highlightedImage: (UIImage *) highlightedImage;

- (void) startAnimating;
- (BOOL) isAnimating;
- (void) stopAnimating;

@end
