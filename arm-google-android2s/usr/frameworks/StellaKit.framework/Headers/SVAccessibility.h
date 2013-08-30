/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>

typedef uint64_t UIAccessibilityTraits;

extern UIAccessibilityTraits UIAccessibilityTraitNone;
extern UIAccessibilityTraits UIAccessibilityTraitButton;
extern UIAccessibilityTraits UIAccessibilityTraitLink;
extern UIAccessibilityTraits UIAccessibilityTraitSearchField;
extern UIAccessibilityTraits UIAccessibilityTraitImage;
extern UIAccessibilityTraits UIAccessibilityTraitSelected;
extern UIAccessibilityTraits UIAccessibilityTraitPlaysSound;
extern UIAccessibilityTraits UIAccessibilityTraitKeyboardKey;
extern UIAccessibilityTraits UIAccessibilityTraitStaticText;
extern UIAccessibilityTraits UIAccessibilityTraitSummaryElement;
extern UIAccessibilityTraits UIAccessibilityTraitNotEnabled;
extern UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently;
extern UIAccessibilityTraits UIAccessibilityTraitHeader;


typedef uint32_t UIAccessibilityNotifications;
extern UIAccessibilityNotifications UIAccessibilityScreenChangedNotification;
extern UIAccessibilityNotifications UIAccessibilityLayoutChangedNotification;
extern UIAccessibilityNotifications UIAccessibilityAnnouncementNotification;
extern UIAccessibilityNotifications UIAccessibilityPageScrolledNotification;


@interface NSObject (UIAccessibility)
@property (nonatomic) BOOL          isAccessibilityElement;
@property (nonatomic, copy) NSString    * accessibilityLabel;
@property (nonatomic, copy) NSString    * accessibilityHint;
@property (nonatomic, copy) NSString    * accessibilityValue;
@property (nonatomic) UIAccessibilityTraits     accessibilityTraits;
@property (nonatomic) CGRect                    accessibilityFrame;
@property (nonatomic) BOOL                      accessibilityViewIsModal;
@property (nonatomic) BOOL                      accessibilityElementsHidden;
@end

/*
@interface NSObject (UIAccessibilityContainer)
- (NSInteger) accessibilityElementCount;
- (id) accessibilityElementAtIndex: (NSInteger) index;
- (NSInteger) indexOfAccessibilityElement: (id) element;
@end
*/

extern void UIAccessibilityPostNotification (UIAccessibilityNotifications notification, id argument);
extern BOOL UIAccessibilityIsVoiceOverRunning (void);


