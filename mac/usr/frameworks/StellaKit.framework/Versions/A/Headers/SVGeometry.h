/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"


typedef struct UIOffset {
        CGFloat     horizontal;
        CGFloat     vertical;
} UIOffset;

typedef struct _UIEdgeInsets {
        CGFloat     top;
        CGFloat     left;
        CGFloat     bottom;
        CGFloat     right;
} UIEdgeInsets;


/* Prototypes */
STELLA_KIT_EXPORT CGPoint       CGPointFromString (NSString * string);
STELLA_KIT_EXPORT CGSize        CGSizeFromString (NSString * string);
STELLA_KIT_EXPORT CGRect        CGRectFromString (NSString * string);

STELLA_KIT_EXPORT NSString    * NSStringFromCGPoint (CGPoint point);
STELLA_KIT_EXPORT NSString    * NSStringFromCGRect (CGRect rect);
STELLA_KIT_EXPORT NSString    * NSStringFromCGSize (CGSize size);


static inline UIEdgeInsets UIEdgeInsetsMake (CGFloat top, CGFloat left, CGFloat bottom, CGFloat right)
{
        return (UIEdgeInsets) {top, left, bottom, right};
}

static inline CGRect UIEdgeInsetsInsetRect (CGRect rect, UIEdgeInsets insets)
{
        rect.origin.x          += insets.left;
        rect.origin.y          += insets.top;
        rect.size.width        -= (insets.left + insets.right);
        rect.size.height       -= (insets.top  + insets.bottom);
        return rect;
}

static inline BOOL UIEdgeInsetsEqualToEdgeInsets (UIEdgeInsets insets1, UIEdgeInsets insets2)
{
        return CGRectEqualToRect ( CGRectMake (insets1.left, insets1.top, insets1.right, insets1.bottom),
                                   CGRectMake (insets2.left, insets2.top, insets2.right, insets2.bottom) );
}



@interface NSValue (StellaKitAdditions)
+ (NSValue *) valueWithCGPoint: (CGPoint) point;
+ (NSValue *) valueWithCGRect: (CGRect) rect;
+ (NSValue *) valueWithCGSize: (CGSize) size;

- (CGPoint) CGPointValue;
- (CGRect) CGRectValue;
- (CGSize) CGSizeValue;
@end
