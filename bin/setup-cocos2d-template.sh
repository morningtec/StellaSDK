#/bin/sh

arguments=""
while [ "$1" != "" ]; do
        arguments="$arguments $1"
        shift
done

COCOS2D_DEFAULT_VERSION_V1=1.1-RC0
COCOS2D_DEFAULT_VERSION_V2=2.0

STELLASDK_SAMPLES_FOLDER=/opt/StellaSDK/samples
DEFAULT_PROJECT_NAME=Sample

files=""

if [ "$(echo $arguments | grep "\-"v2)" != "" ]; then
        version=$COCOS2D_DEFAULT_VERSION_V2
else
        version=$COCOS2D_DEFAULT_VERSION_V1
fi

if [ "$(echo $arguments | grep "\-"p)" != "" ]; then
        projectName=$(echo $arguments | sed s@'.*-p[ ]*\([^ ]*\).*'@\\1@1)
else
        projectName=$DEFAULT_PROJECT_NAME
fi

if [ "$version" == "1.1-RC0" ]; then
        cocos2dFiles="\
        cocos2d \
        external/FontLabel \
        Resources/Info.plist \
        Resources/Fonts/fps_images.png \
        tests/samples/HelloWorld.m \
        tests/samples/HelloWorld.h \
        "
fi

function createProject
{
        if [ ! -d $projectName ]; then
                mkdir $projectName
        fi

        cd $projectName
        
        if [ ! -d $projectName.xcodeproj ]; then
                mkdir $projectName.xcodeproj
        fi
        
        cp -af  $STELLASDK_SAMPLES_FOLDER/cocos2d-templates/cocos2d-iphone-$version-template.xcodeproj/project.pbxproj \
                $projectName.xcodeproj/


        if [ ! -d tests/samples ]; then
                mkdir -p tests/samples
        fi

        if [ ! -d external ]; then
                mkdir -p external
        fi

        for f in $cocos2dFiles; do
                dirname=$(dirname $f);
                if [ ! -d "$dirname" ]; then
                        mkdir -p $dirname
                fi

                cp -af  $STELLASDK_SAMPLES_FOLDER/cocos2d-iphone-$version/$f $dirname/
        done


        # cp -af  $STELLASDK_SAMPLES_FOLDER/cocos2d-iphone-$version/cocos2d ./
        # cp -af  $STELLASDK_SAMPLES_FOLDER/cocos2d-iphone-$version/tests/samples/HelloWorld.* tests/samples/
        # cp -af  $STELLASDK_SAMPLES_FOLDER/cocos2d-iphone-$version/external/FontLabel external/
}


echo -ne "creating template for $projectName using cocos2d-iphone-$version ..."

createProject

echo "done"