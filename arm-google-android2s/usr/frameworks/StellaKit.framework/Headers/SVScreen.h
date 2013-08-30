/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

/* Compatibility */


typedef enum {
    UIScreenOverscanCompensationScale,
    UIScreenOverscanCompensationInsetBounds,
    UIScreenOverscanCompensationInsetApplicationFrame,
} UIScreenOverscanCompensation;

@class UIScreenMode;

/* Prototypes */
@interface UIScreen : NSObject
{
        CGRect              rc01;
}

@property(nonatomic, readonly) CGRect           bounds;
@property(nonatomic, readonly) CGRect           applicationFrame;
@property(nonatomic, readonly) CGFloat          scale;

@property(nonatomic, readonly, retain) UIScreen         * mirroredScreen;
@property(nonatomic, readonly, retain) UIScreenMode     * preferredMode;
@property(nonatomic, readonly, copy) NSArray            * availableModes;
@property(nonatomic, retain) UIScreenMode               * currentMode;

@property(nonatomic) CGFloat                              brightness;
@property(nonatomic) BOOL                                 wantsSoftwareDimming;
@property(nonatomic) UIScreenOverscanCompensation         overscanCompensation;

+ (UIScreen *) mainScreen;
+ (NSArray *) screens;
- (id) displayLinkWithTarget: (id) target selector: (SEL) sel;










@end



