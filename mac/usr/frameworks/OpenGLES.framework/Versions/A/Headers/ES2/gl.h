/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

#include <GL/gl.h>
#include <GL/glext.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#define glOrthof                        glOrtho
#define glFrustumf                      glFrustum
#define glClearDepthf                   glClearDepth

#define GL_POINT_SPRITE_OES             GL_POINT_SPRITE
#define GL_COORD_REPLACE_OES            GL_COORD_REPLACE
#define GL_DEPTH24_STENCIL8_OES         GL_DEPTH24_STENCIL8

#define GL_RGB565                       0x8D62


#define glBindRenderbuffer              glBindRenderbufferEXT
#define glDeleteRenderbuffers           glDeleteRenderbuffersEXT
#define glGenRenderbuffers              glGenRenderbuffersEXT
#define glRenderbufferStorage           glRenderbufferStorageEXT
#define glGetRenderbufferParameteriv    glGetRenderbufferParameterivEXT
#define glIsFramebuffer                 glIsFramebufferEXT
#define glBindFramebuffer               glBindFramebufferEXT
#define glDeleteFramebuffers            glDeleteFramebuffersEXT
#define glGenFramebuffers               glGenFramebuffersEXT
#define glCheckFramebufferStatus        glCheckFramebufferStatusEXT
#define glFramebufferTexture2D          glFramebufferTexture2DEXT
#define glFramebufferRenderbuffer       glFramebufferRenderbufferEXT

#define glGenerateMipmap                glGenerateMipmapEXT
