/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVBarItem.h"
#import "SVImage.h"
#import "SVGeometry.h"



typedef enum {
    UITabBarSystemItemMore,
    UITabBarSystemItemFavorites,
    UITabBarSystemItemFeatured,
    UITabBarSystemItemTopRated,
    UITabBarSystemItemRecents,
    UITabBarSystemItemContacts,
    UITabBarSystemItemHistory,
    UITabBarSystemItemBookmarks,
    UITabBarSystemItemSearch,
    UITabBarSystemItemDownloads,
    UITabBarSystemItemMostRecent,
    UITabBarSystemItemMostViewed,
} UITabBarSystemItem;



@interface UITabBarItem : UIBarItem

@property(nonatomic, copy) NSString *badgeValue;

- (id) initWithTabBarSystemItem: (UITabBarSystemItem) systemItem tag: (NSInteger) tag;
- (id) initWithTitle: (NSString *) title image: (UIImage *) image tag: (NSInteger) tag;
- (UIImage *) finishedSelectedImage;
- (UIImage *) finishedUnselectedImage;
- (void) setFinishedSelectedImage: (UIImage *) selectedImage withFinishedUnselectedImage: (UIImage *) unselectedImage;
- (UIOffset) titlePositionAdjustment;
- (void) setTitlePositionAdjustment: (UIOffset) adjustment;

@end
