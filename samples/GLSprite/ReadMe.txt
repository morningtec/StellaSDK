### GLSprite ###

================================================================================
DESCRIPTION:

The GLSprite sample application shows how to create a texture from an image. By looking at the code, you'll learn how to use Core Graphics to create a bitmap context and draw an image into the context. You'll then see how to use OpenGL ES to create a texture from the image data. 

================================================================================
BUILD REQUIREMENTS:

iPhone SDK 3.1 and later

================================================================================
RUNTIME REQUIREMENTS:

iPhone OS 3.1 and later

================================================================================
PACKAGING LIST:

GLSpriteAppDelegate.h
GLSpriteAppDelegate.m
The UIApplication  delegate class, which is the central controller of the application.

EAGLView.h
EAGLView.m
This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass. The view content is basically an EAGL surface you render your OpenGL scene into. Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.

main.m
The main entry point for the GLSprite application.

================================================================================
CHANGES FROM PREVIOUS VERSIONS:

Version 1.8
Updated for iPhone OS 3.1:
Set texture parameters before creating the texture. This will save texture memory and texture loading time.
Use CADisplayLink as the preferred method for controlling animation timing, and fall back to NSTimer when running on a pre 3.1 device where CADisplayLink is not available.

Version 1.7
-Updated for and tested with iPhone OS 2.0. First public release.
 
Version 1.6
-Fixed typographical error.

Version 1.5
-Updated for Beta 6. There were  changes to the EAGL API.
-Changed the status bar to black.
-Modified the Default.png file.

Version 1.4
-Updated for Beta 5.
-Restructured the application to use a xib file. 
-Removed the Texture2D class. The texture is now created using data from a bitmap context.
-Changed the dimensions and case of the png file.

Version 1.3
-Updated for Beta 4.
-Changed the project setting for Code Signing.
-Removed the error that prevented the application from running in the simulator.

Version 1.2
-Updated for Beta 3. 
-Updated art files

Version 1.1
Updated for Beta 2

================================================================================
Copyright (C) 2009 Apple Inc. All rights reserved.