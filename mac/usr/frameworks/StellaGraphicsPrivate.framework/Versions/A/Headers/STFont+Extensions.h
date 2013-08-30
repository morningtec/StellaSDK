/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <StellaGraphics/STFont.h>

/* Prototypes */
// @class CGWindow;


@interface STFont : NSObject
@end

@interface STFont (Internal)

- (SGPoint)positionOfGlyph:(SGGlyph)current precededByGlyph:(SGGlyph)previous isNominal:(BOOL *)isNominalp;


@end
