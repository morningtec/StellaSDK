/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

/* Compatibility */


/* Constants */


/* Prototypes */
@class UIImage;

@interface UIColor : NSObject
{
}

@property(nonatomic, readonly) CGColorRef       CGColor;

+ (UIColor *) colorWithWhite: (CGFloat) white alpha: (CGFloat) alpha;
+ (UIColor *) colorWithHue: (CGFloat) hue saturation: (CGFloat) saturation brightness: (CGFloat) brightness alpha: (CGFloat) alpha;
+ (UIColor *) colorWithRed: (CGFloat) red green: (CGFloat) green blue: (CGFloat) blue alpha: (CGFloat) alpha;
+ (UIColor *) colorWithCGColor: (CGColorRef) cgColorRef;
- (UIColor *) colorWithAlphaComponent: (CGFloat) alpha;

+ (UIColor *) blackColor;
+ (UIColor *) darkGrayColor;
+ (UIColor *) lightGrayColor;
+ (UIColor *) whiteColor;
+ (UIColor *) grayColor;
+ (UIColor *) redColor;
+ (UIColor *) greenColor;
+ (UIColor *) blueColor;
+ (UIColor *) cyanColor;
+ (UIColor *) yellowColor;
+ (UIColor *) magentaColor;
+ (UIColor *) orangeColor;
+ (UIColor *) purpleColor;
+ (UIColor *) brownColor;
+ (UIColor *) clearColor;

/* Apple-begin */
+ (UIColor *) darkTextColor;
+ (UIColor *) viewFlipsideBackgroundColor;
+ (UIColor *) colorWithPatternImage: (UIImage *) image;
+ (UIColor *) groupTableViewBackgroundColor;
+ (UIColor *) underPageBackgroundColor;
+ (UIColor *) scrollViewTexturedBackgroundColor;
+ (UIColor *) lightTextColor;

- (BOOL) getRed: (CGFloat *) red green: (CGFloat *) green blue: (CGFloat *) blue alpha: (CGFloat *) alpha;
- (BOOL) getHue: (CGFloat *) hue saturation: (CGFloat *) saturation brightness: (CGFloat *) brightness alpha: (CGFloat *) alpha;
- (void) set;
- (UIColor *) initWithPatternImage: (UIImage *) image;
- (UIColor *) initWithHue: (CGFloat) hue saturation: (CGFloat) saturation brightness: (CGFloat) brightness alpha: (CGFloat) alpha;
- (void) setStroke;
- (UIColor *) initWithRed: (CGFloat) red green: (CGFloat) green blue: (CGFloat) blue alpha: (CGFloat) alpha;
- (BOOL) getWhite: (CGFloat *) white alpha: (CGFloat *) alpha;
- (UIColor *) initWithWhite: (CGFloat) white alpha: (CGFloat) alpha;
- (void) setFill;
- (UIColor *) initWithCGColor: (CGColorRef) cgColor;
/* Apple-end */

@end



