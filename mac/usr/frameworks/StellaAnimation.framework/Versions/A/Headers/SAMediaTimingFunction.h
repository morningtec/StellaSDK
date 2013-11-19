/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <StellaGraphics/StellaGraphicsExport.h>

/* Compatibility */
#define CAMediaTimingFunction               SAMediaTimingFunction

#define kCAMediaTimingFunctionLinear        kSAMediaTimingFunctionLinear
#define kCAMediaTimingFunctionEaseIn        kSAMediaTimingFunctionEaseIn
#define kCAMediaTimingFunctionEaseOut       kSAMediaTimingFunctionEaseOut
#define kCAMediaTimingFunctionEaseInEaseOut kSAMediaTimingFunctionEaseInEaseOut
#define kCAMediaTimingFunctionDefault       kSAMediaTimingFunctionDefault


STELLA_GRAPHICS_EXPORT NSString * const     kSAMediaTimingFunctionLinear;
STELLA_GRAPHICS_EXPORT NSString * const     kSAMediaTimingFunctionEaseIn;
STELLA_GRAPHICS_EXPORT NSString * const     kSAMediaTimingFunctionEaseOut;
STELLA_GRAPHICS_EXPORT NSString * const     kSAMediaTimingFunctionEaseInEaseOut;
STELLA_GRAPHICS_EXPORT NSString * const     kSAMediaTimingFunctionDefault;

@interface SAMediaTimingFunction : NSObject <NSCopying>
{
}
+ (id) functionWithName: (NSString *)name;
+ (id) functionWithControlPoints: (float) c1x : (float) c1y : (float) c2x : (float) c2y;
- (id) initWithControlPoints: (float) c1x : (float) c1y : (float)c2x : (float) c2y;

- (void) getControlPointAtIndex: (size_t) index values: (float[2]) ptr;

@end






