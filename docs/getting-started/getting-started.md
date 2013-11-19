## Getting started with Stella SDK


### About Stella SDK

Stella SDK is an Objective-C based smartphone app development frameworks that allows existing skill sets to be reused for multiple smartphone platforms. It is comprised of the clang-based compiler tools and frameworks necessary for the app generation.

#### Stella SDK at a glance

Frameworks that comes with Stella SDK include:

* Foundation: OpenStep compliant Foundation framework
* OpenGLES: OpenGLES framework
* StellaGraphics: Quartz2D/CoreGraphics compatible framework
* StellaAnimation: QuartzCore/CoreAnimation compatible framework
* StellaKit: UIKit compatible framework (without user interface elements)
* StellaStore: StoreKit compatible framework and commercialisation APIs(Amazon IAP, Tapjoy etc)
* StellaMedia: Stella frameworks for audio and video processing
* cocos2d-iphone 1.1/2.0 (a popular iOS game engine written in Objective-C)


### Installing Stella SDK

Stella SDK can be cloned and installed from github. Get the installer from github:

    $ cd /opt
    $ git clone https://github.com/morningtec/StellaSDK.git
    $ /opt/StellaSDK/bin/stella-config --install

You need to restart Xcode and Terminal after the installation. Update Stella SDK for the first time and then periodically afterwards. Suppose the latest release is r2.3:

    $ cd /opt/StellaSDK
    $ git reset --hard origin/r2.3
    $ /opt/StellaSDK/bin/stella-config --install


### Porting iOS OpenGLES2 app GLES2Sample to Android

This GLES2Sample demonstrates how to create an OpenGL ES 2.0 compatible project. 
Using sibtool and xcgen, it can be ported to Android instantly.



#### Running GLES2Sample in Stella Android simulator

iOS developers use Xcode to develop apps on Macs. Stella SDK allows developers to use the same Xcode tool to develop for Android. Xcode projects contain organised information on source codes, resources, and settings required to build the apps. Creating separate Xcode projects targeting different platforms (e.g. iOS and Android) is usually considered best practice to source control and management.

Stella SDK comes with a tool called xcgen to generate Stella Xcode projects. Using xcgen, iOS Xcode projects can be automatically converted to ones that target either the Stella Android Simulator on Mac or real Android devices.

Using the iOS app demo GLES2Sample as an example, a separate Xcode project targeting the Android Simulator can be generated in the same folder as the iOS Xcode project:

    $ cd /opt/StellaSDK/samples/GLES2Sample
    $ xcgen --project GLES2Sample --target mac --es2

GLES2Sample uses OpenGLESv2 hence Stella SDK needs to be configured:

    $ stella-config --switch=es2

Note that Xib files need to be converted to sib files before they can be used in Stella Xcode projects.

    $ cd /opt/StellaSDK/samples/GLES2Sample/
    $ sibtool -x MainWindow.xib

Now open the newly generated xcode project, and hit Run. The Stella Android simulator will be launched:

    $ open /opt/StellaSDK/samples/GLES2Sample/GLES2Sample-mac.xcodeproj


![GLES2Sample-3G](GLES2Sample-3G.png)

The App is running , but it is small for the simulator.The reasion is the app is iPhone3GEmulationMode, going to fix it, set iPhone3GEmulationMode UIScreenMode to reduce the resolution of the virtual screen.

Put the following code in main  after initializing autorelease pool.

	int main(int argc, char *argv[]) {
	    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	#if defined (__STELLA_VERSION_MAX_ALLOWED)
	    [UIScreen mainScreen].currentMode   = [UIScreen mainScreen].iPhone3GEmulationMode;
	#endif
	    int retVal = UIApplicationMain(argc, argv, nil, @"AppDelegate");
	    [pool release];
	    return retVal;
	}

Then clean the GLES2 target and run again:

![GLES2Sample Mac Xcodeproj](GLES2Sample-mac-xcodeproj.png)



#### Getting GLES2Sample to run on Android devices

Having GLES2Sample running in Stella Android simulator is one step away from getting the same programme running in Android devices. Using xcgen again, this time targeting Android devices:

    $ cd /opt/StellaSDK/samples/GLES2Sample
    $ xcgen --project GLES2Sample --target android --es2

A GLES2Sample-android folder is created along with the xcode project. The structure is as follows:

    GLES2Sample-android/AndroidManifest.xml
    GLES2Sample-android/jni/Android.mk
    GLES2Sample-android/libs/stellasdk2.jar
    GLES2Sample-android/res/drawable/icon_android.png
    GLES2Sample-android/res/values/strings.xml
    GLES2Sample-android/src/com/yourcompany/GLES2Sample/MainHActivity.java


Now open the xcode project and hit Build:

    $ open /opt/StellaSDK/samples/GLES2Sample/GLES2Sample-android.xcodeproj


Run the fix_assets.sh scripte to fix multilanguage issue.

    $ cd /opt/StellaSDK/samples/GLES2Sample/GLES2Sample-android
    $ stella-config --fix-assets


Plug in your Android device, the apk file can then be generated inside GLES2Sample-android folder:

    $ cd /opt/StellaSDK/samples/GLES2Sample/GLES2Sample-android
    $ android update project -p . -s -t android-10 -n GLES2Sample
    $ ndk-build
    $ ant clean; ant debug install


Please note that Google’s Android Virtual Devices (AVDs) are not supported as targets to install app made using Stella SDK. Real devices are required for testing and deployment of apps.

You should now be able to launch GLES2Sample on your Android device!



### Adapting your source code for Stella SDK

Following the above instruction, you can now generate a Stella SDK Xcode project for you app. To adapt the source codes for use with Stella SDK, however, you will find some minor tweakings necessarys.


#### Code changes due to class names

Stella SDK header files and class names are intentionally renamed from the compatible UIKit equivalents. This is to avoid conflicts with existing frameworks. For example, to use QuartzCore/CoreAnimation in Stella SDK, you will need to take care of both header imports as well as class names:

    #if defined (__STELLA_VERSION_MAX_ALLOWED)
    #import <StellaAnimation/StellaAnimation.h>
    #else
    #import <QuartzCore/QuartzCore.h>
    #endif

Stella SDK defines compatibility macros in the header files so that classes can be used just as documented:

    // Stella SDK compatibility macros defined in SAESGLLayer.h:
    #define CAEAGLLayer         SAESGLLayer

    // To use the class
    CAEAGLLayer *eaglLayer = (CAEAGLLayer*) self.layer;

class names Stella SDK follows the pattern:

Framework                     | Apple prefix   | Stella SDK prefix
-                             | -              | -
Foundation                    | NS             | NS
CoreGraphics/StellaGraphics   | CG             | SG
CoreAnimation/StellaAnimation | CA             | SA
UIKit/StellaKit               | UI             | UI
StoreKit/StellaStore          | SK             | SS
AVFoundation/StellaMedia      | AV             | AV

Under normal circumstances, Stella SDK’s compatibility layer will cause the compiler to replace the Standard prefixes to Stella SDK prefixes automatically and no more code change is necessary.

When prefix automatic replacement is deliberately not used, such as the CADisplayLink class in the GLES2Sample demo, manual replacement is required:

    #if defined (__STELLA_VERSION_MAX_ALLOWED)
    displayLink = [NSClassFromString(@"SADisplayLink") displayLinkWithTarget:self selector:@selector(drawView)];
    #else
    displayLink = [NSClassFromString(@"CADisplayLink") displayLinkWithTarget:self selector:@selector(drawView)];
    #endif


#### Code changes due to OpenGLES

For OpenGL renderbuffer objects that intend to have a CALayer backing, Stella implementation of glRenderBuffer functions (IMP) are required to replace the OpenGLES counterparts (OES).

    #if defined (__STELLA_VERSION_MAX_ALLOWED)
        glGenRenderbuffersIMP(1, &viewRenderbuffer);
    #else
        glGenRenderbuffersOES(1, &viewRenderbuffer);
    #endif


### Run StellaSDK with XCode 5


* The Stella Android simulator need the X11 libraries. Download [**xquartz**](http://xquartz.macosforge.org/downloads/SL/XQuartz-2.7.4.dmg) and  install it.

* After installation, Reboot computer.

* Open the Xcode 5 mac project, choose the Base SDK to macosx 10.8, 

![header_search_path](xcode5_base_sdk.png)

And change the X11 path from $(SDKROOT)/usr/X11 to /opt/X11 (X11 default  installation directory) in the Header Search Paths and Library Search Paths build settings.


![header_search_path](xcode5_x11_header_search_path.png)

![library_search_path](xcode5_x11_library_search_path.png)



### Revision history

Revision    | Notes
-           | -
20120611    | Initial version
20120612    | Climber demo added
20120704    | Added Android APK generation for the demos
20120802    | Updated for xcgen with auto folder generation
20120805    | Minor updates and pedantic guides
20120815    | Minor corrections, updates on AVDs and nib support
20120917    | Minor corrections and update folder structure with latest xcgen
20130730    | Changes for Stella SDK II
20131101    | GLES2Sample demo instead of GLSprite
20131209    | Added run StellaSDK with XCode 5











