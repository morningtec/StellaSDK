/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifdef __cplusplus

#if defined (__WIN32__)
#if defined (STELLA_GRAPHICS_INSIDE_BUILD)
#define STELLA_GRAPHICS_EXPORT extern "C" __declspec(dllexport)
#else
#define STELLA_GRAPHICS_EXPORT extern "C" __declspec(dllimport)
#endif
#else
#define STELLA_GRAPHICS_EXPORT extern "C"
#endif

#else

#if defined (__WIN32__)
#if defined (STELLA_GRAPHICS_INSIDE_BUILD)
#define STELLA_GRAPHICS_EXPORT __declspec(dllexport) extern
#else
#define STELLA_GRAPHICS_EXPORT __declspec(dllimport) extern
#endif
#else
#define STELLA_GRAPHICS_EXPORT extern
#endif


#endif // __cplusplus


/* Version control */
#define __STELLA_GRAPHICS_VERSION   0x00010000

