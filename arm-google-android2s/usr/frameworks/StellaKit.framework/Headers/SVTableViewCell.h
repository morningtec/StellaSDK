/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "SVView.h"

typedef enum {
        UITableViewCellStyleDefault,
        UITableViewCellStyleValue1,
        UITableViewCellStyleValue2,
        UITableViewCellStyleSubtitle
} UITableViewCellStyle;

typedef NSUInteger UITableViewCellStateMask;

typedef enum {
        UITableViewCellSelectionStyleNone,
        UITableViewCellSelectionStyleBlue,
        UITableViewCellSelectionStyleGray
} UITableViewCellSelectionStyle;

typedef enum {
        UITableViewCellEditingStyleNone,
        UITableViewCellEditingStyleDelete,
        UITableViewCellEditingStyleInsert
} UITableViewCellEditingStyle;

typedef enum {
        UITableViewCellAccessoryNone,
        UITableViewCellAccessoryDisclosureIndicator,
        UITableViewCellAccessoryDetailDisclosureButton,
        UITableViewCellAccessoryCheckmark
} UITableViewCellAccessoryType;

enum {
        UITableViewCellStateDefaultMask                     = 0,
        UITableViewCellStateShowingEditControlMask          = 1 << 0,
        UITableViewCellStateShowingDeleteConfirmationMask   = 1 << 1
};

typedef enum {
        UITableViewCellSeparatorStyleNone,
        UITableViewCellSeparatorStyleSingleLine,
        UITableViewCellSeparatorStyleSingleLineEtched
} UITableViewCellSeparatorStyle;

@class UILabel;
@interface UITableViewCell : UIView
{
}

@property(nonatomic, readonly, copy) NSString         * reuseIdentifier;

@property(nonatomic, readonly, retain) UILabel        * textLabel;
@property(nonatomic, readonly, retain) UILabel        * detailTextLabel;

@property(nonatomic, readonly, retain) UIImageView    * imageView;

@property(nonatomic, readonly, retain) UIView         * contentView;
@property(nonatomic, retain) UIView                   * backgroundView;
@property(nonatomic, retain) UIView                   * selectedBackgroundView;
/**/

@property(nonatomic) UITableViewCellAccessoryType       accessoryType;
@property(nonatomic, retain) UIView                   * accessoryView;
@property(nonatomic) UITableViewCellAccessoryType       editingAccessoryType;


@property(nonatomic, getter=isSelected) BOOL            selected;
@property(nonatomic) UITableViewCellSelectionStyle      selectionStyle;
@property(nonatomic, getter=isHighlighted) BOOL         highlighted;

- (id) initWithStyle: (UITableViewCellStyle) style reuseIdentifier: (NSString *) reuseIdentifier;

- (void) prepareForReuse;

- (void) setAccessoryType: (UITableViewCellAccessoryType) accessoryType;

- (void) setSelected: (BOOL) selected animated: (BOOL) animated;
- (void) setHighlighted: (BOOL) highlighted animated: (BOOL) animated;

@end
