/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

/* Compatibility */
#define CADisplayLink                 SADisplayLink

/* constants */


/* Stella implementation */
@interface SADisplayLink : NSObject
{
}

@property (nonatomic) NSInteger                     frameInterval;
@property (readonly, nonatomic) CFTimeInterval      timestamp;

+ (SADisplayLink *) displayLinkWithTarget: (id) target selector: (SEL) sel;

- (void) addToRunLoop: (NSRunLoop *) runloop forMode: (NSString *) mode;
/* remove */
- (void) invalidate;


@end


