/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>

@interface SGPWSWindow : NSObject
{
}

@property (nonatomic, assign) id                delegate;

- (SGContext *) cgContext;

- (void) placeAboveWindow: (NSInteger) otherNumber;
- (void) placeBelowWindow: (NSInteger) otherNumber;

- (void) flushBuffer;

@end

