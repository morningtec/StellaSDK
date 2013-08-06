/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"


/* Compatibility */
#define CGGlyph   SGGlyph

#define CGFont    SGFont
#define CGFontRef SGFontRef




#define CGFontRelease               SGFontRelease
#define CGFontRetain                SGFontRetain

#define CGFontCreateWithFontName    SGFontCreateWithFontName

#define CGFontCopyTableForTag       SGFontCopyTableForTag
#define CGFontCopyFullName          SGFontCopyFullName
#define CGFontGetAscent             SGFontGetAscent
#define CGFontGetDescent            SGFontGetDescent
#define CGFontGetLeading            SGFontGetLeading
#define CGFontGetCapHeight          SGFontGetCapHeight
#define CGFontGetXHeight            SGFontGetXHeight
#define CGFontGetFontBBox           SGFontGetFontBBox
#define CGFontGetItalicAngle        SGFontGetItalicAngle
#define CGFontGetStemV              SGFontGetStemV
#define CGFontGetGlyphWithGlyphName SGFontGetGlyphWithGlyphName
#define CGFontCopyGlyphNameForGlyph SGFontCopyGlyphNameForGlyph
#define CGFontGetNumberOfGlyphs     SGFontGetNumberOfGlyphs
#define CGFontGetGlyphAdvances      SGFontGetGlyphAdvances
#define CGFontGetUnitsPerEm         SGFontGetUnitsPerEm







/* Prototypes */
@class CGFont;
typedef CGFont           * CGFontRef;




typedef uint16_t CGGlyph;

STELLA_GRAPHICS_EXPORT void SGFontRelease (SGFontRef self);
STELLA_GRAPHICS_EXPORT SGFontRef SGFontRetain (SGFontRef self);

STELLA_GRAPHICS_EXPORT SGFontRef SGFontCreateWithDataProvider (SGDataProviderRef provider);
STELLA_GRAPHICS_EXPORT SGFontRef SGFontCreateWithFontName (NSString * name);


STELLA_GRAPHICS_EXPORT CFDataRef   CGFontCopyTableForTag (CGFontRef self, uint32_t tag);

STELLA_GRAPHICS_EXPORT CFStringRef CGFontCopyFullName (CGFontRef self);
STELLA_GRAPHICS_EXPORT int         CGFontGetAscent (CGFontRef self);
STELLA_GRAPHICS_EXPORT int         CGFontGetDescent (CGFontRef self);
STELLA_GRAPHICS_EXPORT int         CGFontGetLeading (CGFontRef self);
STELLA_GRAPHICS_EXPORT int         CGFontGetCapHeight (CGFontRef self);
STELLA_GRAPHICS_EXPORT int         CGFontGetXHeight (CGFontRef self);
STELLA_GRAPHICS_EXPORT CGRect      CGFontGetFontBBox (CGFontRef self);
STELLA_GRAPHICS_EXPORT CGFloat     CGFontGetItalicAngle (CGFontRef self);
STELLA_GRAPHICS_EXPORT CGFloat     CGFontGetStemV (CGFontRef self);
STELLA_GRAPHICS_EXPORT CGGlyph     CGFontGetGlyphWithGlyphName (CGFontRef self, CFStringRef name);
STELLA_GRAPHICS_EXPORT CFStringRef CGFontCopyGlyphNameForGlyph (CGFontRef self, CGGlyph glyph);
STELLA_GRAPHICS_EXPORT size_t      CGFontGetNumberOfGlyphs (CGFontRef self);
STELLA_GRAPHICS_EXPORT bool        CGFontGetGlyphAdvances (CGFontRef self, const CGGlyph * glyphs, size_t count, int * advances);
STELLA_GRAPHICS_EXPORT int         CGFontGetUnitsPerEm (CGFontRef self);





