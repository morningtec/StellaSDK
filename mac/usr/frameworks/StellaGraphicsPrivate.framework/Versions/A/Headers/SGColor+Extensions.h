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

#import <StellaGraphics/SGColor.h>

STELLA_GRAPHICS_EXPORT SGColorRef  SGColorCreateGenericGray (CGFloat gray,CGFloat a);
STELLA_GRAPHICS_EXPORT SGColorRef  SGColorCreateGenericRGB (CGFloat r, CGFloat g, CGFloat b, CGFloat a);
STELLA_GRAPHICS_EXPORT SGColorRef  SGColorCreateGenericCMYK (CGFloat c, CGFloat m, CGFloat y, CGFloat k, CGFloat a);

