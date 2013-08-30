/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

/* Compatibility */
#define CGFloat     SGFloat

#ifdef __LP64__
#define SGFLOAT_IS_DOUBLE 1
#define SGFLOAT_MIN       DBL_MIN
#define SGFLOAT_MAX       DBL_MAX
#else
#define SGFLOAT_IS_DOUBLE 0
#define CGFLOAT_MIN       FLT_MIN
#define CGFLOAT_MAX       FLT_MAX

#endif


/* Prototypes */
#ifdef __LP64__
typedef double SGFloat;
#else
typedef float SGFloat;
#endif

#ifdef __LP64__
#define CGFLOAT_SCAN  %lg
#else
#define CGFLOAT_SCAN  %g
#endif

