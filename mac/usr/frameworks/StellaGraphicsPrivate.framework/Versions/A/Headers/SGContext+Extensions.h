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

#import <StellaGraphics/SGContext.h>

/* Prototypes - to be reviewed */
@class SGWindow;

@interface SGContext : NSObject
@end

@interface SGContext (Internal)
+ (SGContext *) createContextWithSize: (SGSize) size
                               window: (SGWindow *) window;

- (id) initWithSize: (SGSize) size
             window: (SGWindow *) SGWindow;

@end


STELLA_GRAPHICS_EXPORT void SGContextSetCTM (SGContextRef self,SGAffineTransform matrix);