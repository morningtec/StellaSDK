/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import <StellaGraphics/StellaGraphicsExport.h>


/* Compatibility */
#define CATransform3D SATransform3D


#define SATransform3DIdentity SATransform3DIdentity


#define CATransform3DIsIdentity          SATransform3DIsIdentity
#define CATransform3DEqualToTransform    SATransform3DEqualToTransform
#define CATransform3DMakeTranslation     SATransform3DMakeTranslation
#define CATransform3DMakeScale           SATransform3DMakeScale
#define CATransform3DMakeRotatation      SATransform3DMakeRotatation
#define CATransform3DTranslate           SATransform3DTranslate
#define CATransform3DScale               SATransform3DScale
#define CATransform3DRotate              SATransform3DRotate
#define CATransform3DConcat              SATransform3DConcat
#define CATransform3DInvert              SATransform3DInvert
#define CATransform3DMakeAffineTransform SATransform3DMakeAffineTransform
#define CATransform3DIsAffine            SATransform3DIsAffine
#define CATransform3DGetAffineTransform  SATransform3DGetAffineTransform




typedef struct _SATransform3D {
        float m11, m12, m13, m14;
        float m21, m22, m23, m24;
        float m31, m32, m33, m34;
        float m41, m42, m43, m44;
} SATransform3D;

STELLA_GRAPHICS_EXPORT const SATransform3D SATransform3DIdentity;

STELLA_GRAPHICS_EXPORT BOOL              SATransform3DIsIdentity (SATransform3D t);
STELLA_GRAPHICS_EXPORT BOOL              SATransform3DEqualToTransform (SATransform3D t1, SATransform3D t2);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DMakeTranslation (CGFloat tx, CGFloat ty, CGFloat tz);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DMakeScale (CGFloat sx, CGFloat sy, CGFloat sz);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DMakeRotatation (CGFloat angle, CGFloat x, CGFloat y, CGFloat z);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DTranslate (SATransform3D t, CGFloat tx, CGFloat ty, CGFloat tz);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DScale (SATransform3D t, CGFloat sx, CGFloat sy, CGFloat sz);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DRotate (SATransform3D t, CGFloat angle, CGFloat x, CGFloat y, CGFloat z);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DConcat (SATransform3D t1, SATransform3D t2);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DInvert (SATransform3D t);
STELLA_GRAPHICS_EXPORT SATransform3D     SATransform3DMakeAffineTransform (CGAffineTransform m);
STELLA_GRAPHICS_EXPORT BOOL              SATransform3DIsAffine (SATransform3D t);
STELLA_GRAPHICS_EXPORT CGAffineTransform SATransform3DGetAffineTransform (SATransform3D t);

