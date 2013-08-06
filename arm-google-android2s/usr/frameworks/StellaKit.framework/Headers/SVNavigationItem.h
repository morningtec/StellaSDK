//
//  SVNavigationItem.h
//  StellaKit-android2s
//
//  Created by ymm on 13-2-17.
//
//

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"

#import "SVNavigationBar.h"
#import "SVBarButtonItem.h"
#import "SVView.h"


@class SVNavigationBar;
@class SVBarButtonItem;

#define UINavigationItem            SVNavigationItem

@interface SVNavigationItem : NSObject <NSCoding>

@property(nonatomic, copy) NSString                 * prompt;
@property(nonatomic, copy) NSString                 * title;
@property(nonatomic, copy) NSArray                  * rightBarButtonItems;
@property(nonatomic, copy) NSArray                  * leftBarButtonItems;
@property(nonatomic, assign) BOOL                     hidesBackButton;
@property(nonatomic, retain) SVView                 * titleView;
@property(nonatomic, retain) SVBarButtonItem        * backBarButtonItem;
@property(nonatomic, retain) SVBarButtonItem        * rightBarButtonItem;
@property BOOL                                        leftItemsSupplementBackButton;
@property(nonatomic, retain) SVBarButtonItem        * leftBarButtonItem;


- (void) setRightBarButtonItems: (NSArray *) items animated: (BOOL) animated;
- (void) setLeftBarButtonItem: (SVBarButtonItem *) item animated: (BOOL) animated;
- (id) initWithTitle: (NSString *) title;
- (void) setHidesBackButton: (BOOL) hidesBackButton animated: (BOOL) animated;
- (void) setRightBarButtonItem: (SVBarButtonItem *) item animated: (BOOL) animated;
- (void) setLeftBarButtonItems: (NSArray *) items animated: (BOOL) animated;

@end