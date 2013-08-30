/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVImage.h"


/* Prototypes */
@interface UIImageView : UIView
{
}

@property(retain, nonatomic) UIImage              * image;
@property(nonatomic, getter=isHighlighted) BOOL     highlighted;
/* Apple-begin */
@property(nonatomic, getter=isUserInteractionEnabled) BOOL      userInteractionEnabled;
@property(nonatomic, copy) NSArray                            * highlightedAnimationImages;
@property(nonatomic, copy) NSArray                            * animationImages;
@property(nonatomic) NSTimeInterval                             animationDuration;
@property(nonatomic) NSInteger                                  animationRepeatCount;
/* Apple-end */
- (id) initWithImage: (UIImage *) image;
/* Apple-begin */
- (id) initWithImage: (UIImage *) image highlightedImage: (UIImage *) highlightedImage;
- (void) startAnimating;
- (BOOL) isAnimating;
- (void) stopAnimating;
/* Apple-end */
@end
