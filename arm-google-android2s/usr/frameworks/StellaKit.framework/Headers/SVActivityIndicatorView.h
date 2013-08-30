/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVColor.h"

/* Compatibility */

typedef enum {
    UIActivityIndicatorViewStyleWhiteLarge,
    UIActivityIndicatorViewStyleWhite,
    UIActivityIndicatorViewStyleGray,
} UIActivityIndicatorViewStyle;

@interface UIActivityIndicatorView : UIView

- (id) initWithActivityIndicatorStyle: (UIActivityIndicatorViewStyle) style;
- (void) startAnimating;
- (void) stopAnimating;
- (BOOL) isAnimating;

@property BOOL hidesWhenStopped;
@property UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property(readwrite, nonatomic, retain) UIColor *color;

@end
