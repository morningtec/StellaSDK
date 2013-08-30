/* Stella Debut 2012 */

#import <Foundation/NSOperation.h>

@interface NSBlockOperation : NSOperation
+ (id) blockOperationWithBlock: (void (^)(void)) block;
- (void) addExecutionBlock: (void (^)(void)) block;
- (NSArray *) executionBlocks;
@end



