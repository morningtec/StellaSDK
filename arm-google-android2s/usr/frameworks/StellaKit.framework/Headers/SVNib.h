/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"


@interface UINib : NSObject

+ (UINib *) nibWithNibName: (NSString *) name bundle: (NSBundle *) bundle;
+ (UINib *) nibWithData: (NSData *) data bundle: (NSBundle *) bundle;
- (NSArray *) instantiateWithOwner: (id) owner options: (NSDictionary *) options;

@end

