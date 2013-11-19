/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import "SVScrollView.h"
#import "SVTableViewCell.h"

typedef enum {
        UITableViewStylePlain,
        UITableViewStyleGrouped
} UITableViewStyle;

typedef enum {
        UITableViewScrollPositionNone,
        UITableViewScrollPositionTop,
        UITableViewScrollPositionMiddle,
        UITableViewScrollPositionBottom
} UITableViewScrollPosition;

typedef enum {
        UITableViewRowAnimationFade,
        UITableViewRowAnimationRight,
        UITableViewRowAnimationLeft,
        UITableViewRowAnimationTop,
        UITableViewRowAnimationBottom,
        UITableViewRowAnimationNone,
        UITableViewRowAnimationMiddle
} UITableViewRowAnimation;


@class UITableView;

@protocol UITableViewDataSource <NSObject>
@required
//- (UITableViewCell *) tableView: (UITableView *) tableView cellForRowAtIndexPath: (NSIndexPath *) indexPath;
- (NSInteger) tableView: (UITableView *) tableView numberOfRowsInSection: (NSInteger) section;

@optional
- (NSInteger) numberOfSectionsInTableView: (UITableView *) tableView;
- (NSString *) tableView: (UITableView *) tableView titleForHeaderInSection: (NSInteger) section;
- (NSString *) tableView: (UITableView *) tableView titleForFooterInSection: (NSInteger) section;

- (BOOL) tableView: (UITableView *) tableView canEditRowAtIndexPath: (NSIndexPath *) indexPath;
//- (void) tableView: (UITableView *) tableView commitEditingStyle: (UITableViewCellEditingStyle) editingStyle forRowAtIndexPath: (NSIndexPath *) indexPath;
@end

@protocol UITableViewDelegate <UIScrollViewDelegate>
@optional
- (CGFloat) tableView: (UITableView *) tableView heightForRowAtIndexPath: (NSIndexPath *) indexPath;

- (void) tableView: (UITableView *) tableView accessoryButtonTappedForRowWithIndexPath: (NSIndexPath *) indexPath;

- (NSIndexPath *) tableView: (UITableView *) tableView willSelectRowAtIndexPath: (NSIndexPath *) indexPath;
- (void) tableView: (UITableView *) tableView didSelectRowAtIndexPath: (NSIndexPath *) indexPath;
- (NSIndexPath *) tableView: (UITableView *) tableView willDeselectRowAtIndexPath: (NSIndexPath *) indexPath;
- (void) tableView: (UITableView *) tableView didDeselectRowAtIndexPath: (NSIndexPath *) indexPath;

- (UIView *) tableView: (UITableView *) tableView viewForHeaderInSection: (NSInteger) section;
- (UIView *) tableView: (UITableView *) tableView viewForFooterInSection: (NSInteger) section;
- (CGFloat) tableView: (UITableView *) tableView heightForHeaderInSection: (NSInteger) section;
- (CGFloat) tableView: (UITableView *) tableView heightForFooterInSection: (NSInteger) section;

- (void) tableView: (UITableView *) tableView willBeginEditingRowAtIndexPath: (NSIndexPath *) indexPath;
- (void) tableView: (UITableView *) tableView didEndEditingRowAtIndexPath: (NSIndexPath *) indexPath;
- (NSString *) tableView: (UITableView *) tableView titleForDeleteConfirmationButtonForRowAtIndexPath: (NSIndexPath *) indexPath;

@end


@interface UITableView : UIScrollView
{
}

@property (nonatomic, readonly) UITableViewStyle                style;
@property (nonatomic) CGFloat                                   rowHeight;
@property (nonatomic) UITableViewCellSeparatorStyle             separatorStyle;
@property (nonatomic, retain) UIColor                         * separatorColor;
@property (nonatomic, retain) UIView                          * backgroundView;


@property(nonatomic) BOOL                                       allowsSelection;
@property(nonatomic) BOOL                                       allowsSelectionDuringEditing;

@property(nonatomic, assign) id<UITableViewDataSource>          dataSource;
@property(nonatomic, assign) id<UITableViewDelegate>            delegate;


- (id) initWithFrame: (CGRect) frame style: (UITableViewStyle) style;

- (NSInteger) numberOfRowsInSection: (NSInteger) section;
- (NSInteger) numberOfSections;

- (UITableViewCell *) dequeueReusableCellWithIdentifier: (NSString *) identifier;

- (NSIndexPath *) indexPathForSelectedRow;
- (void) deselectRowAtIndexPath: (NSIndexPath *) indexPath animated: (BOOL)animated;

- (void) reloadData;
- (void) reloadRowsAtIndexPaths: (NSArray *) indexPaths withRowAnimation: (UITableViewRowAnimation) animation;   // not implemented, just reload all.
- (void) reloadSections: (NSIndexSet *) sections withRowAnimation: (UITableViewRowAnimation) animation;  // not implemented, just reload all.

- (void) layoutSubviews;


@end


@interface NSIndexPath (UITableView)
@property(nonatomic, readonly) NSUInteger       row;
@property(nonatomic, readonly) NSUInteger       section;

+ (NSIndexPath *) indexPathForRow: (NSUInteger) row inSection: (NSUInteger) section;
@end


