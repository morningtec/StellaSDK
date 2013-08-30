//
// Scene demo
// a cocos2d example
// http://www.cocos2d-iphone.org
//

#import "HelloTest.h"


@implementation HelloWorld

-(id) init
{
	// always call "super" init
	// Apple recommends to re-assign "self" with the "super" return value
	if( (self=[super init] )) {

		// create and initialize a Label
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"Cocos2d 2.0" fontName:@"Marker Felt" fontSize:48];

		// ask director the the window size
		CGSize size = [[CCDirector sharedDirector] winSize];

		// position the label on the center of the screen
		label.position =  ccp( size.width /2 , size.height/2 );

		// add the label as a child to this Layer
		[self addChild: label];
	}
	return self;
}

- (void) dealloc
{
        [super dealloc];
}

@end


#pragma mark - AppController - iOS

#if defined(__CC_PLATFORM_IOS)

@implementation AppController

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	[super application:application didFinishLaunchingWithOptions:launchOptions];

	// Enables High Res mode (Retina Display) on iPhone 4 and maintains low res on all other devices
	if( ! [director_ enableRetinaDisplay:YES] )
		CCLOG(@"Retina Display Not supported");

	// Turn on display FPS
	[director_ setDisplayStats:YES];


	// Default texture format for PNG/BMP/TIFF/JPEG/GIF images
	// It can be RGBA8888, RGBA4444, RGB5_A1, RGB565
	// You can change anytime.
	[CCTexture2D setDefaultAlphaPixelFormat:kCCTexture2DPixelFormat_RGBA8888];


	// If the 1st suffix is not found, then the fallback suffixes are going to used. If none is found, it will try with the name without suffix.
	// On iPad HD  : "-ipadhd", "-ipad",  "-hd"
	// On iPad     : "-ipad", "-hd"
	// On iPhone HD: "-hd"
	CCFileUtils *sharedFileUtils = [CCFileUtils sharedFileUtils];
	[sharedFileUtils setEnableFallbackSuffixes:YES];			// Default: NO. No fallback suffixes are going to be used
	[sharedFileUtils setiPhoneRetinaDisplaySuffix:@"-hd"];		// Default on iPhone RetinaDisplay is "-hd"
	[sharedFileUtils setiPadSuffix:@"-ipad"];					// Default on iPad is "ipad"
	[sharedFileUtils setiPadRetinaDisplaySuffix:@"-ipadhd"];	// Default on iPad RetinaDisplay is "-ipadhd"

	CCScene *scene = [CCScene node];

	[scene addChild: [HelloWorld node] z:0];

	[director_ pushScene: scene];

	return YES;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}
@end

#pragma mark - AppController - Mac

#elif defined(__CC_PLATFORM_MAC)

@implementation AppController

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	[super applicationDidFinishLaunching:aNotification];
	
	CCScene *scene = [CCScene node];
	
	[scene addChild: [HelloWorld node] z:0];
	
	[director_ runWithScene:scene];
}
@end
#endif

