/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <StellaAnimation/SADisplayLink.h>

enum {
        SADisplayLinkLevelSystem        = 1000
};
typedef NSUInteger SADisplayLinkLevel;

@interface SADisplayLink (Internal)

@property (nonatomic) NSUInteger                    level;

@end

