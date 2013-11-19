/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import "SVControl.h"
#import "SVImage.h"

@class UIImageView, UIImage;
@interface UISlider : UIControl
{
}

@property(nonatomic) float                          value;

@property(nonatomic) float                          minimumValue;
@property(nonatomic) float                          maximumValue;

@property(nonatomic, getter=isContinuous) BOOL      continuous;

@property(nonatomic, retain) UIImage              * minimumValueImage;
@property(nonatomic, retain) UIImage              * maximumValueImage;
@property(nonatomic, retain) UIColor              * minimumTrackTintColor;
@property(nonatomic, readonly) UIImage            * currentMinimumTrackImage;
@property(nonatomic, retain) UIColor              * maximumTrackTintColor;
@property(nonatomic, readonly) UIImage            * currentMaximumTrackImage;
@property(nonatomic, retain) UIColor              * thumbTintColor;
@property(nonatomic, readonly) UIImage            * currentThumbImage;


- (void) setValue: (float) value animated: (BOOL) animated;
- (void) setMaximumTrackImage: (UIImage *)image forState: (UIControlState)state;
- (void) setMinimumTrackImage: (UIImage *)image forState: (UIControlState)state;
- (void) setThumbImage: (UIImage *)image forState: (UIControlState)state;


- (UIImage *) minimumTrackImageForState: (UIControlState)state;
- (UIImage *) maximumTrackImageForState: (UIControlState)state;
- (UIImage *) thumbImageForState: (UIControlState)state;

- (CGRect) maximumValueImageRectForBounds: (CGRect)bounds;
- (CGRect) minimumValueImageRectForBounds: (CGRect)bounds;
- (CGRect) trackRectForBounds: (CGRect)bounds;
- (CGRect) thumbRectForBounds: (CGRect)bounds trackRect: (CGRect)rect value: (float)value;

@end
