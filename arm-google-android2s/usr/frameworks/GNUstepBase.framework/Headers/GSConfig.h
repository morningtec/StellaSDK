#if defined (__APPLE__)
#import "GSConfig.darwin.h"
#elif defined (__ANDROID__)
#import "GSConfig.android.h"
#else
#error "GSConfig.h not found for platform"
#endif