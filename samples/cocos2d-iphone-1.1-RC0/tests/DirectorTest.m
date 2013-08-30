//
// Sprite Demo
// a cocos2d example
// http://www.cocos2d-iphone.org
//

// cocos import
#import "cocos2d.h"

// local import
#import "DirectorTest.h"

//located in tests/DirectorTest
#import "ScrollViewController.h"

static int sceneIdx=-1;
static NSString *transitions[] = {

	@"Director1",
    @"ScrollViewTest",

};

Class nextAction(void);
Class backAction(void);
Class restartAction(void);

Class nextAction()
{
	sceneIdx++;
	sceneIdx = sceneIdx % ( sizeof(transitions) / sizeof(transitions[0]) );
	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

Class backAction()
{
	sceneIdx--;
	int total = ( sizeof(transitions) / sizeof(transitions[0]) );
	if( sceneIdx < 0 )
		sceneIdx += total;

	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

Class restartAction()
{
	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

#pragma mark -
#pragma mark DirectorTest

@implementation DirectorTest
-(id) init
{
	if( (self = [super init]) ) {


		CGSize s = [[CCDirector sharedDirector] winSize];

		CCLabelTTF *label = [CCLabelTTF labelWithString:[self title] fontName:@"Arial" fontSize:26];
		[self addChild: label z:1];
		[label setPosition: ccp(s.width/2, s.height-50)];

		NSString *subtitle = [self subtitle];
		if( subtitle ) {
			CCLabelTTF *l = [CCLabelTTF labelWithString:subtitle fontName:@"Thonburi" fontSize:16];
			[self addChild:l z:1];
			[l setPosition:ccp(s.width/2, s.height-80)];
		}

		CCMenuItemImage *item1 = [CCMenuItemImage itemFromNormalImage:@"b1.png" selectedImage:@"b2.png" target:self selector:@selector(backCallback:)];
		CCMenuItemImage *item2 = [CCMenuItemImage itemFromNormalImage:@"r1.png" selectedImage:@"r2.png" target:self selector:@selector(restartCallback:)];
		CCMenuItemImage *item3 = [CCMenuItemImage itemFromNormalImage:@"f1.png" selectedImage:@"f2.png" target:self selector:@selector(nextCallback:)];

		CCMenu *menu = [CCMenu menuWithItems:item1, item2, item3, nil];

		menu.position = CGPointZero;
		item1.position = ccp( s.width/2 - 100,30);
		item2.position = ccp( s.width/2, 30);
		item3.position = ccp( s.width/2 + 100,30);
		[self addChild: menu z:1];
	}
	return self;
}

-(void) dealloc
{
	[super dealloc];
}

-(void) restartCallback: (id) sender
{
	CCScene *s = [CCScene node];
	[s addChild: [restartAction() node]];
	[[CCDirector sharedDirector] replaceScene: s];
}

-(void) nextCallback: (id) sender
{
	CCScene *s = [CCScene node];
	[s addChild: [nextAction() node]];
	[[CCDirector sharedDirector] replaceScene: s];
}

-(void) backCallback: (id) sender
{
	CCScene *s = [CCScene node];
	[s addChild: [backAction() node]];
	[[CCDirector sharedDirector] replaceScene: s];
}

-(NSString*) title
{
	return @"No title";
}

-(NSString*) subtitle
{
	return nil;
}
@end

#pragma mark -
#pragma mark Director1


@implementation Director1

-(id) init
{
	if( (self=[super init]) ) {

#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
		self.isTouchEnabled = YES;

		CGSize s = [[CCDirector sharedDirector] winSize];

		CCMenuItem *item = [CCMenuItemFont itemFromString:@"Rotate Device" target:self selector:@selector(rotateDevice:)];
		CCMenu *menu = [CCMenu menuWithItems:item, nil];
		[menu setPosition:ccp( s.width/2, s.height/2) ];
		[self addChild:menu];


#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
		self.isMouseEnabled = YES;
#endif


	}
	return self;
}

#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
-(void) newOrientation
{
	ccDeviceOrientation orientation = [[CCDirector sharedDirector] deviceOrientation];
	switch (orientation) {
		case CCDeviceOrientationLandscapeLeft:
			orientation = CCDeviceOrientationPortrait;
			break;
		case CCDeviceOrientationPortrait:
			orientation = CCDeviceOrientationLandscapeRight;
			break;
		case CCDeviceOrientationLandscapeRight:
			orientation = CCDeviceOrientationPortraitUpsideDown;
			break;
		case CCDeviceOrientationPortraitUpsideDown:
			orientation = CCDeviceOrientationLandscapeLeft;
			break;
	}
	[[CCDirector sharedDirector] setDeviceOrientation:orientation];
}
-(void) rotateDevice:(id)sender
{
	[self newOrientation];
	CCScene *s = [CCScene node];
	[s addChild: [restartAction() node]];

	[[CCDirector sharedDirector] replaceScene: s];
}
#endif // __IPHONE_OS_VERSION_MAX_ALLOWED


#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
- (void)ccTouchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	for( UITouch *touch in touches ) {
		CGPoint a = [touch locationInView: [touch view]];

		CCDirector *director = [CCDirector sharedDirector];
		CGPoint b = [director convertToUI: [director convertToGL: a]];

		NSLog(@"(%d,%d) == (%d,%d)", (int) a.x, (int)a.y, (int)b.x, (int)b.y );

	}
}
#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
-(BOOL) ccMouseUp:(NSEvent *)event
{
	NSLog(@"NOT IMPLEMENTED");
	return YES;
}
#endif

-(NSString *) title
{
	return @"Testing conversion";
}

-(NSString*) subtitle
{
	return @"Tap screen and see the debug console";
}
@end

//this test is only meant for iphone, the problem doesn't occur on mac
@implementation ScrollViewTest

-(id) init
{
	if( (self=[super init]) ) {


#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
        scrollView = nil;

		self.isTouchEnabled = YES;

        CCDirector* director = [CCDirector sharedDirector];

        //setting this property to yes makes cocos more compatible with UIKit elements
        [director setRunLoopCommon:YES];



		CGSize s = [[CCDirector sharedDirector] winSize];

		CCMenuItem *item = [CCMenuItemFont itemFromString:@"Enable scrollView" target:self selector:@selector(viewScrollView)];
		CCMenu *menu = [CCMenu menuWithItems:item, nil];
		[menu setPosition:ccp( s.width/2, s.height/2) ];
		[self addChild:menu];

        id seq = [CCSequence actions:
				  [CCRotateTo actionWithDuration:0.5f angle:-90],
				  [CCRotateTo actionWithDuration:0.5f angle:90],
                  nil];


        id rep2 = [CCRepeatForever actionWithAction: [[seq copy] autorelease] ];

        CCSprite *gros = [CCSprite spriteWithFile:@"grossini_dance_01.png"];
        [gros setPosition:ccp(120.f,100.f)];

        [self addChild:gros];
        [gros runAction:rep2];

#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
		self.isMouseEnabled = YES;
#endif


	}
	return self;
}

- (void) viewScrollView
{
    if (scrollView == nil)
    {
        scrollView = [[ScrollViewController alloc] init];
        [[[CCDirector sharedDirector] openGLView] addSubview:scrollView.view];
    }
}

- (void) onExit
{
    [scrollView.view removeFromSuperview];
    [scrollView release];
    scrollView = nil;
}

#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
- (void)ccTouchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	for( UITouch *touch in touches ) {
		CGPoint a = [touch locationInView: [touch view]];

		CCDirector *director = [CCDirector sharedDirector];
		CGPoint b = [director convertToUI: [director convertToGL: a]];

		NSLog(@"(%d,%d) == (%d,%d)", (int) a.x, (int)a.y, (int)b.x, (int)b.y );

	}
}
#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
-(BOOL) ccMouseUp:(NSEvent *)event
{
	NSLog(@"NOT IMPLEMENTED");
	return YES;
}
#endif

-(NSString *) title
{
	return @"Testing scrollview";
}

-(NSString*) subtitle
{
	return @"";
}

- (void) deallloc
{

    [super dealloc];
}
@end


#pragma mark -
#pragma mark AppDelegate

// CLASS IMPLEMENTATIONS

#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
@implementation AppController

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	// Init the window
	window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

	// must be called before any othe call to the director
	[CCDirector setDirectorType:kCCDirectorTypeDisplayLink];

	// before creating any layer, set the landscape mode
	CCDirector *director = [CCDirector sharedDirector];

    //set the runLoop here, this run loop lets the director play a bit more nicely with UIKit elements
    [director setRunLoopCommon:YES];


	// Enable Retina display
	[director enableRetinaDisplay:YES];

	// Create an EAGLView with a RGB8 color buffer, and a depth buffer of 24-bits
	EAGLView *glView = [EAGLView viewWithFrame:[window bounds]
								   pixelFormat:kEAGLColorFormatRGBA8
								   depthFormat:GL_DEPTH_COMPONENT24_OES
							preserveBackbuffer:NO
									sharegroup:nil
								 multiSampling:NO
							   numberOfSamples:0];


    // Init the View Controller
	viewController = [[MasterViewController alloc] initWithNibName:nil bundle:nil];
	viewController.wantsFullScreenLayout = YES;

	[glView setMultipleTouchEnabled:YES];

	// attach the openglView to the director
	[director setOpenGLView:glView];

	//
	// VERY IMPORTANT:
	// If the rotation is going to be controlled by a UIViewController
	// then the device orientation should be "Portrait".
	//
	[director setDeviceOrientation:kCCDeviceOrientationPortrait];

	[director setAnimationInterval:1.0/60];

	[director setDisplayFPS:YES];

	// make the OpenGLView a child of the view controller
	[viewController setView:glView];

    [window addSubview:viewController.view];

    //needed for iOS6, recommend in 4 and 5
    [window setRootViewController:viewController];
	// make main window visible
	[window makeKeyAndVisible];

	// Default texture format for PNG/BMP/TIFF/JPEG/GIF images
	// It can be RGBA8888, RGBA4444, RGB5_A1, RGB565
	// You can change anytime.
	[CCTexture2D setDefaultAlphaPixelFormat:kCCTexture2DPixelFormat_RGBA8888];

	// When in iPhone RetinaDisplay, iPad, iPad RetinaDisplay mode, CCFileUtils will append the "-hd", "-ipad", "-ipadhd" to all loaded files
	// If the -hd, -ipad, -ipadhd files are not found, it will load the non-suffixed version
	[CCFileUtils setiPhoneRetinaDisplaySuffix:@"-hd"];		// Default on iPhone RetinaDisplay is "-hd"
    [CCFileUtils setiPhoneFourInchDisplaySuffix:@"-568h"];	// Default on iPhone RetinaFourInchDisplay is "-568h"
	[CCFileUtils setiPadSuffix:@"-ipad"];					// Default on iPad is "" (empty string)
	[CCFileUtils setiPadRetinaDisplaySuffix:@"-ipadhd"];	// Default on iPad RetinaDisplay is "-ipadhd"
	// Assume that PVR images have premultiplied alpha
	[CCTexture2D PVRImagesHavePremultipliedAlpha:YES];

	// create the main scene
	CCScene *scene = [CCScene node];
	[scene addChild: [nextAction() node]];


	// and run it!
	[director runWithScene: scene];

	return YES;
}

// getting a call, pause the game
-(void) applicationWillResignActive:(UIApplication *)application
{
	[[CCDirector sharedDirector] pause];
}

// call got rejected
-(void) applicationDidBecomeActive:(UIApplication *)application
{
	[[CCDirector sharedDirector] resume];
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
}

// purge memory
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
	[[CCDirector sharedDirector] purgeCachedData];
}

// next delta time will be zero
-(void) applicationSignificantTimeChange:(UIApplication *)application
{
	[[CCDirector sharedDirector] setNextDeltaTimeZero:YES];
}

- (void) dealloc
{
	[window release];
	[super dealloc];
}
@end

#pragma mark -
#pragma mark AppController - Mac

#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)

@implementation cocos2dmacAppDelegate

@synthesize window=window_, glView=glView_;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	CCDirectorMac *director = (CCDirectorMac*) [CCDirector sharedDirector];

	[director setDisplayFPS:YES];

	[director setOpenGLView:glView_];

	//	[director setProjection:kCCDirectorProjection2D];

	// Enable "moving" mouse event. Default no.
	[window_ setAcceptsMouseMovedEvents:NO];

	// EXPERIMENTAL stuff.
	// 'Effects' don't work correctly when autoscale is turned on.
	[director setResizeMode:kCCDirectorResize_AutoScale];

	CCScene *scene = [CCScene node];
	[scene addChild: [nextAction() node]];

	[director runWithScene:scene];
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) theApplication
{
	return YES;
}

- (IBAction)toggleFullScreen: (id)sender
{
	CCDirectorMac *director = (CCDirectorMac*) [CCDirector sharedDirector];
	[director setFullScreen: ! [director isFullScreen] ];
}

@end
#endif
