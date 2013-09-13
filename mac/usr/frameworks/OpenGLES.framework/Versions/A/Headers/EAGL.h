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

#import <StellaGraphics/StellaGraphics.h>

/* Compatibility */
#define EAGLSharegroup          ESGLSharegroup
#define EAGLContext             ESGLContext

#define EAGLRenderingAPI                ESGLRenderingAPI
#define kEAGLRenderingAPIOpenGLES1      kESGLRenderingAPIOpenGLES1
#define kEAGLRenderingAPIOpenGLES2      kESGLRenderingAPIOpenGLES2


/* Prototypes */
enum {
    	kESGLRenderingAPIOpenGLES1      = 1,
    	kESGLRenderingAPIOpenGLES2      = 2
};
typedef NSUInteger ESGLRenderingAPI;

@interface ESGLSharegroup : NSObject
{
}
@end

@interface ESGLContext : NSObject
{
}
@property (readonly) ESGLRenderingAPI       API;
@property (readonly) ESGLSharegroup       * sharegroup;

- (id) initWithAPI: (ESGLRenderingAPI) api;
- (id) initWithAPI: (ESGLRenderingAPI) api sharegroup:(ESGLSharegroup *) sharegroup;

+ (BOOL) setCurrentContext:(ESGLContext*) context;
+ (ESGLContext *) currentContext;

@end
