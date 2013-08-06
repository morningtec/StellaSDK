/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>


/* Compatibility */
#define CATransaction                 SATransaction
#define CATransactionDelegate         SATransactionDelegate

/* constants */
#define kCATransactionAnimationDuration       kSATransactionAnimationDuration
#define kCATransactionDisableActions          kSATransactionAnimationDuration
#define kCATransactionAnimationTimingFunction kSATransactionAnimationDuration
#define kCATransactionCompletionBlock         kSATransactionAnimationDuration




/* Stella implementation */
@interface SATransaction : NSObject
{
}

+ (void) begin;
+ (void) commit;
+ (void) flush;

+ (CFTimeInterval) animationDuration;
+ (void) setAnimationDuration : (CFTimeInterval) value;
+ (SAMediaTimingFunction *) animationTimingFunction;
+ (void) setAnimationTimingFunction : (SAMediaTimingFunction *) value;

+ (BOOL) disableActions;
+ (void) setDisableActions: (BOOL) value;

+ (void) lock;
+ (void) unlock;

+ (void) setValue: (id) value forKey: (NSString *) key;
+ (id) valueForKey:(NSString *)key;

+ (void) setValue: (id) value forKey: (NSString *) key;
+ (id) valueForKey: (NSString *) key;

@end



STELLA_GRAPHICS_EXPORT NSString * const kSATransactionAnimationDuration;
STELLA_GRAPHICS_EXPORT NSString * const kSATransactionDisableActions;
STELLA_GRAPHICS_EXPORT NSString * const kSATransactionAnimationTimingFunction;
STELLA_GRAPHICS_EXPORT NSString * const kSATransactionCompletionBlock;

