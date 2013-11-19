/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#include <jni.h>

#import <Foundation/Foundation.h>

@interface JNIHelper : NSObject
{
}

@property (nonatomic, assign) JNIEnv      * env;
@property (nonatomic, assign) jobject       clazz;
@property (nonatomic, assign) jclass      * clazzID;

+ (id) _sharedHelper;

- (void) setEnv: (JNIEnv *) env activity: (jobject) clazz activityClazzID: (jclass) clazzID;
- (void) initJVMUIThread;
- (jclass) classIDFromName: (NSString *) name;

- (void) backButtonPressed;

@end

