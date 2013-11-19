/*
 * Stella Debut
 * Wenqi Chen 1/2011
 */

#import <Foundation/Foundation.h>
#import "../DebutKit/SGDebug+Stella.h"

// #import "SGSomeObject+Stella.h"
#import "SGEvent+Stella.h"

// @class SUClass;

@interface SGMouseEvent : SGEvent
{
        int   _clickCount;
        float _deltaX;
        float _deltaY;
        NSInteger _trackingNumber;
        void *_userData;
}
// @property (nonatomic)       BOOL    someProperty;



+ (void) initialize;
- (id) initWithType: (SGEventType) type
           location: (NSPoint) location
      modifierFlags: (NSUInteger) modifierFlags
           delegate: (id) delegate
         clickCount: (int) clickCount
             deltaX: (float) deltaX
             deltaY: (float)deltaY;

- (void) dealloc;

#if defined (STELLA_PROBE_TEMPLATE) || 1
- (NSString *) description;
#endif



// -initWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(NSUInteger)modifierFlags timestamp:(NSTimeInterval)timestamp delegateNumber:(NSInteger)delegateNumber context:(NSGraphicsContext*)context eventNumber:(NSInteger)eventNumber trackingNumber:(NSInteger)tracking userData:(void *)userData;

// -initWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(NSUInteger)modifierFlags timestamp:(NSTimeInterval)timestamp delegateNumber:(NSInteger)delegateNumber context:(NSGraphicsContext*)context eventNumber:(NSInteger)eventNumber clickCount:(NSInteger)clickCount pressure:(float)pressure;

// -(NSTrackingArea *)trackingArea;
-(NSInteger)trackingNumber;
-(void *)userData;




@end

// #import  "SGMouseEvent+Key.h"
// #import  "SGMouseEvent+Mouse.h"


