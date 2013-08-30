/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>

/* Translation from CT -> ST */
#define CTFontRef           STFontRef



#define CTFontCreateWithName                STFontCreateWithName

#define CTFontCopyName                      STFontCopyName
#define CTFontCopyFullName                  STFontCopyFullName

#define CTFontGetAscent                     STFontGetAscent
#define CTFontGetDescent                    STFontGetDescent
#define CTFontGetLeading                    STFontGetLeading

#define CTFontGetUnitsPerEm                 STFontGetUnitsPerEm
#define CTFontGetCapHeight                  STFontGetCapHeight
#define CTFontGetXHeight                    STFontGetXHeight


#define CTFontGetAdvancesForGlyphs          STFontGetAdvancesForGlyphs
#define CTFontGetGlyphsForCharacters        STFontGetGlyphsForCharacters
#define CTFontCreateWithGraphicsFont        STFontCreateWithGraphicsFont

#define CTFontCopyGraphicsFont              STFontCopyGraphicsFont


#define CTFontOptions                       STFontOptions

/* Stella implementation */
@class STFont;
typedef STFont            * STFontRef;

@class STFontDescriptor;
typedef STFontDescriptor    * STFontDescriptorRef;


extern const NSString * kSTFontCopyrightNameKey;
extern const NSString * kSTFontFamilyNameKey;
extern const NSString * kSTFontSubFamilyNameKey;
extern const NSString * kSTFontStyleNameKey;
extern const NSString * kSTFontUniqueNameKey;
extern const NSString * kSTFontFullNameKey;
extern const NSString * kSTFontVersionNameKey;
extern const NSString * kSTFontPostScriptNameKey;
extern const NSString * kSTFontTrademarkNameKey;
extern const NSString * kSTFontManufacturerNameKey;
extern const NSString * kSTFontDesignerNameKey;
extern const NSString * kSTFontDescriptionNameKey;
extern const NSString * kSTFontVendorURLNameKey;
extern const NSString * kSTFontDesignerURLNameKey;
extern const NSString * kSTFontLicenseNameKey;
extern const NSString * kSTFontLicenseURLNameKey;
extern const NSString * kSTFontSampleTextNameKey;
extern const NSString * kSTFontPostScriptCIDNameKey;


STELLA_GRAPHICS_EXPORT STFontRef STFontCreateWithName (CFStringRef name, CGFloat size, const SGAffineTransform * matrix);

STELLA_GRAPHICS_EXPORT SGFloat STFontGetSize (STFontRef font);

STELLA_GRAPHICS_EXPORT CFStringRef STFontCopyFullName (STFontRef font);
STELLA_GRAPHICS_EXPORT CFStringRef STFontCopyName (STFontRef font, CFStringRef key);



STELLA_GRAPHICS_EXPORT CGFloat STFontGetAscent (STFontRef self);
STELLA_GRAPHICS_EXPORT CGFloat STFontGetDescent (STFontRef self);
STELLA_GRAPHICS_EXPORT CGFloat STFontGetLeading (STFontRef self);
STELLA_GRAPHICS_EXPORT unsigned STFontGetUnitsPerEm (STFontRef font);
STELLA_GRAPHICS_EXPORT SGFloat STFontGetCapHeight (STFontRef font);
STELLA_GRAPHICS_EXPORT SGFloat STFontGetXHeight (STFontRef font);


STELLA_GRAPHICS_EXPORT double STFontGetAdvancesForGlyphs (STFontRef self, int orientation, const SGGlyph glyphs[], SGSize advances[], size_t count);

STELLA_GRAPHICS_EXPORT bool STFontGetGlyphsForCharacters (STFontRef font, const unichar characters[], SGGlyph glyphs[] , size_t count);

STELLA_GRAPHICS_EXPORT SGFontRef STFontCopyGraphicsFont (STFontRef font, STFontDescriptorRef attributes);
STELLA_GRAPHICS_EXPORT STFontRef STFontCreateWithGraphicsFont ( SGFontRef graphicsFont, SGFloat size,
                                                                SGAffineTransform * matrix, STFontDescriptorRef attributes );

