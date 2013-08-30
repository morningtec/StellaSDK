/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <UIKit/UIKit.h>
#import <jni.h>

#if defined (__STELLA_NANDROID)
/* to be deprecated below */
struct android_app;

extern int main_android_pre (struct android_app * app);
extern int main_android (int argc, char * argv []);

@interface StellaAndroidApp : NSObject
@end

@implementation StellaAndroidApp (AppMain)
- (void) launchWithAndroidApp: (struct android_app *) app
{
        main_android_pre (app);
        main_android (0, NULL);
}
@end
/* to be deprecated above */
#endif



extern int main_handroid (int argc, char * argv[]);

#if defined (__STELLA_HANDROID)
extern int main_handroid_pre (void * param);
#endif

#if defined (__STELLA_HANDROID) || defined (__STELLA_NANDROID)
@interface SGAppLauncher : NSObject
@end


@implementation SGAppLauncher (AppMain)
#if defined (__STELLA_HANDROID)
- (void) launchHAndroidAppWithParam: (void *) param
{
        main_handroid_pre (param);
        main_handroid (0, NULL);
}
#endif

#if defined (__STELLA_NANDROID)
- (void) launchNAndroidAppWithParam: (void *) param
{
        main_android_pre (param);
        main_android (0, NULL);
}
#endif
@end


#else /* none defined */

typedef int     (*AndroidAppMainPROC) (int argc, char * argv[]);
extern AndroidAppMainPROC       g_android_main;

jint JNI_OnLoad (JavaVM * vm, void * reserved)
{
    g_android_main      = main_android;
    return JNI_VERSION_1_4;
}
#endif





