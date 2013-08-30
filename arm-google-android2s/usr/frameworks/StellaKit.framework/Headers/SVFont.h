/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

/* Compatibility */


/* Prototypes */
@interface UIFont : NSObject
{
}

@property(nonatomic, readonly, retain) NSString     * familyName;
@property(nonatomic, readonly, retain) NSString     * fontName;

@property(nonatomic, readonly) CGFloat                pointSize;
@property(nonatomic, readonly) CGFloat                ascender;
@property(nonatomic, readonly) CGFloat                descender;
@property(nonatomic, readonly) CGFloat                capHeight;
@property(nonatomic, readonly) CGFloat                xHeight;
@property(nonatomic, readonly) CGFloat                lineHeight;
@property(nonatomic, readonly) CGFloat                leading;

- (id) copyWithZone: (NSZone *) zone;
- (id) initWithName: (NSString *) name;
- (void) dealloc;

+ (UIFont *) fontWithName: (NSString *) fontName size: (CGFloat) fontSize;
- (UIFont *) fontWithSize: (CGFloat) fontSize;

+ (UIFont *) systemFontOfSize: (CGFloat) fontSize;
+ (UIFont *) boldSystemFontOfSize: (CGFloat) fontSize;
+ (UIFont *) italicSystemFontOfSize: (CGFloat) fontSize;

+ (NSArray *) familyNames;
+ (NSArray *) fontNamesForFamilyName: (NSString *) familyName;

+ (CGFloat) labelFontSize;
+ (CGFloat) buttonFontSize;
+ (CGFloat) smallSystemFontSize;
+ (CGFloat) systemFontSize;

@end



