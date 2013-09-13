/*
 * Copyright (c) 2011 Yeecco Limited
 */

#ifdef __cplusplus

#if defined(__WIN32__)
#if defined(STELLAKIT_INSIDE_BUILD)
#define STELLA_KIT_EXPORT extern "C" __declspec(dllexport)
#else
#define STELLA_KIT_EXPORT extern "C" __declspec(dllimport)
#endif
#else
#define STELLA_KIT_EXPORT extern "C"
#endif

#else

#if defined(__WIN32__)
#if defined(STELLAKIT_INSIDE_BUILD)
#define STELLA_KIT_EXPORT __declspec(dllexport) extern
#else
#define STELLA_KIT_EXPORT __declspec(dllimport) extern
#endif
#else
#define STELLA_KIT_EXPORT extern
#endif


#endif // __cplusplus


/* Version control */
#define __STELLA_KIT_VERSION        0x00010000
#define __STELLA_VERSION            0x00012000


