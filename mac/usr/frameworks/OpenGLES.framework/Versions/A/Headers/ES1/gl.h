/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

#include <GL/gl.h>
#include <GL/glext.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#define glOrthof                 glOrtho
#define glFrustumf               glFrustum
#define glClearDepthf            glClearDepth


#define GL_POINT_SPRITE_OES             GL_POINT_SPRITE
#define GL_COORD_REPLACE_OES            GL_COORD_REPLACE



#define GL_FRAMEBUFFER_OES              GL_FRAMEBUFFER_EXT
#define GL_COLOR_ATTACHMENT0_OES        GL_COLOR_ATTACHMENT0_EXT
#define GL_FRAMEBUFFER_COMPLETE_OES     GL_FRAMEBUFFER_COMPLETE_EXT

#define GL_RENDERBUFFER_OES             GL_RENDERBUFFER_EXT
#define GL_RENDERBUFFER_WIDTH_OES       GL_RENDERBUFFER_WIDTH_EXT
#define GL_RENDERBUFFER_HEIGHT_OES      GL_RENDERBUFFER_HEIGHT_EXT


#define GL_DEPTH_COMPONENT16_OES        GL_DEPTH_COMPONENT16
#define GL_DEPTH_COMPONENT24_OES        GL_DEPTH_COMPONENT24
#define GL_FRAMEBUFFER_BINDING_OES      GL_FRAMEBUFFER_BINDING

#define GL_DEPTH_ATTACHMENT_OES         GL_DEPTH_ATTACHMENT

#define GL_RGBA8_OES                    GL_RGBA8


#define glGenFramebuffersOES            glGenFramebuffersEXT
#define glIsFramebufferOES              glIsFramebufferEXT
#define glBindFramebufferOES            glBindFramebufferEXT
#define glFramebufferTexture2DOES       glFramebufferTexture2DEXT
#define glDeleteFramebuffersOES         glDeleteFramebuffersEXT
#define glCheckFramebufferStatusOES     glCheckFramebufferStatusEXT
#define glGenerateMipmapOES             glGenerateMipmapEXT
#define glRenderbufferStorageOES        glRenderbufferStorageEXT

#define glGenRenderbuffersOES           glGenRenderbuffersEXT
#define glBindRenderbufferOES           glBindRenderbufferEXT
#define glDeleteRenderbuffersOES        glDeleteRenderbuffersEXT
#define glFramebufferRenderbufferOES    glFramebufferRenderbufferEXT
#define glGetRenderbufferParameterivOES glGetRenderbufferParameterivEXT


// #define glGenRenderbuffersOES           glGenRenderbuffersIMP
// #define glBindRenderbufferOES           glBindRenderbufferIMP
// #define glDeleteRenderbuffersOES        glDeleteRenderbuffersIMP
// #define glFramebufferRenderbufferOES    glFramebufferRenderbufferIMP
// #define glGetRenderbufferParameterivOES glGetRenderbufferParameterivIMP




STELLA_GRAPHICS_EXPORT void glGenRenderbuffersIMP (GLsizei n, GLuint * renderbuffers);
STELLA_GRAPHICS_EXPORT void glBindRenderbufferIMP (GLenum target, GLuint renderbuffer);
STELLA_GRAPHICS_EXPORT void glDeleteRenderbuffersIMP (GLsizei n, const GLuint * renderbuffers);
STELLA_GRAPHICS_EXPORT void glFramebufferRenderbufferIMP (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
STELLA_GRAPHICS_EXPORT void glGetRenderbufferParameterivIMP (GLenum target, GLenum pname, GLint * params);


