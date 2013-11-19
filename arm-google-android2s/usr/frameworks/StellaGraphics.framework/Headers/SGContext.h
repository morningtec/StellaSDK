/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "StellaGraphicsExport.h"
#import "SGGeometry.h"

#define CGContext    SGContext
#define CGContextRef SGContextRef

@class CGContext;
typedef CGContext     * CGContextRef;

#import "SGColor.h"
#import "SGFont.h"
#import "SGImage.h"
#import "SGLayer.h"
#import "SGPath.h"
// #import "SGShading.h"
// #import "SGPDFPage.h"


/* Compatibility */
#define CGBlendMode                 SGBlendMode
#define kCGBlendModeNormal          kSGBlendModeNormal
#define kCGBlendModeMultiply        kSGBlendModeMultiply
#define kCGBlendModeScreen          kSGBlendModeScreen
#define kCGBlendModeOverlay         kSGBlendModeOverlay
#define kCGBlendModeDarken          kSGBlendModeDarken
#define kCGBlendModeLighten         kSGBlendModeLighten
#define kCGBlendModeColorDodge      kSGBlendModeColorDodge
#define kCGBlendModeColorBurn       kSGBlendModeColorBurn
#define kCGBlendModeHardLight       kSGBlendModeHardLight
#define kCGBlendModeSoftLight       kSGBlendModeSoftLight
#define kCGBlendModeDifference      kSGBlendModeDifference
#define kCGBlendModeExclusion       kSGBlendModeExclusion
#define kCGBlendModeHue             kSGBlendModeHue
#define kCGBlendModeSaturation      kSGBlendModeSaturation
#define kCGBlendModeColor           kSGBlendModeColor
#define kCGBlendModeLuminosity      kSGBlendModeLuminosity
#define kCGBlendModeClear           kSGBlendModeClear
#define kCGBlendModeCopy            kSGBlendModeCopy
#define kCGBlendModeSourceIn        kSGBlendModeSourceIn
#define kCGBlendModeSourceOut       kSGBlendModeSourceOut
#define kCGBlendModeSourceAtop      kSGBlendModeSourceAtop
#define kCGBlendModeDestinationOver kSGBlendModeDestinationOver
#define kCGBlendModeDestinationIn   kSGBlendModeDestinationIn
#define kCGBlendModeDestinationOut  kSGBlendModeDestinationOut
#define kCGBlendModeDestinationAtop kSGBlendModeDestinationAtop
#define kCGBlendModeXOR             kSGBlendModeXOR
#define kCGBlendModePlusDarker      kSGBlendModePlusDarker
#define kCGBlendModePlusLighter     kSGBlendModePlusLighter

#define CGInterpolationQuality      SGInterpolationQuality
#define kCGInterpolationDefault     kSGInterpolationDefault
#define kCGInterpolationNone        kSGInterpolationNone
#define kCGInterpolationLow         kSGInterpolationLow
#define kCGInterpolationHigh        kSGInterpolationHigh

#define CGLineCap                   SGLineCap
#define kCGLineCapButt              kSGLineCapButt
#define kCGLineCapRound             kSGLineCapRound
#define kCGLineCapSquare            kSGLineCapSquare

#define CGLineJoin                  SGLineJoin
#define kCGLineJoinMiter            kSGLineJoinMiter
#define kCGLineJoinRound            kSGLineJoinRound
#define kCGLineJoinBevel            kSGLineJoinBevel

#define CGTextEncoding              SGTextEncoding
#define kCGEncodingFontSpecific     kSGEncodingFontSpecific
#define kCGEncodingMacRoman         kSGEncodingMacRoman

#define kCGTextFill                 kSGTextFill
#define kCGTextStroke               kSGTextStroke
#define kCGTextFillStroke           kSGTextFillStroke
#define kCGTextInvisible            kSGTextInvisible
#define kCGTextFillClip             kSGTextFillClip
#define kCGTextStrokeClip           kSGTextStrokeClip
#define kCGTextFillStrokeClip       kSGTextFillStrokeClip
#define kCGTextClip                 kSGTextClip

#define kCGEncodingFontSpecific     kSGEncodingFontSpecific
#define kCGEncodingMacRoman         kSGEncodingMacRoman

#define CGPathDrawingMode           SGPathDrawingMode
#define kCGPathFill                 kSGPathFill
#define kCGPathEOFill               kSGPathEOFill
#define kCGPathStroke               kSGPathStroke
#define kCGPathFillStroke           kSGPathFillStroke
#define kCGPathEOFillStroke         kSGPathEOFillStroke


#define CGContextFlush                              SGContextFlush
#define CGContextRelease                            SGContextRelease
#define CGContextRetain                             SGContextRetain
#define CGContextSynchronize                        SGContextSynchronize

#define CGContextSaveGState                         SGContextSaveGState
#define CGContextRestoreGState                      SGContextRestoreGState

#define CGContextGetInterpolationQuality            SGContextGetInterpolationQuality
#define CGContextSetFlatness                        SGContextSetFlatness
#define CGContextSetInterpolationQuality            SGContextSetInterpolationQuality
#define CGContextSetLineCap                         SGContextSetLineCap
#define CGContextSetLineDash                        SGContextSetLineDash
#define CGContextSetLineJoin                        SGContextSetLineJoin
#define CGContextSetLineWidth                       SGContextSetLineWidth
#define CGContextSetMiterLimit                      SGContextSetMiterLimit
#define CGContextSetPatternPhase                    SGContextSetPatternPhase
#define CGContextSetFillPattern                     SGContextSetFillPattern
#define CGContextSetRenderingIntent                 SGContextSetRenderingIntent
#define CGContextSetShouldAntialias                 SGContextSetShouldAntialias
#define CGContextSetStrokePattern                   SGContextSetStrokePattern
#define CGContextSetBlendMode                       SGContextSetBlendMode
#define CGContextSetAllowsAntialiasing              SGContextSetAllowsAntialiasing
#define CGContextSetShouldSmoothFonts               SGContextSetShouldSmoothFonts

#define CGContextAddArc                             SGContextAddArc
#define CGContextAddArcToPoint                      SGContextAddArcToPoint
#define CGContextAddCurveToPoint                    SGContextAddCurveToPoint
#define CGContextAddLines                           SGContextAddLines
#define CGContextAddLineToPoint                     SGContextAddLineToPoint
#define CGContextAddPath                            SGContextAddPath
#define CGContextAddQuadCurveToPoint                SGContextAddQuadCurveToPoint
#define CGContextAddRect                            SGContextAddRect
#define CGContextAddRects                           SGContextAddRects
#define CGContextBeginPath                          SGContextBeginPath
#define CGContextClosePath                          SGContextClosePath
#define CGContextMoveToPoint                        SGContextMoveToPoint
#define CGContextAddEllipseInRect                   SGContextAddEllipseInRect

#define CGContextClearRect                          SGContextClearRect
#define CGContextDrawPath                           SGContextDrawPath
#define CGContextEOFillPath                         SGContextEOFillPath
#define CGContextFillPath                           SGContextFillPath
#define CGContextFillRect                           SGContextFillRect
#define CGContextFillRects                          SGContextFillRects
#define CGContextFillEllipseInRect                  SGContextFillEllipseInRect
#define CGContextStrokePath                         SGContextStrokePath
#define CGContextStrokeRect                         SGContextStrokeRect
#define CGContextStrokeRectWithWidth                SGContextStrokeRectWithWidth
#define CGContextReplacePathWithStrokedPath         SGContextReplacePathWithStrokedPath
#define CGContextStrokeEllipseInRect                SGContextStrokeEllipseInRect
#define CGContextStrokeLineSegments                 SGContextStrokeLineSegments

#define CGContextIsPathEmpty                        SGContextIsPathEmpty
#define CGContextGetPathCurrentPoint                SGContextGetPathCurrentPoint
#define CGContextGetPathBoundingBox                 SGContextGetPathBoundingBox
#define CGContextPathContainsPoint                  SGContextPathContainsPoint

#define CGContextClip                               SGContextClip
#define CGContextEOClip                             SGContextEOClip
#define CGContextClipToRect                         SGContextClipToRect
#define CGContextClipToRects                        SGContextClipToRects
#define CGContextGetClipBoundingBox                 SGContextGetClipBoundingBox
#define CGContextClipToMask                         SGContextClipToMask

#define CGContextSetAlpha                           SGContextSetAlpha
#define CGContextSetCMYKFillColor                   SGContextSetCMYKFillColor
#define CGContextSetFillColor                       SGContextSetFillColor
#define CGContextSetCMYKStrokeColor                 SGContextSetCMYKStrokeColor
#define CGContextSetFillColorSpace                  SGContextSetFillColorSpace
#define CGContextSetFillColorWithColor              SGContextSetFillColorWithColor
#define CGContextSetGrayFillColor                   SGContextSetGrayFillColor
#define CGContextSetGrayStrokeColor                 SGContextSetGrayStrokeColor
#define CGContextSetRGBFillColor                    SGContextSetRGBFillColor
#define CGContextSetRGBStrokeColor                  SGContextSetRGBStrokeColor
#define CGContextSetShadow                          SGContextSetShadow
#define CGContextSetShadowWithColor                 SGContextSetShadowWithColor
#define CGContextSetStrokeColor                     SGContextSetStrokeColor
#define CGContextSetStrokeColorSpace                SGContextSetStrokeColorSpace
#define CGContextSetStrokeColorWithColor            SGContextSetStrokeColorWithColor

#define CGContextConcatCTM                          SGContextConcatCTM
#define CGContextGetCTM                             SGContextGetCTM
#define CGContextRotateCTM                          SGContextRotateCTM
#define CGContextScaleCTM                           SGContextScaleCTM
#define CGContextTranslateCTM                       SGContextTranslateCTM

#define CGContextBeginTransparencyLayer             SGContextBeginTransparencyLayer
#define CGContextEndTransparencyLayer               SGContextEndTransparencyLayer

#define CGContextDrawImage                          SGContextDrawImage

// #define CGContextDrawPDFPage                        SGContextDrawPDFPage

// #define CGContextDrawShading                        SGContextDrawShading

#define CGContextBeginPage                          SGContextBeginPage
#define CGContextEndPage                            SGContextEndPage

#define CGContextShowGlyphs                         SGContextShowGlyphs
#define CGContextShowGlyphsAtPoint                  SGContextShowGlyphsAtPoint
#define CGContextShowGlyphsWithAdvances             SGContextShowGlyphsWithAdvances

#define CGContextGetTextMatrix                      SGContextGetTextMatrix
#define CGContextGetTextPosition                    SGContextGetTextPosition
#define CGContextSelectFont                         SGContextSelectFont
#define CGContextSetCharacterSpacing                SGContextSetCharacterSpacing
#define CGContextSetFont                            SGContextSetFont
#define CGContextSetFontSize                        SGContextSetFontSize
#define CGContextSetTextDrawingMode                 SGContextSetTextDrawingMode
#define CGContextSetTextMatrix                      SGContextSetTextMatrix
#define CGContextSetTextPosition                    SGContextSetTextPosition
#define CGContextShowText                           SGContextShowText
#define CGContextShowTextAtPoint                    SGContextShowTextAtPoint

#define CGContextGetUserSpaceToDeviceSpaceTransform SGContextGetUserSpaceToDeviceSpaceTransform
#define CGContextConvertPointToDeviceSpace          SGContextConvertPointToDeviceSpace
#define CGContextConvertPointToUserSpace            SGContextConvertPointToUserSpace
#define CGContextConvertSizeToDeviceSpace           SGContextConvertSizeToDeviceSpace
#define CGContextConvertSizeToUserSpace             SGContextConvertSizeToUserSpace
#define CGContextConvertRectToDeviceSpace           SGContextConvertRectToDeviceSpace
#define CGContextConvertRectToUserSpace             SGContextConvertRectToUserSpace

/* Prototypes */
typedef enum {
        kSGBlendModeNormal,
        kSGBlendModeMultiply,
        kSGBlendModeScreen,
        kSGBlendModeOverlay,
        kSGBlendModeDarken,
        kSGBlendModeLighten,
        kSGBlendModeColorDodge,
        kSGBlendModeColorBurn,
        kSGBlendModeHardLight,
        kSGBlendModeSoftLight,
        kSGBlendModeDifference,
        kSGBlendModeExclusion,
        kSGBlendModeHue,
        kSGBlendModeSaturation,
        kSGBlendModeColor,
        kSGBlendModeLuminosity,
        kSGBlendModeClear,
        kSGBlendModeCopy,
        kSGBlendModeSourceIn,
        kSGBlendModeSourceOut,
        kSGBlendModeSourceAtop,
        kSGBlendModeDestinationOver,
        kSGBlendModeDestinationIn,
        kSGBlendModeDestinationOut,
        kSGBlendModeDestinationAtop,
        kSGBlendModeXOR,
        kSGBlendModePlusDarker,
        kSGBlendModePlusLighter,
} SGBlendMode;

typedef enum {
        kSGInterpolationDefault     = 0,
        kSGInterpolationNone        = 1,
        kSGInterpolationLow         = 2,
        kSGInterpolationMedium      = 4,
        kSGInterpolationHigh        = 3,
} SGInterpolationQuality;

typedef enum {
        kSGLineCapButt,
        kSGLineCapRound,
        kSGLineCapSquare,
} SGLineCap;

typedef enum {
        kSGLineJoinMiter,
        kSGLineJoinRound,
        kSGLineJoinBevel,
} SGLineJoin;


typedef enum {
        kSGTextFill,
        kSGTextStroke,
        kSGTextFillStroke,
        kSGTextInvisible,
        kSGTextFillClip,
        kSGTextStrokeClip,
        kSGTextFillStrokeClip,
        kSGTextClip,
} SGTextDrawingMode;

typedef enum {
        kSGEncodingFontSpecific,
        kSGEncodingMacRoman,
} SGTextEncoding;

typedef enum {
        kSGPathFill,
        kSGPathEOFill,
        kSGPathStroke,
        kSGPathFillStroke,
        kSGPathEOFillStroke,
} SGPathDrawingMode;


STELLA_GRAPHICS_EXPORT void                   SGContextFlush (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextRelease (SGContextRef context);
STELLA_GRAPHICS_EXPORT SGContextRef           SGContextRetain (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextSynchronize (SGContextRef context);

STELLA_GRAPHICS_EXPORT void                   SGContextSaveGState (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextRestoreGState (SGContextRef context);

STELLA_GRAPHICS_EXPORT SGInterpolationQuality SGContextGetInterpolationQuality (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFlatness (SGContextRef context, SGFloat flatness);
STELLA_GRAPHICS_EXPORT void                   SGContextSetInterpolationQuality (SGContextRef context, SGInterpolationQuality quality);
STELLA_GRAPHICS_EXPORT void                   SGContextSetLineCap (SGContextRef context, SGLineCap lineCap);
STELLA_GRAPHICS_EXPORT void                   SGContextSetLineDash (SGContextRef context, SGFloat phase, const SGFloat * lengths, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextSetLineJoin (SGContextRef context, SGLineJoin lineJoin);
STELLA_GRAPHICS_EXPORT void                   SGContextSetLineWidth (SGContextRef context, SGFloat width);
STELLA_GRAPHICS_EXPORT void                   SGContextSetMiterLimit (SGContextRef context, SGFloat miterLimit);
STELLA_GRAPHICS_EXPORT void                   SGContextSetPatternPhase (SGContextRef context, SGSize phase);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFillPattern (SGContextRef context, SGPatternRef pattern, const SGFloat * components);
STELLA_GRAPHICS_EXPORT void                   SGContextSetRenderingIntent (SGContextRef context, SGColorRenderingIntent renderingIntent);
STELLA_GRAPHICS_EXPORT void                   SGContextSetShouldAntialias (SGContextRef context, bool yesOrNo);
STELLA_GRAPHICS_EXPORT void                   SGContextSetStrokePattern (SGContextRef context, SGPatternRef pattern, const SGFloat * components);
STELLA_GRAPHICS_EXPORT void                   SGContextSetBlendMode (SGContextRef context, SGBlendMode blendMode);
STELLA_GRAPHICS_EXPORT void                   SGContextSetAllowsAntialiasing (SGContextRef context, bool yesOrNo);
STELLA_GRAPHICS_EXPORT void                   SGContextSetShouldSmoothFonts (SGContextRef context, bool yesOrNo);

STELLA_GRAPHICS_EXPORT void                   SGContextAddArc (SGContextRef context, SGFloat x, SGFloat y, SGFloat radius, SGFloat startRadian, SGFloat endRadian, bool clockwise);
STELLA_GRAPHICS_EXPORT void                   SGContextAddArcToPoint (SGContextRef context, SGFloat x1, SGFloat y1, SGFloat x2, SGFloat y2, SGFloat radius);
STELLA_GRAPHICS_EXPORT void                   SGContextAddCurveToPoint (SGContextRef context, SGFloat cx1, SGFloat cy1, SGFloat cx2, SGFloat cy2, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void                   SGContextAddLines (SGContextRef context, const SGPoint * points, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextAddLineToPoint (SGContextRef context, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void                   SGContextAddPath (SGContextRef context, SGPathRef path);
STELLA_GRAPHICS_EXPORT void                   SGContextAddQuadCurveToPoint (SGContextRef context, SGFloat cx1, SGFloat cy1, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void                   SGContextAddRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextAddRects (SGContextRef context, const SGRect * rects, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextBeginPath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextClosePath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextMoveToPoint (SGContextRef context, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void                   SGContextAddEllipseInRect (SGContextRef context, SGRect rect);

STELLA_GRAPHICS_EXPORT void                   SGContextClearRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextDrawPath (SGContextRef context, SGPathDrawingMode pathMode);
STELLA_GRAPHICS_EXPORT void                   SGContextEOFillPath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextFillPath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextFillRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextFillRects (SGContextRef context, const SGRect * rects, size_t count);
STELLA_GRAPHICS_EXPORT void                   SGContextFillEllipseInRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextStrokePath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextStrokeRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextStrokeRectWithWidth (SGContextRef context, SGRect rect, SGFloat width);
STELLA_GRAPHICS_EXPORT void                   SGContextReplacePathWithStrokedPath (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextStrokeEllipseInRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextStrokeLineSegments (SGContextRef context, const SGPoint * points, size_t count);

STELLA_GRAPHICS_EXPORT bool                   SGContextIsPathEmpty (SGContextRef context);
STELLA_GRAPHICS_EXPORT SGPoint                SGContextGetPathCurrentPoint (SGContextRef context);
STELLA_GRAPHICS_EXPORT SGRect                 SGContextGetPathBoundingBox (SGContextRef context);
STELLA_GRAPHICS_EXPORT bool                   SGContextPathContainsPoint (SGContextRef context, SGPoint point, SGPathDrawingMode pathMode);

STELLA_GRAPHICS_EXPORT void                   SGContextClip (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextEOClip (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextClipToRect (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT void                   SGContextClipToRects (SGContextRef context, const SGRect * rects, unsigned count);
STELLA_GRAPHICS_EXPORT SGRect                 SGContextGetClipBoundingBox (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextClipToMask (SGContextRef context, SGRect rect, SGImageRef image);

STELLA_GRAPHICS_EXPORT void                   SGContextSetAlpha (SGContextRef context, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetCMYKFillColor (SGContextRef context, SGFloat c, SGFloat m, SGFloat y, SGFloat k, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFillColor (SGContextRef context, const SGFloat * components);
STELLA_GRAPHICS_EXPORT void                   SGContextSetCMYKStrokeColor (SGContextRef context, SGFloat c, SGFloat m, SGFloat y, SGFloat k, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFillColorSpace (SGContextRef context, SGColorSpaceRef colorSpace);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFillColorWithColor (SGContextRef context, SGColorRef color);
STELLA_GRAPHICS_EXPORT void                   SGContextSetGrayFillColor (SGContextRef context, SGFloat gray, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetGrayStrokeColor (SGContextRef context, SGFloat gray, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetRGBFillColor (SGContextRef context, SGFloat r, SGFloat g, SGFloat b, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetRGBStrokeColor (SGContextRef context, SGFloat r, SGFloat g, SGFloat b, SGFloat alpha);
STELLA_GRAPHICS_EXPORT void                   SGContextSetShadow (SGContextRef context, SGSize offset, SGFloat blur);
STELLA_GRAPHICS_EXPORT void                   SGContextSetShadowWithColor (SGContextRef context, SGSize offset, SGFloat blur, SGColorRef color);
STELLA_GRAPHICS_EXPORT void                   SGContextSetStrokeColor (SGContextRef context, const SGFloat * components);
STELLA_GRAPHICS_EXPORT void                   SGContextSetStrokeColorSpace (SGContextRef context, SGColorSpaceRef colorSpace);
STELLA_GRAPHICS_EXPORT void                   SGContextSetStrokeColorWithColor (SGContextRef context, SGColorRef color);

STELLA_GRAPHICS_EXPORT void                   SGContextConcatCTM (SGContextRef context, SGAffineTransform matrix);
STELLA_GRAPHICS_EXPORT SGAffineTransform      SGContextGetCTM (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextRotateCTM (SGContextRef context, SGFloat radians);
STELLA_GRAPHICS_EXPORT void                   SGContextScaleCTM (SGContextRef context, SGFloat scalex, SGFloat scaley);
STELLA_GRAPHICS_EXPORT void                   SGContextTranslateCTM (SGContextRef context, SGFloat translatex, SGFloat translatey);

STELLA_GRAPHICS_EXPORT void                   SGContextBeginTransparencyLayer (SGContextRef context, CFDictionaryRef unused);
STELLA_GRAPHICS_EXPORT void                   SGContextEndTransparencyLayer (SGContextRef context);

STELLA_GRAPHICS_EXPORT void                   SGContextDrawImage (SGContextRef context, SGRect rect, SGImageRef image);

// STELLA_GRAPHICS_EXPORT void                   SGContextDrawPDFPage (SGContextRef context, SGPDFPageRef page);

// STELLA_GRAPHICS_EXPORT void                   SGContextDrawShading (SGContextRef context, SGShadingRef shading);

STELLA_GRAPHICS_EXPORT void                   SGContextBeginPage (SGContextRef context, const SGRect * mediaBox);
STELLA_GRAPHICS_EXPORT void                   SGContextEndPage (SGContextRef context);

STELLA_GRAPHICS_EXPORT void                   SGContextShowGlyphs (SGContextRef context, const SGGlyph * glyphs, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextShowGlyphsAtPoint (SGContextRef context, SGFloat x, SGFloat y, const SGGlyph * glyphs, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextShowGlyphsWithAdvances (SGContextRef context, const SGGlyph * glyphs, const SGSize * advances, unsigned count);

STELLA_GRAPHICS_EXPORT SGAffineTransform      SGContextGetTextMatrix (SGContextRef context);
STELLA_GRAPHICS_EXPORT SGPoint                SGContextGetTextPosition (SGContextRef context);
STELLA_GRAPHICS_EXPORT void                   SGContextSelectFont (SGContextRef context, const char * name, SGFloat size, SGTextEncoding encoding);
STELLA_GRAPHICS_EXPORT void                   SGContextSetCharacterSpacing (SGContextRef context, SGFloat spacing);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFont (SGContextRef context, SGFontRef font);
STELLA_GRAPHICS_EXPORT void                   SGContextSetFontSize (SGContextRef context, SGFloat size);
STELLA_GRAPHICS_EXPORT void                   SGContextSetTextDrawingMode (SGContextRef context, SGTextDrawingMode textMode);
STELLA_GRAPHICS_EXPORT void                   SGContextSetTextMatrix (SGContextRef context, SGAffineTransform matrix);
STELLA_GRAPHICS_EXPORT void                   SGContextSetTextPosition (SGContextRef context, SGFloat x, SGFloat y);
STELLA_GRAPHICS_EXPORT void                   SGContextShowText (SGContextRef context, const char * text, unsigned count);
STELLA_GRAPHICS_EXPORT void                   SGContextShowTextAtPoint (SGContextRef context, SGFloat x, SGFloat y, const char * text, unsigned count);

STELLA_GRAPHICS_EXPORT SGAffineTransform      SGContextGetUserSpaceToDeviceSpaceTransform (SGContextRef context);
STELLA_GRAPHICS_EXPORT SGPoint                SGContextConvertPointToDeviceSpace (SGContextRef context, SGPoint point);
STELLA_GRAPHICS_EXPORT SGPoint                SGContextConvertPointToUserSpace (SGContextRef context, SGPoint point);
STELLA_GRAPHICS_EXPORT SGSize                 SGContextConvertSizeToDeviceSpace (SGContextRef context, SGSize size);
STELLA_GRAPHICS_EXPORT SGSize                 SGContextConvertSizeToUserSpace (SGContextRef context, SGSize size);
STELLA_GRAPHICS_EXPORT SGRect                 SGContextConvertRectToDeviceSpace (SGContextRef context, SGRect rect);
STELLA_GRAPHICS_EXPORT SGRect                 SGContextConvertRectToUserSpace (SGContextRef context, SGRect rect);


