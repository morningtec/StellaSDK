//
// EAGLViewTest
// This sample/test shows how to create an EAGLView using Interface Builder
//
// http://www.cocos2d-iphone.org
//


//WARNING if you build this for iOS6 or higher, change the names of the xibs in the plist to the ones ending with iOS6, also include the iOS6 xibs to the EAGLViewTest target (in build phases -> compile bundle resources)
//the iPad xib is broken at the moment

#import <UIKit/UIKit.h>

// cocos2d import
#import "cocos2d.h"

// local import
#import "EAGLViewTest.h"

@interface LayerExample : CCLayer
{}
@end

@implementation LayerExample
-(id) init
{
	if( (self=[super init] ) )
	{
		CGSize s = [[CCDirector sharedDirector] winSize];
		CCLabelTTF *label;

#ifdef __IPHONE_3_2
		if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
			label = [CCLabelTTF labelWithString:@"Hello iPad" fontName:@"Marker Felt" fontSize:40];

		else
#endif
			label = [CCLabelTTF labelWithString:@"Hello iPhone" fontName:@"Marker Felt" fontSize:40];

		label.position = ccp(s.width/2, s.height/2);
		[self addChild:label];

	}
	return self;
}

- (void) dealloc
{
	[super dealloc];
}

@end


// CLASS IMPLEMENTATIONS
@implementation EAGLViewTestDelegate

@synthesize window=window_;
@synthesize glView=glView_;

#pragma mark -
#pragma mark Application Delegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	if( ! [CCDirector setDirectorType:kCCDirectorTypeDisplayLink] )
		[CCDirector setDirectorType:kCCDirectorTypeThreadMainLoop];

	CCDirector *director = [CCDirector sharedDirector];
	[director setDisplayFPS:YES];
	[director setDeviceOrientation:kCCDeviceOrientationLandscapeLeft];

	[director setOpenGLView:glView_];

	// Enables High Res mode (Retina Display) on iPhone 4 and maintains low res on all other devices
	if( ! [director enableRetinaDisplay:YES] )
		CCLOG(@"Retina Display Not supported");

	// turn on multiple touches
	[glView_ setMultipleTouchEnabled:YES];

	CCScene *scene = [CCScene node];
	[scene addChild: [LayerExample node]];

	[director runWithScene:scene];

	return YES;
}

// purge memroy
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
	[[CCDirector sharedDirector] purgeCachedData];
}

-(void) applicationDidEnterBackground:(UIApplication*)application
{
	[[CCDirector sharedDirector] stopAnimation];
}

-(void) applicationWillEnterForeground:(UIApplication*)application
{
	[[CCDirector sharedDirector] startAnimation];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
	CCDirector *director = [CCDirector sharedDirector];
	[[director openGLView] removeFromSuperview];
	[director end];

	// release glView here, else it won't be dealloced
	[glView_ release];
	glView_ = nil;
}

#pragma mark -
#pragma mark Init
-(void) dealloc
{
//	[glView_ release];
	[window_ release];
	[super dealloc];
}
@end
