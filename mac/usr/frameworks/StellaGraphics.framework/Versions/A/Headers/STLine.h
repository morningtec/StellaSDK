/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#import "STLine.h"

/* Translation from CT -> ST */
#define CTLineRef         STLineRef

#define CTLineCreateWithAttributedString            STLineCreateWithAttributedString
#define CTLineCreateTruncatedLine                   STLineCreateTruncatedLine
#define CTLineCreateJustifiedLine                   STLineCreateJustifiedLine

#define CTLineDraw                                  STLineDraw

#define CTLineGetGlyphCount                         STLineGetGlyphCount
#define CTLineGetGlyphRuns                          STLineGetGlyphRuns
#define CTLineGetStringRange                        STLineGetStringRange
#define CTLineGetPenOffsetForFlush                  STLineGetPenOffsetForFlush

#define CTLineGetImageBounds                        STLineGetImageBounds
#define CTLineGetTypographicBounds                  STLineGetTypographicBounds
#define CTLineGetTrailingWhitespaceWidth            STLineGetTrailingWhitespaceWidth

#define CTLineGetTypeID                             STLineGetTypeID


#define kCTLineTruncationStart                      kSTLineTruncationStart
#define kCTLineTruncationEnd                        kSTLineTruncationEnd
#define kCTLineTruncationMiddle                     kSTLineTruncationMiddle
#define CTLineTruncationType                        STLineTruncationType



/* Stella implementation */
@class STLine;
typedef STLine      * STLineRef;


enum {
        kSTLineTruncationStart      = 0,
        kSTLineTruncationEnd        = 1,
        kSTLineTruncationMiddle     = 2
};
typedef uint32_t STLineTruncationType;


STELLA_GRAPHICS_EXPORT STLineRef STLineCreateWithAttributedString (CFAttributedStringRef string);
STELLA_GRAPHICS_EXPORT STLineRef STLineCreateTruncatedLine ( STLineRef line, double width, STLineTruncationType truncationType,
                                                    STLineRef truncationToken );
STELLA_GRAPHICS_EXPORT STLineRef STLineCreateJustifiedLine ( STLineRef line, CGFloat justificationFactor,
                                                   double justificationWidth );

STELLA_GRAPHICS_EXPORT void STLineDraw (STLineRef line, SGContextRef context);

STELLA_GRAPHICS_EXPORT CFIndex STLineGetGlyphCount (STLineRef line);
STELLA_GRAPHICS_EXPORT CFArrayRef STLineGetGlyphRuns (STLineRef line);
STELLA_GRAPHICS_EXPORT CFRange STLineGetStringRange (STLineRef line);
STELLA_GRAPHICS_EXPORT double STLineGetPenOffsetForFlush (STLineRef line, SGFloat flushFactor, double flushWidth);

STELLA_GRAPHICS_EXPORT SGRect STLineGetImageBounds (STLineRef line, SGContextRef context);
STELLA_GRAPHICS_EXPORT double STLineGetTypographicBounds (STLineRef line, SGFloat * ascent, SGFloat * descent, SGFloat * leading);
STELLA_GRAPHICS_EXPORT double STLineGetTrailingWhitespaceWidth (STLineRef line);

