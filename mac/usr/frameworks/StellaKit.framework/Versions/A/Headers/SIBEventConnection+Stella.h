/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "SIBConnection+Stella.h"

@class SIBObject;
@interface SIBEventConnection : SIBConnection <NSCoding>
{
}

@property(nonatomic, assign) NSUInteger       eventType;


- (id) initWithCoder: (NSCoder *) coder;
- (void) encodeWithCoder: (NSCoder *) coder;

- (void) dealloc;

- (BOOL) establishST2;

@end
