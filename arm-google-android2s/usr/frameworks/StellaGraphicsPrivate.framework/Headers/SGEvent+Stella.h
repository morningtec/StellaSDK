/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import "../Onyx2D/SGGeometry+Stella.h"

/*mutlitouch: define the MAX points  stella support*/
#if defined (__STELLA_HANDROID2)
#define MAX_SUPPORT_POINTS 10
#else
#define MAX_SUPPORT_POINTS 2
#endif

typedef enum _SGEventType {
        SGLeftMouseDown     = 1,
        SGLeftMouseUp       = 2,
        SGRightMouseDown    = 3,
        SGRightMouseUp      = 4,
        SGMouseMoved        = 5,
        SGLeftMouseDragged  = 6,
        SGRightMouseDragged = 7,
        SGMouseEntered      = 8,
        SGMouseExited       = 9,
        SGKeyDown           = 10,
        SGKeyUp             = 11,
        SGFlagsChanged      = 12,
        SGPeriodic          = 13,
        SGCursorUpdate      = 14,


        SGScrollWheel=18,
        SGApplicationDefined=19,

        SGTouchEventType    = 20,

        SGAppKitSystem                  = 1000,
        SGPlatformSpecific              = 1500,
        SGPlatformSpecificDisplayEvent  = 1600,

} SGEventType;

typedef enum _SGTouchPhase {
        SGTouchPhaseBegan,
        SGTouchPhaseMoved,
        SGTouchPhaseStationary,
        SGTouchPhaseEnded,
        SGTouchPhaseCancelled,
} SGTouchPhase;


typedef enum {
        SGTouchGesturePhaseUnknown      = 0,
        SGTouchGesturePhaseBegan,
        SGTouchGesturePhaseChanged,
        SGTouchGesturePhaseEnded,
        SGTouchGesturePhaseDiscrete,
} SGTouchGesturePhase;


typedef enum {
        SGTouchGestureTypePan,
} SGTouchGestureType;



typedef struct _SGTouch {
        SGTouchPhase   phase;
        SGPoint        location;
        BOOL           valid;
        BOOL           new;
} SGTouch;


@interface SGEvent : NSObject // <NSCoding>
{
        int             _type;
        NSTimeInterval  _timestamp;
        NSPoint         _locationInWindow;
        NSUInteger      _modifierFlags;

        // NSWindow      *_window;
        id              _delegate;
        SGTouch         _touches[MAX_SUPPORT_POINTS];
}

@property(nonatomic) SGTouchGesturePhase            touchGesturePhase;
@property(nonatomic) SGTouchGestureType             touchGestureType;


+ (void) initialize;

- (id) initWithType: (SGEventType) type
           location: (NSPoint) location
      modifierFlags: (NSUInteger) modifierFlags
           delegate: (id) delegate;

/* WC - todo 8.2012: use SGTouches (done)*/
- (id) initWithTouches: (SGTouch *) touches
              delegate: (id) delegate;

- (SGTouch *) touches;



- (void) dealloc;

#if defined (STELLA_PROBE_TEMPLATE) || 1
- (NSString *) description;
#endif


/* zuckered */
+ (SGEvent *) mouseEventWithType: (SGEventType) type
                        location: (NSPoint) location
                   modifierFlags: (NSUInteger) modifierFlags
                        delegate: (id) delegate
                      clickCount: (int) clickCount
                          deltaX: (float) deltaX
                          deltaY: (float) deltaY;



- (SGEventType) type;
-(NSTimeInterval)timestamp;
-(NSPoint)locationInWindow;
-(NSUInteger)modifierFlags;
-(id) delegate;

-(int)clickCount;
-(float)deltaX;
-(float)deltaY;
-(float)deltaZ;



-(short)subtype;
-(NSInteger)data1;
-(NSInteger)data2;
-(void *)userData;


@end

// #import  "SGEvent+Key.h"
// #import  "SGEvent+Mouse.h"



