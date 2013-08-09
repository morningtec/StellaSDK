#!/bin/sh

STELLA_BRANCH_ID=v1.3
BUILT_TAGS_FOLDER=/Project/Stella/Debut/release-engineering/built-tags
DEFAULT_JARGEN_FOLDER=/Project/Stella/Debut/tools/xcgen2/example-handroid2

DEFAULT_DST_GIT_FOLDER=/opt/StellaSDK
DEFAULT_DST_GIT_FOLDER_ANDROID_LIBS=/opt/StellaSDK/share/android/libs


# environment setup
if [ ! -d $BUILT_TAGS_FOLDER ]; then
        mkdir -p $BUILT_TAGS_FOLDER
fi


function runCommand
{
        cmd=$1

        #dry-run
        echo "> $cmd"
}


function tagVersions
{
        dstGitFolder=$DEFAULT_DST_GIT_FOLDER

        # set up dest git folder
        if [ ! -d $dstGitFolder ]; then
                mkdir -p $dstGitFolder
        fi

        pushd $dstGitFolder >/dev/null
        if [ "$(git status -s | grep --invert "^??")" != "" ]; then
                echo "Folder not clean: $dstGitFolder"
                return
        fi

        if [ "$(git branch | grep autobuild)" != "" ]; then
                git checkout autobuild >/dev/null 2>&1
        else
                git checkout -b autobuild >/dev/null
        fi

        # maxVersion=(git tag | grep autobuild-$STELLA_BRANCH_ID | cut -d'.' -f3 | sort -n | tail -1)

        versionTag=$(git describe --abbrev=0 --tags)        # v1.3.3
        version=$(echo $versionTag | cut -d'.' -f3)         # 3

        fullVersionTag=$(git describe --tags)               # v1.3.3-1-g58e33e0
        echo "tag: $fullVersionTag"

        if [ "$fullVersionTag" == "$versionTag" ]; then
                return;
        fi

        rev=$version
        for commit in $(git log --reverse --oneline $versionTag..HEAD | cut -d' ' -f1); do
                ((rev ++ ));

                git tag $STELLA_BRANCH_ID.$rev $commit
                # echo "$commit => $rev"
        done

        fullVersionTag=$(git describe --tags)               # v1.3.10
        echo "tag: $fullVersionTag"

        popd >/dev/null
}

function setupSrcGitFolder
{
        srcGitFolder=$1

        # set up source git folder
        if [ ! -d $srcGitFolder ]; then
                echo "Source folder nonexistant: $srcGitFolder"
                return 255
        fi

        pushd $srcGitFolder >/dev/null
        if [ "$(git status -s | grep --invert "^??")" != "" ]; then
                echo "Folder not clean: $srcGitFolder"
                return 255
        fi
        popd >/dev/null

        return 0
}

function setupDstGitFolder
{
        dstGitFolder=$1

        # set up dest git folder
        if [ ! -d $dstGitFolder ]; then
                mkdir -p $dstGitFolder
        fi

        pushd $dstGitFolder >/dev/null
        if [ "$(git status -s | grep --invert "^??")" != "" ]; then
                echo "Folder not clean: $dstGitFolder"
                return 255
        fi

        if [ "$(git branch | grep autobuild)" != "" ]; then
                git checkout autobuild >/dev/null 2>&1
        else
                git checkout -b autobuild >/dev/null
        fi
        popd >/dev/null

        return 0
}

function releaseGitFolder
{
        productID=$1
        srcGitFolder=$2
        dstGitFolder=$3

        echo "Generating $dstGitFolder..."

        setupSrcGitFolder $srcGitFolder
        setupDstGitFolder $dstGitFolder

        if [ $? -eq 255 ]; then
                return
        fi



        pushd $BUILT_TAGS_FOLDER >/dev/null
        if [ ! -f .blitted.$productID.$STELLA_BRANCH_ID.0 ]; then
                touch .blitted.$productID.$STELLA_BRANCH_ID.0    # v1.3.0
        fi

        builtVersion=$(ls .blitted.$productID.$STELLA_BRANCH_ID.* |\
                       sed s@".blitted.$productID.$STELLA_BRANCH_ID."@@g |\
                       sort -n | tail -1)   # 1

        popd >/dev/null



        pushd $srcGitFolder >/dev/null

        srcVersionTag=$(git describe --abbrev=0 --tags)        # v1.3.3
        srcVersion=$(echo $srcVersionTag | sed s@"$STELLA_BRANCH_ID."@@g)  # 3

        srcFullVersionTag=$(git describe --tags)    # v1.3.3-1-g58e33e0

        if [ "$srcFullVersionTag" != "$srcVersionTag" ] ||
           [ $srcVersion -gt $builtVersion ]; then
                action="release"
        else
                action="skip"
        fi

        echo "tag: $srcFullVersionTag blitted: $STELLA_BRANCH_ID.$builtVersion action: $action"

        if [ "$action" != "release" ]; then
                popd >/dev/null
                return 0;
        fi

        rm -fr $srcGitFolder/*
        git reset --hard > /dev/null 2>&1

        rm -fr $dstGitFolder/*
        tar cv --exclude=".git" . 2>/dev/null | tar xv -C $dstGitFolder 2>/dev/null

        pushd $dstGitFolder >/dev/null
        git add .
        if [ "$(git status -s | grep --invert "^??")" != "" ]; then
                git commit -a -m "import $productID $srcFullVersionTag" >/dev/null
        fi
        popd >/dev/null

        touch $BUILT_TAGS_FOLDER/.blitted.$productID.$srcVersionTag


        popd >/dev/null
}


function generateStellaSDKJar
{
        productID=StellaSDKJar
        srcGitFolder=$DEFAULT_JARGEN_FOLDER

        setupSrcGitFolder $srcGitFolder

        if [ $? -eq 255 ]; then
                return 255
        fi


        pushd $BUILT_TAGS_FOLDER >/dev/null
        if [ ! -f .jargen.$productID.$STELLA_BRANCH_ID.0 ]; then
                touch .jargen.$productID.$STELLA_BRANCH_ID.0    # v1.3.0
        fi

        builtVersion=$(ls .jargen.$productID.$STELLA_BRANCH_ID.* |\
                       sed s@".jargen.$productID.$STELLA_BRANCH_ID."@@g |\
                       sort -n | tail -1)   # 1

        popd >/dev/null



        pushd $srcGitFolder >/dev/null

        srcVersionTag=$(git describe --abbrev=0 --tags)        # v1.3.3
        srcVersion=$(echo $srcVersionTag | sed s@"$STELLA_BRANCH_ID."@@g)  # 3

        srcFullVersionTag=$(git describe --tags)    # v1.3.3-1-g58e33e0

        if [ "$srcFullVersionTag" != "$srcVersionTag" ] ||
           [ $srcVersion -gt $builtVersion ]; then
                action="release"
        else
                action="skip"
        fi

        echo "tag: $srcFullVersionTag jargen: $STELLA_BRANCH_ID.$builtVersion action: $action"

        if [ "$action" != "release" ]; then
                popd >/dev/null
                return 0;
        fi


        rm -fr $srcGitFolder/*
        git reset --hard > /dev/null 2>&1

        android update project -p . -s --target android-10 >/dev/null
        ant debug >/dev/null

        if [ ! -d libs ]; then
                mkdir libs
        fi
        cp bin/classes.jar libs/stellasdk2.jar

        touch $BUILT_TAGS_FOLDER/.jargen.$productID.$srcVersionTag

        popd >/dev/null
}


# function generateStellaSDKJar
# {
#         productID=StellaSDKJar
#         srcGitFolder=$DEFAULT_JARGEN_FOLDER
#         dstGitFolder=$DEFAULT_DST_GIT_FOLDER_ANDROID_LIBS
#
#         setupSrcGitFolder $srcGitFolder
#         setupDstGitFolder $dstGitFolder
#
#         if [ $? -eq -1 ]; then
#                 return
#         fi
#
#
#         pushd $BUILT_TAGS_FOLDER >/dev/null
#         if [ ! -f .blitted.$productID.$STELLA_BRANCH_ID.0 ]; then
#                 touch .blitted.$productID.$STELLA_BRANCH_ID.0    # v1.3.0
#         fi
#
#         builtVersion=$(ls .blitted.$productID.$STELLA_BRANCH_ID.* |\
#                        sed s@".blitted.$productID.$STELLA_BRANCH_ID."@@g |\
#                        sort -n | tail -1)   # 1
#
#         popd >/dev/null
#
#
#
#         rm -fr $srcGitFolder/*
#         git reset --hard > /dev/null 2>&1
#
#         rm -fr $dstGitFolder/*
#
#         android update project -p . -s --target android-10
#         rm -fr bin gen; ant debug
#
#         cp bin/classes.jar /opt/StellaSDK/share/android/stellasdk2.jar
#
#         # jar /opt/StellaSDK/share/android/stellasdk2.jar
#
#         popd >/dev/null
# }

arguments=""
while [ "$1" != "" ]; do
        if [ "$1" == "--tags" ]; then
                generateTags=YES;

        elif [ "$1" == "--all" ]; then
                buildAll=YES;

        else
                arguments="$arguments $1"
        fi

        shift
done

if [ "$(echo $arguments | grep GLSprite)" != "" ] ||
   [ "$buildAll" == "YES" ]; then

        releaseGitFolder GLSprite \
            /Project/Stella/iOS-Samples/GLSprite \
            /opt/StellaSDK/samples/GLSprite

        if [ $? -eq 255 ]; then
                exit
        fi
fi

if [ "$(echo $arguments | grep cocos2d-iphone-1.1-RC0)" != "" ] ||
   [ "$buildAll" == "YES" ]; then

        releaseGitFolder cocos2d-iphone-1.1-RC0 \
            /Project/Stella/cocos2d-iphone-1.1-RC0 \
            /opt/StellaSDK/samples/cocos2d-iphone-1.1-RC0

        if [ $? -eq 255 ]; then
                exit
        fi
fi

if [ "$(echo $arguments | grep cocos2d-iphone-2.0)" != "" ] ||
   [ "$buildAll" == "YES" ]; then

        releaseGitFolder cocos2d-iphone-2.0 \
            /Project/Stella/cocos2d-iphone-2.0 \
            /opt/StellaSDK/samples/cocos2d-iphone-2.0

        if [ $? -eq 255 ]; then
                exit
        fi
fi

if [ "$(echo $arguments | grep StellaSDKJar)" != "" ] ||
   [ "$buildAll" == "YES" ]; then

        generateStellaSDKJar

        if [ $? -eq 255 ]; then
                exit
        fi

        releaseGitFolder StellaSDKJar \
            /Project/Stella/Debut/tools/xcgen2/example-handroid2/libs \
            /opt/StellaSDK/share/android/libs

        if [ $? -eq 255 ]; then
                exit
        fi

        releaseGitFolder AndroidMainM \
            /Project/Stella/Debut/tools/xcgen2/android/jni \
            /opt/StellaSDK/share/android/jni

        if [ $? -eq 255 ]; then
                exit
        fi
fi


if [ "$generateTags" == "YES" ]; then
        tagVersions
fi



exit






currentBranch="auto-build"

## begin

mkdir -p /opt/StellaSDK/auto_build/success
mkdir -p /opt/StellaSDK/auto_build/fail

now=`date +%Y-%m-%d-%H%M%S`
log="/opt/StellaSDK/auto_build/success/autobuild-$now-"
err="/opt/StellaSDK/auto_build/fail/autobuild-$now-"


filePath=/Project/Stella/Debut/scratch
cd /Project/Stella/Debut
mkdir -p "$filePath"

copyGlsprite
copyCoco2dIphone




cd /opt/StellaSDK
currentVersion=$(git describe --abbrev=0 --tags)    #v1.3.3
numNon=0
if [ "$currentVersion" == "" ];then
        echo currentVersion="v1.3.0"
else
        numNon=$(git log HEAD...$currentVersion --oneline | wc -l)
fi




# mac compatibility
result_mac_1=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-mac.xcodeproj -target StellaGraphicsPrivate -config Release 1>>$log"StellaGraphicsPrivate-mac.log" 2>>$err"StellaGraphicsPrivate-mac.log")
# check "$result_mac_1"

result_mac_2=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-mac.xcodeproj -target StellaAnimation -config Release 1>>$log"StellaAnimation-mac.log" 2>>$err"StellaAnimation-mac.log")
# check "$result_mac_2"

result_mac_3=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-mac.xcodeproj -target OpenGLES -config Release 1>>$log"OpenGLES-mac.log" 2>>$err"OpenGLES-mac.log")
# check "$result_mac_3"

result_mac_4=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-mac.xcodeproj -target StellaGraphics-es2 -config Release 1>>$log"StellaGraphics-es2-mac.log" 2>>$err"StellaGraphics-es2-mac.log")
# check "$result_mac_4"

cp  /opt/StellaSDK/mac/usr/frameworks/StellaGraphics.framework/Versions/Current/StellaGraphics \
    /opt/StellaSDK/mac/usr/frameworks/StellaGraphics.framework/Versions/Current/StellaGraphics-es2

result_mac_5=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-mac.xcodeproj -target StellaGraphics -config Release 1>>$log"StellaGraphics-mac.log" 2>>$err"StellaGraphics-mac.log")
# check "$result_mac_5"

cp  /opt/StellaSDK/mac/usr/frameworks/StellaGraphics.framework/Versions/Current/StellaGraphics \
    /opt/StellaSDK/mac/usr/frameworks/StellaGraphics.framework/Versions/Current/StellaGraphics-es1

result_mac_6=$(xcodebuild -project /Project/Stella/Debut/StellaKit/xcode/StellaKit-mac.xcodeproj -target StellaKit -config Release 1>>$log"StellaKit-mac.log" 2>>$err"StellaKit-mac.log")
# check "$result_mac_6"

result_mac_7=$(xcodebuild -project /Project/Stella/Debut/StellaKit/xcode/StellaKit-mac.xcodeproj -target UIKit -config Release 1>>$log"UIKit-mac.log" 2>>$err"UIKit-mac.log")
# check "$result_mac_7"

result_mac_8=$(xcodebuild -project /Project/Stella/Debut/StellaMedia/xcode/StellaMedia-mac.xcodeproj -target StellaMedia -config Release 1>>$log"StellaMedia-mac.log" 2>>$err"StellaMedia-mac.log")
# check "$result_mac_8"

result_mac_9=$(xcodebuild -project /Project/Stella/Debut/StellaStore/xcode/StellaStore-mac.xcodeproj -target StellaStore -config Release 1>>$log"StellaStore-mac.log" 2>>$err"StellaStore-mac.log")
# check "$result_mac_9"



# android2s compatibility
result_android2s_1=$(xcodebuild -project /Project/Stella/Debut/Foundation/xcode/stella-rt-android2s.xcodeproj -target Availability -config Release 1>>$log"Availability-android2s.log" 2>>$err"Availability-android2s.log")
# check "$result_android2s_1"

result_android2s_2=$(xcodebuild -project /Project/Stella/Debut/Foundation/xcode/stella-rt-android2s.xcodeproj -target libstella-rt -config Release 1>>$log"rt-android2s.log" 2>>$err"rt-android2s.log")
# check "$result_android2s_2"

result_android2s_3=$(xcodebuild -project /Project/Stella/Debut/External/xcode/stella-base-android2s.xcodeproj -target libstella-base -config Release 1>>$log"base-android2s.log" 2>>$err"base-android2s.log")
# check "$result_android2s_3"

result_android2s_4=$(xcodebuild -project /Project/Stella/Debut/Foundation/xcode/Foundation-android2s.xcodeproj -target libFoundation -config Release 1>>$log"foundation-android2s.log" 2>>$err"foundation-android2s.log")
# check "$result_android2s_4"

result_android2s_5=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-android2s.xcodeproj -target libStellaGraphics-es2 -config Release 1>>$log"graphics-es2-android2s.log" 2>>$err"graphics-es2-android2s.log")
# check "$result_android2s_5"

cp  /opt/StellaSDK/arm-google-android2s/usr/lib/libStellaGraphics.so \
            /opt/StellaSDK/arm-google-android2s/usr/lib/libStellaGraphics-es2.so

result_android2s_6=$(xcodebuild -project /Project/Stella/Debut/StellaGraphics/xcode/StellaGraphics-android2s.xcodeproj -target libStellaGraphics -config Release 1>>$log"graphics-android2s.log" 2>>$err"graphics-android2s.log")
# check "$result_android2s_6"

cp  /opt/StellaSDK/arm-google-android2s/usr/lib/libStellaGraphics.so \
            /opt/StellaSDK/arm-google-android2s/usr/lib/libStellaGraphics-es1.so

result_android2s_7=$(xcodebuild -project /Project/Stella/Debut/StellaKit/xcode/StellaKit-android2s.xcodeproj -target libStellaKit -config Release 1>>$log"stellakit-android2s.log" 2>>$err"stellakit-android2s.log")
# check "$result_android2s_7"

result_android2s_8=$(xcodebuild -project /Project/Stella/Debut/StellaMedia/xcode/StellaMedia-android2s.xcodeproj -target libStellaMedia -config Release 1>>$log"media-android2s.log" 2>>$err"media-android2s.log")
# check "$result_android2s_8"

result_android2s_9=$(xcodebuild -project /Project/Stella/Debut/StellaStore/xcode/StellaStore-android2s.xcodeproj -target libStellaMarket -config Release 1>>$log"market-android2s.log" 2>>$err"market-android2s.log")
# check "$result_android2s_9"


 # extensions
result_extensions_1=$(xcodebuild -project /Project/Stella/Debut/StellaStore/xcode/StellaStore-android2s.xcodeproj -target libStellaMarket -config Release 1>>$log"graphics-extensions.log" 2>>$err"graphics-extensions.log")
# check "$result_extensions_1"



# build tools like xcgen
result_built_tools_1=$(xcodebuild -project /Project/Stella/Debut/External/xcode/xcgen.xcodeproj -target xcgen -config Release 1>>$log"xcgen.log" 2>>$err"xcgen.log")
# check "$result_built_tools_1"

result_built_tools_2=$(xcodebuild -project /Project/Stella/Debut/External/xcode/stella-clang.xcodeproj -target stella-clang -config Release 1>>$log"xcodeproj.log" 2>>$err"xcodeproj.log")
# check "$result_built_tools_2"


cd /opt/StellaSDK
git add .
status=$(git status)
echo "$status" |grep -q "nothing"
if [ $? -eq 0 ]
then
        echo "cocos2d-iphone-1.1-RC0 not commit"
else
        git commit -m "-- import autobuild $currentVersion+$numNon"
fi




