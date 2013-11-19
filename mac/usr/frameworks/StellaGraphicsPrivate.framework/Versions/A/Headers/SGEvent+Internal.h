/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>

/*mutlitouch: define the MAX points  stella support*/
#if defined (__STELLA_HANDROID2)
#define MAX_SUPPORT_POINTS 10
#else
#define MAX_SUPPORT_POINTS 2
#endif

typedef enum {
        SGLeftMouseDown         = 1,
        SGLeftMouseUp           = 2,
        SGRightMouseDown        = 3,
        SGRightMouseUp          = 4,
        SGMouseMoved            = 5,
        SGLeftMouseDragged      = 6,
        SGRightMouseDragged     = 7,
        SGMouseEntered          = 8,
        SGMouseExited           = 9,
        SGKeyDown               = 10,
        SGKeyUp                 = 11,
        SGFlagsChanged          = 12,
        SGPeriodic              = 13,
        SGCursorUpdate          = 14,

        SGScrollWheel           = 18,
        SGApplicationDefined    = 19,

        SGTouchEventType        = 20,

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
}

@property(nonatomic) SGTouchGesturePhase            touchGesturePhase;
@property(nonatomic) SGTouchGestureType             touchGestureType;

- (NSTimeInterval) timestamp;
- (NSPoint) locationInWindow;
- (SGEventType) type;
- (id) delegate;

- (SGTouch *) touches;

@end

