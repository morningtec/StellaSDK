/*
 * Copyright (c) 2011 Yeecco Limited
 */


#import "SVView.h"
#import "SVImage.h"
#import "SVTextInputTraits.h"

@protocol UISearchBarDelegate;
// @class UISearchField;
// @class UIKey;

@interface UISearchBar : UIView

@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) id<UISearchBarDelegate> delegate;
@property (nonatomic) BOOL showsCancelButton;
@property (nonatomic,copy) NSString *placeholder;


@end


@protocol UISearchBarDelegate <NSObject>

@optional

- (BOOL) searchBarShouldBeginEditing: (UISearchBar *) searchBar;
- (void) searchBarTextDidBeginEditing: (UISearchBar *) searchBar;
- (BOOL) searchBarShouldEndEditing: (UISearchBar *) searchBar;
- (void) searchBarTextDidEndEditing: (UISearchBar *) searchBar;
- (void) searchBar: (UISearchBar *) searchBar textDidChange: (NSString *) searchText;
- (BOOL) searchBar: (UISearchBar *) searchBar shouldChangeTextInRange: (NSRange) range replacementText: (NSString *) text;

- (void) searchBarSearchButtonClicked: (UISearchBar *) searchBar;
- (void) searchBarBookmarkButtonClicked: (UISearchBar *) searchBar;
- (void) searchBarCancelButtonClicked: (UISearchBar *) searchBar;
- (void) searchBarResultsListButtonClicked: (UISearchBar *) searchBar;

- (void) searchBar: (UISearchBar *) searchBar selectedScopeButtonIndexDidChange: (NSInteger) selectedScope;

@end
