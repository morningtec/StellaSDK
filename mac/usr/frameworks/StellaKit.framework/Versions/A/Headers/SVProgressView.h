/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "SVView.h"
#import "SVImage.h"

enum {
        UIProgressViewStyleDefault,
        UIProgressViewStyleBar,
};
typedef NSUInteger UIProgressViewStyle;

@interface UIProgressView : UIView {
        UIProgressViewStyle     _progressViewStyle;
        float                   _progress;
}

- (id) initWithProgressViewStyle: (UIProgressViewStyle) style;
- (void) setProgress: (float) progress animated: (BOOL) animated;


@property(nonatomic) UIProgressViewStyle progressViewStyle;
@property(nonatomic, retain) UIColor   * progressTintColor;
@property(nonatomic, retain) UIImage   * progressImage;
@property(nonatomic, retain) UIColor   * trackTintColor;
@property(nonatomic, retain) UIImage   * trackImage;
@property(nonatomic) float progress;

@end



