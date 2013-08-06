/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import <Foundation/Foundation.h>
#import "SVControl.h"

typedef enum {
        UIDatePickerModeTime,
        UIDatePickerModeDate,
        UIDatePickerModeDateAndTime,
        UIDatePickerModeCountDownTimer
} UIDatePickerMode;

@interface UIDatePicker : UIControl

@property (nonatomic, copy) NSCalendar          * calendar;
@property (nonatomic, retain) NSDate              * date;
@property (nonatomic, retain) NSLocale            * locale;
@property (nonatomic, retain) NSTimeZone          * timeZone;

@property (nonatomic, assign) UIDatePickerMode      datePickerMode;

@property (nonatomic, retain) NSDate              * minimumDate;
@property (nonatomic, retain) NSDate              * maximumDate;
@property (nonatomic, assign) NSInteger             minuteInterval;
@property (nonatomic, assign) NSTimeInterval        countDownDuration;


- (void) setDate: (NSDate *) date animated: (BOOL) animated;

@end

