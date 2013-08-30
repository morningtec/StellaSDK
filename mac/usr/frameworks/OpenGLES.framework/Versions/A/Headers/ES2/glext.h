/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

#include <GL/gl.h>
#include <GL/glext.h>
#import <StellaGraphics/StellaGraphicsExport.h>


#define GL_DEPTH_COMPONENT16_OES        GL_DEPTH_COMPONENT16
#define GL_DEPTH_COMPONENT24_OES        GL_DEPTH_COMPONENT24
#define GL_FRAMEBUFFER_BINDING_OES      GL_FRAMEBUFFER_BINDING

#define GL_RGBA8_OES                    GL_RGBA8


STELLA_GRAPHICS_EXPORT void glGenRenderbuffersIMP (GLsizei n, GLuint * renderbuffers);
STELLA_GRAPHICS_EXPORT void glBindRenderbufferIMP (GLenum target, GLuint renderbuffer);
STELLA_GRAPHICS_EXPORT void glDeleteRenderbuffersIMP (GLsizei n, const GLuint * renderbuffers);
STELLA_GRAPHICS_EXPORT void glFramebufferRenderbufferIMP (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
STELLA_GRAPHICS_EXPORT void glGetRenderbufferParameterivIMP (GLenum target, GLenum pname, GLint * params);



#define glDeleteVertexArraysOES         glDeleteVertexArraysAPPLE
#define glGenVertexArraysOES            glGenVertexArraysAPPLE
#define glBindVertexArrayOES            glBindVertexArrayAPPLE






