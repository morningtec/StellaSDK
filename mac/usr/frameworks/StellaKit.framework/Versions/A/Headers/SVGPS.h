/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

@interface SVGPS: NSObject

+ (SVGPS *) sharedGPS;

- (void) openGPSSetting;
- (void) locationUpdated;

@property (nonatomic, retain) NSNumber      * latitude;
@property (nonatomic, retain) NSNumber      * longitude;
@property (nonatomic, assign) id            * delegate;

@end



