/* 
 * Copyright 2011 Yeecco Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "EAGL.h"
#import <StellaGraphics/StellaGraphics.h>

/* Compatibility */
#define EAGLDrawable                                ESGLDrawable
#define kEAGLDrawablePropertyRetainedBacking        kESGLDrawablePropertyRetainedBacking
#define kEAGLDrawablePropertyColorFormat            kESGLDrawablePropertyColorFormat

#define kEAGLColorFormatRGB565      kESGLColorFormatRGB565
#define kEAGLColorFormatRGBA8       kESGLColorFormatRGBA8


/* Prototypes */
STELLA_GRAPHICS_EXPORT NSString * const kESGLDrawablePropertyRetainedBacking;
STELLA_GRAPHICS_EXPORT NSString * const kESGLDrawablePropertyColorFormat;

STELLA_GRAPHICS_EXPORT NSString * const kESGLColorFormatRGB565;
STELLA_GRAPHICS_EXPORT NSString * const kESGLColorFormatRGBA8;


@protocol ESGLDrawable
@property (copy) NSDictionary     * drawableProperties;
@end


@interface ESGLContext (ESGLContextDrawableAdditions)
- (BOOL) renderbufferStorage: (NSUInteger) target fromDrawable: (id<ESGLDrawable>) drawable;
- (BOOL) presentRenderbuffer: (NSUInteger) target;
@end

