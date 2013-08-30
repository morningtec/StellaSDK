/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import "SVControl.h"
#import "SVImage.h"

@interface UISwitch : UIControl

@property(nonatomic, retain) UIImage      * offImage;
@property(nonatomic, getter=isOn) BOOL      on;
@property(nonatomic, retain) UIImage      * onImage;
@property(nonatomic, retain) UIColor      * onTintColor;
@property(nonatomic, retain) UIColor      * thumbTintColor;
@property(nonatomic, retain) UIColor      * tintColor;

- (id) initWithFrame: (CGRect) frame;
- (void) dealloc;

- (void) setOn: (BOOL) on animated: (BOOL) animated;


@end