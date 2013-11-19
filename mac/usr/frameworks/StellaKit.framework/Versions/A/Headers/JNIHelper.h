/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import "StellaKitExport.h"

#include <jni.h>

@interface JNIHelper : NSObject
{
}

@property(nonatomic, assign) JNIEnv       * env;
@property(nonatomic, assign) jobject        clazz;
@property(nonatomic, assign) jclass       * clazzID;

+ (id) sharedHelper;

- (jclass) classIDFromName: (NSString *) name;
- (void) backButtonDown;
@end
