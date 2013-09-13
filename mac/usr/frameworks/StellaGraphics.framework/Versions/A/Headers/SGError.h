/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <stdint.h>

/* Compatibility */


#define CGError                         SGError
#define kCGErrorSuccess                 kSGErrorSuccess
#define kCGErrorFailure                 kSGErrorFailure
#define kCGErrorIllegalArgument         kSGErrorIllegalArgument
#define kCGErrorInvalidConnection       kSGErrorInvalidConnection
#define kCGErrorInvalidContext          kSGErrorInvalidContext




/* Prototypes */
typedef enum {
        kCGErrorSuccess                 = 0,
        kCGErrorFailure                 = 1000,
        kCGErrorIllegalArgument         = 1001,
        kCGErrorInvalidConnection       = 1002,
        kCGErrorInvalidContext          = 1003,
} CGError;
