/*
 * Stella Debut
 * Wenqi Chen 10/2008
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphicsExport.h>

extern void SGQuietLog (NSString * format, ...);

extern void SGVerboseErrorLog (NSString * key, NSString * formatVA, ...);
extern void SGVerboseDebugLog (NSString * key, NSString * formatVA, ...);
extern void SGVerboseAssert (NSString * key, BOOL condition, NSString * conditionString, char * file, int line);
extern void SGMethodCallTrace (NSString * level, id self, SEL selector);

        /* todo */
        #define SGCallDump(level, format ...)           /**/

#if defined (__STELLA_DEBUG)
        #define SGErrorLog(key, format ...)             SGVerboseErrorLog (key, format)
        #define SGDebugLog(key, format ...)             SGVerboseDebugLog (key, format)
        #define SGAssert(key, condition)                SGVerboseAssert (key, condition, @#condition, __FILE__, __LINE__)
        #define SGCallTrace(key)                        SGMethodCallTrace (key, self, _cmd)

#else
        #define SGErrorLog(key, format ...)             NSLog (format)
        #define SGDebugLog(key, format ...)             /**/
        #define SGAssert(key, condition)                /**/
        #define SGCallTrace(key)                        /**/
#endif





#define SGExceptionAbstract() { \
        NSString      * methodFormat; \
        methodFormat    = [ NSString stringWithFormat: @"[%@%@ %@]", NSStringFromClass (isa), \
                            (Class) self == [self class] ? @" +" : [NSString stringWithFormat: @"<%p> -", self], NSStringFromSelector (_cmd) ]; \
        [NSException raise: NSInternalInconsistencyException format: @"%@ abstract method", methodFormat]; \
}

#define SGExceptionUnimplemented() { \
        NSString      * methodFormat; \
        methodFormat    = [ NSString stringWithFormat: @"[%@%@ %@]", NSStringFromClass (isa), \
                            (Class) self == [self class] ? @" +" : [NSString stringWithFormat: @"<%p> -", self], NSStringFromSelector (_cmd) ]; \
        [NSException raise: NSInternalInconsistencyException format: @"%@ unimplemented method", methodFormat]; \
}

#define SGExceptionUnimplementedFunction() { \
        [NSException raise: NSInternalInconsistencyException format: @"%@ unimplemented function", __func__]; \
}


