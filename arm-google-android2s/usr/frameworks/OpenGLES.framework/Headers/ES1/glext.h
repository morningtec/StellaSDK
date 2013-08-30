/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

#include <GLES/gl.h>
#include <GLES/glext.h>
#import <StellaGraphics/StellaGraphicsExport.h>

#define GL_BGRA                         GL_BGRA_EXT


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


