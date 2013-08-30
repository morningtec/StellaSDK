#!/usr/bin/python

import os;
import shutil;
import re;

def switch_es_mode (es_mode):

        sgbin_path      = '/opt/StellaSDK/mac/usr/frameworks/StellaGraphics.framework/Versions/A';
        shutil.copy (sgbin_path + '/StellaGraphics-' + es_mode, sgbin_path + '/StellaGraphics');

        sgbin_path      = '/opt/StellaSDK/arm-google-android2s/usr/lib';
        shutil.copy (sgbin_path + '/libStellaGraphics-' + es_mode + '.so', sgbin_path + '/libStellaGraphics.so');

        return 0;


def fix_assets (folder):

        if not os.path.isdir (folder + '/assets/Resources'):
                print ('assets/Resources folder does not exist')
                return 0;

        for (root, dirs, files) in os.walk (folder + '/assets/Resources'):
                for d in dirs:
                        store_tag   = root + '/STELLA_Store_' + d;

                        if not os.path.isfile (store_tag):
                                open (store_tag, 'a').close ();
                                print 'created tag: ' + store_tag;

        return 0;


def install_pbcompspecs (home_folder):

        specs_folder    = \
        home_folder + '/Library/Application Support/Developer/Shared/Xcode/Specifications';

        if (not os.path.isdir (specs_folder)):
                os.makedirs (specs_folder);

        os.chdir (specs_folder);
        specfile    = open ('stella-clang-2.0.pbcompspec', 'w');

        specfile.write ('''
(
    {
        Identifier = cn.morningtec.compilers.stella.clang.2.0;
        BasedOn    = com.apple.compilers.llvm.clang.1_0;
        Name       = "Stella Clang 2.0";
        Version    = "cn.morningtec.compilers.stella.clang.2.0";
        Vendor     = "cn.morningtec";
        ExecPath   = "/opt/StellaSDK/bin/stella-clang";
        Architectures = (i386);

        SupportsZeroLink              = No;
        SupportsPredictiveCompilation = No;
        SupportsHeadermaps            = Yes;
        DashIFlagAcceptsHeadermaps    = Yes;

        Options = (
        {
            Name = SDKROOT;
            Type = Path;
            CommandLineArgs = ();
        },

        );

    }
)

''');

        specfile.close ();


def install_bash_profile (home_folder):

        os.chdir (home_folder);

        if not os.path.isfile ('.bash_profile'):
                profile         = open ('.bash_profile', 'w');

        else:
                profile         = open ('.bash_profile', 'r');

                text_lines      = profile.read ().split ('\n');

                regex_begin     = re.compile (r'^# STELLASDK BEGIN');
                regex_end       = re.compile (r'^# STELLASDK END');

                section_found   = 0;
                filtered_text   = '';

                for line in text_lines:
                        # print 'line: ' + line;
                        if (section_found == 0):
                                if regex_begin.search (line):
                                        # print ('section found');
                                        section_found   = 1;

                                else:
                                        if (filtered_text == ''):
                                                filtered_text   = line;
                                        else:
                                                filtered_text   = filtered_text + '\n' + line;

                        elif (section_found == 1):

                                if regex_end.search (line):
                                        section_found   = 0;

                profile.close ();

                profile         = open ('.bash_profile', 'w');
                profile.write (filtered_text);



        profile.write ('''

# STELLASDK BEGIN
function prependPath () {
        entry=$1;
        PATH="$(echo $PATH | sed "s@:$entry@@g")";
        PATH="$PATH:$entry"
}

ANDROID_NDK_PATH=/opt/StellaSDK/android-ndk-r8d
ANDROID_SDK_PATH=/opt/StellaSDK/android-sdk-macosx

prependPath "$ANDROID_SDK_PATH/platform-tools"
prependPath "$ANDROID_SDK_PATH/tools"
prependPath "$ANDROID_NDK_PATH"
prependPath "/opt/StellaSDK/bin"

# STELLASDK END

''');

        profile.close ();







g_cocos2dv1_template_path   = '/opt/StellaSDK/samples/cocos2d-iphone-1.1-RC0';
g_cocos2dv1_files   = [ \
    'cocos2d', \
    'external/FontLabel', \
    'Resources/Info.plist', \
    'Resources/Fonts/fps_images.png', \
    'Resources/Fonts/MarkerFelt.ttc', \
    'CocosDenshion/CocosDenshion', \
    'CocosDenshion/CocosDenshionExtras', \
    'CocosDenshion/TestsAndDemos/FancyRatMeteringDemo', \
    'tests/samples/HelloWorld.m', \
    'tests/samples/HelloWorld.h' ];


g_cocos2dv2_template_path   = '/opt/StellaSDK/samples/cocos2d-iphone-2.0';
g_cocos2dv2_files   = [ \
    'cocos2d', \
    'external/kazmath', \
    'Resources/Icon.png', \
    'Resources/Default.png', \
    'Resources/Info.plist', \
    'Resources/Fonts/MarkerFelt.fnt', \
    'Resources/Fonts/fps_images.png', \
    'tests/main.m', \
    'tests/Prefix.pch', \
    'tests/HelloTest.m', \
    'tests/HelloTest.h', \
    'tests/BaseAppController.m', \
    'tests/BaseAppController.h', \
    'CocosDenshion/CocosDenshion', \
    'CocosDenshion/CocosDenshionExtras', \
    'CocosDenshion/TestsAndDemos/FancyRatMeteringDemo' ];



def blit_folder_contents (src_folder, src_files, dst_folder):

        for f in src_files:
                if os.path.isdir (src_folder + '/' + f):
                        if os.path.isdir (dst_folder + '/' + f):
                                shutil.rmtree (dst_folder + '/' + f);

                        shutil.copytree (src_folder + '/' + f, dst_folder + '/' + f);

                elif os.path.isfile (src_folder + '/' + f):
                        d   = os.path.dirname (f);

                        if not os.path.isdir (dst_folder + '/' + d):
                                os.makedirs (dst_folder + '/' + d);

                        shutil.copy (src_folder + '/' + f, dst_folder + '/' + f);


def blit_cocos2d_template_xcodeproj (src_folder, dst_folder, name):

        if not os.path.isdir (dst_folder):
                os.makedirs (dst_folder);

        xcodeproj_path  = dst_folder + '/' + name + '.xcodeproj';

        if not os.path.isdir (xcodeproj_path):
                os.makedirs (xcodeproj_path);

        shutil.copy ( src_folder + '/template.xcodeproj/project.pbxproj', \
                      xcodeproj_path + '/project.pbxproj');


def setup_cocos2dv1_template (folder, name):

        src_folder      = g_cocos2dv1_template_path;
        src_files       = g_cocos2dv1_files;
        dst_folder      = folder + '/' + name;

        blit_cocos2d_template_xcodeproj (src_folder, dst_folder, name);
        blit_folder_contents (src_folder, src_files, dst_folder);


def setup_cocos2dv2_template (folder, name):

        src_folder      = g_cocos2dv2_template_path;
        src_files       = g_cocos2dv2_files;
        dst_folder      = folder + '/' + name;

        blit_cocos2d_template_xcodeproj (src_folder, dst_folder, name);
        blit_folder_contents (src_folder, src_files, dst_folder);

