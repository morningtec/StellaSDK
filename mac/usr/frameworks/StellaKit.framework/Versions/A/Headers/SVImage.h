/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVGeometry.h"

/* Compatibility */


typedef enum {
        UIImageOrientationUp,
        UIImageOrientationDown,   // 180 deg rotation
        UIImageOrientationLeft,   // 90 deg CCW
        UIImageOrientationRight,   // 90 deg CW
        UIImageOrientationUpMirrored,    // as above but image mirrored along
        // other axis. horizontal flip
        UIImageOrientationDownMirrored,  // horizontal flip
        UIImageOrientationLeftMirrored,  // vertical flip
        UIImageOrientationRightMirrored, // vertical flip
} UIImageOrientation;

/* Prototypes */


typedef enum {
    UIImageResizingModeTile,
    UIImageResizingModeStretch,
} UIImageResizingMode;



@interface UIImage : NSObject
{
}

@property(nonatomic, readonly) CGSize       size;
@property(nonatomic, readonly) CGImageRef   CGImage;

+ (UIImage *) imageNamed:(NSString *) name;

+ (id) imageWithContentsOfFile: (NSString *) path;
+ (id) imageWithData: (NSData *) data;
+ (id) imageWithCGImage: (CGImageRef) cgImage;

- (id) initWithContentsOfFile: (NSString *) path;
- (id) initWithData: (NSData *) data;
- (id) initWithCGImage: (CGImageRef) cgImage;

- (UIImageOrientation) imageOrientation;

#pragma mark -
#pragma mark Dummy property ref: Apple
@property(nonatomic,readonly) UIImageResizingMode   resizingMode;
@property(nonatomic, readonly) NSArray            * images;
@property(nonatomic, readonly) NSTimeInterval       duration;
@property(nonatomic, readonly) UIEdgeInsets         capInsets;
@property(nonatomic, readonly) UIEdgeInsets         alignmentRectInsets;


#pragma mark -
#pragma mark Dummy function ref: Apple

+ (UIImage *) imageWithData: (NSData *) data scale: (CGFloat) scale;
+ (UIImage *) imageWithCGImage: (CGImageRef) imageRef scale: (CGFloat) scale orientation: (UIImageOrientation) orientation;
- (UIImage *) imageWithAlignmentRectInsets: (UIEdgeInsets) alignmentInsets;
+ (UIImage *) animatedImageNamed: (NSString *) name duration: (NSTimeInterval) duration;
+ (UIImage *) animatedImageWithImages: (NSArray *) images duration: (NSTimeInterval) duration;
+ (UIImage *) animatedResizableImageNamed: (NSString *) name capInsets: (UIEdgeInsets) capInsets duration: (NSTimeInterval) duration;
- (UIImage *) resizableImageWithCapInsets: (UIEdgeInsets) capInsets;
+ (UIImage *) animatedResizableImageNamed: (NSString *) name capInsets: (UIEdgeInsets) capInsets resizingMode: (UIImageResizingMode) resizingMode duration: (NSTimeInterval) duration;
- (UIImage *) resizableImageWithCapInsets: (UIEdgeInsets) capInsets resizingMode: (UIImageResizingMode) resizingMode;
- (UIImage *) stretchableImageWithLeftCapWidth: (NSInteger) leftCapWidth topCapHeight: (NSInteger) topCapHeight;
- (id) initWithData: (NSData *) data scale: (CGFloat) scale;
- (id) initWithCGImage: (CGImageRef) imageRef scale: (CGFloat) scale orientation: (UIImageOrientation) orientation;
- (void) drawAtPoint: (CGPoint) point;
- (void) drawAtPoint: (CGPoint) point blendMode: (CGBlendMode) blendMode alpha: (CGFloat) alpha;
- (void) drawInRect: (CGRect) rect;
- (void) drawInRect: (CGRect) rect blendMode: (CGBlendMode) blendMode alpha: (CGFloat) alpha;
- (void) drawAsPatternInRect: (CGRect) rect;

@end


NSData    * UIImageJPEGRepresentation (UIImage * image, CGFloat compressionQuality);
NSData    * UIImagePNGRepresentation (UIImage *image);


