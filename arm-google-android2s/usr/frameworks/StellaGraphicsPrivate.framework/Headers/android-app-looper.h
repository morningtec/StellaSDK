/*
 * Stella Debut
 * Wenqi Chen 10/2008
 */

#import "android-app-jvm.h"

#import <Foundation/Foundation.h>

enum {
        SGAppCommandInputChanged    = 0x00000000,
        SGAppCommandInitWindow,
        SGAppCommandTermWindow,
        SGAppCommandWindowResized,
        SGAppCommandWindowRedrawNeeded,
        SGAppCommandContentRectChanged,
        SGAppCommandGainedFocus,
        SGAppCommandLostFocus,
        SGAppCommandConfigChanged,
        SGAppCommandLowMemory,
        SGAppCommandStart,
        SGAppCommandResume,
        SGAppCommandSaveState,
        SGAppCommandPause,
        SGAppCommandStop,
        SGAppCommandDestroy,

        /*CP 12.12 SGAppCommand Value range [0x00  0x7f]*/
        SGAppCommandKeyEvent        = 0x00000040,
        SGAppCommandMotionEvent     = 0x00000041,

        SGAppCommandJump            = 0x4a554d50,   /* JUMP 8 */
};
typedef int32_t SGAppCommand;

#define SGAppCommandPrimaryTypeMask       0x000000ff
#define SGAppCommandEventActionMask       0xffff0000

enum {
        SGAppMotionActionDown,
        SGAppMotionActionUp,
        SGAppMotionActionMove,
        SGAppMotionActionCancel,

        SGAppMotionActionOutSize,
        SGAppMotionActionPointerDown,
        SGAppMotionActionPointerUp,
};
typedef int32_t SGAppMotionAction;

typedef union {
        int32_t                 key;
        SGAppMotionAction       motion;
} SGAppAction;



extern void android_main (struct android_app * app);
// extern void android_main_stella (struct android_app * app);

@interface StellaAndroidApp : NSObject
{
}

+ (void) initialize;

+ (StellaAndroidApp *) sharedApp;

- (void) launchWithAndroidApp: (struct android_app *) app;


@end

