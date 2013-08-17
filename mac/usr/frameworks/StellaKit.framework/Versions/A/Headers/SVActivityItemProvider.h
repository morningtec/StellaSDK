/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"


@interface UIActivityItemProvider : NSOperation

- (id) initWithPlaceholderItem: (id) placeholderItem;
@property(nonatomic,retain,readonly) id placeholderItem;
@property(nonatomic,readonly) NSString *activityType;

@end
