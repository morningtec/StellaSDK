/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>

#import "SVControl.h"
#import "SVImage.h"
#import "SVFont.h"

typedef enum {
        UISegmentedControlStylePlain,
        UISegmentedControlStyleBordered,
        UISegmentedControlStyleBar,
        UISegmentedControlStyleBezeled,
} UISegmentedControlStyle;

enum {
        UISegmentedControlNoSegment = -1
};

@interface UISegmentedControl : UIControl

@property (nonatomic) UISegmentedControlStyle   segmentedControlStyle;
@property (nonatomic,strong) UIColor          * tintColor;
@property (nonatomic, assign, readonly) NSUInteger  numberOfSegments;
@property (nonatomic, assign) NSInteger             selectedSegmentIndex;
@property (nonatomic, getter=isMomentary) BOOL      momentary;
@property(nonatomic) BOOL                           apportionsSegmentWidthsByContent;

- (id) initWithItems: (NSArray *) items;

- (void)setTitle: (NSString *) title forSegmentAtIndex: (NSUInteger) segment;
- (NSString *) titleForSegmentAtIndex: (NSUInteger) segment;

- (void)setImage: (UIImage *) image forSegmentAtIndex: (NSUInteger) segment;
- (UIImage *) imageForSegmentAtIndex: (NSUInteger) segment;

- (void) setEnabled: (BOOL) enabled forSegmentAtIndex: (NSUInteger) segment;
- (BOOL) isEnabledForSegmentAtIndex: (NSUInteger) segment;

- (void) setTitleTextAttributes: (NSDictionary *) attributes forState: (UIControlState) state;
- (NSDictionary *) titleTextAttributesForState: (UIControlState) state;

@end

