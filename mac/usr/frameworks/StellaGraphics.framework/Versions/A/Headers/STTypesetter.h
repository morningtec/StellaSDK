/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#import "STLine.h"

/* Translation from CT -> ST */
#define CTTypesetterRef         STTypesetterRef


#define CTTypesetterCreateWithAttributedString              STTypesetterCreateWithAttributedString
#define CTTypesetterCreateWithAttributedStringAndOptions    STTypesetterCreateWithAttributedStringAndOptions

#define CTTypesetterCreateLine                              STTypesetterCreateLine
#define CTTypesetterCreateLineWithOffset                    STTypesetterCreateLineWithOffset

#define CTTypesetterSuggestLineBreak                        STTypesetterSuggestLineBreak
#define CTTypesetterSuggestLineBreakWithOffset              STTypesetterSuggestLineBreakWithOffset
#define CTTypesetterSuggestClusterBreak                     STTypesetterSuggestClusterBreak
#define CTTypesetterSuggestClusterBreakWithOffset           STTypesetterSuggestClusterBreakWithOffset

#define CTTypesetterGetTypeID                               STTypesetterGetTypeID


/* Stella implementation */
@class STTypesetter;
typedef STTypesetter      * STTypesetterRef;


STELLA_GRAPHICS_EXPORT STTypesetterRef STTypesetterCreateWithAttributedString (CFAttributedStringRef string);
STELLA_GRAPHICS_EXPORT STTypesetterRef STTypesetterCreateWithAttributedStringAndOptions (CFAttributedStringRef string, CFDictionaryRef options);

STELLA_GRAPHICS_EXPORT STLineRef STTypesetterCreateLine (STTypesetterRef typesetter, CFRange stringRange);
STELLA_GRAPHICS_EXPORT STLineRef STTypesetterCreateLineWithOffset (STTypesetterRef typesetter, CFRange stringRange, double offset);

STELLA_GRAPHICS_EXPORT CFIndex STTypesetterSuggestLineBreak (STTypesetterRef typesetter, CFIndex startIndex, double width);
STELLA_GRAPHICS_EXPORT CFIndex STTypesetterSuggestLineBreakWithOffset (STTypesetterRef typesetter, CFIndex startIndex, double width, double offset);
STELLA_GRAPHICS_EXPORT CFIndex STTypesetterSuggestClusterBreak (STTypesetterRef typesetter, CFIndex startIndex, double width);
STELLA_GRAPHICS_EXPORT CFIndex STTypesetterSuggestClusterBreakWithOffset (STTypesetterRef typesetter, CFIndex startIndex, double width, double offset);

STELLA_GRAPHICS_EXPORT CFTypeID STTypesetterGetTypeID ();

