/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
@protocol UIPickerViewDataSource, UIPickerViewDelegate;

@interface UIPickerView : UIView

@property (nonatomic, assign) id<UIPickerViewDataSource> dataSource;
@property (nonatomic, assign) id<UIPickerViewDelegate>   delegate;
@property (nonatomic, assign) BOOL                       showsSelectionIndicator;
@property (nonatomic, readonly) NSInteger                numberOfComponents;

- (NSInteger) numberOfRowsInComponent: (NSInteger) component; // stub
- (void) reloadAllComponents; // stub
- (void) reloadComponent: (NSInteger) component; // stub
- (CGSize) rowSizeForComponent: (NSInteger) component; // stub
- (NSInteger) selectedRowInComponent: (NSInteger) component; // stub
- (void)selectRow: (NSInteger)row inComponent: (NSInteger)component animated: (BOOL)animated; // stub
- (UIView *) viewForRow: (NSInteger) row inComponent: (NSInteger) component; // stub

@end


@protocol UIPickerViewDataSource <NSObject>
@required

- (NSInteger) numberOfComponentsInPickerView: (UIPickerView *) pickerView;
- (NSInteger) pickerView: (UIPickerView *) pickerView numberOfRowsInComponent: (NSInteger) component;

@end


@protocol UIPickerViewDelegate <NSObject>
@optional

- (CGFloat) pickerView: (UIPickerView *) pickerView widthForComponent: (NSInteger) component;
- (CGFloat) pickerView: (UIPickerView *) pickerView rowHeightForComponent: (NSInteger) component;

- (NSString *) pickerView: (UIPickerView *) pickerView titleForRow: (NSInteger) row forComponent: (NSInteger) component;
- (UIView *) pickerView: (UIPickerView *) pickerView viewForRow: (NSInteger) row forComponent: (NSInteger) component reusingView: (UIView *) view;

- (void) pickerView: (UIPickerView *) pickerView didSelectRow: (NSInteger) row inComponent: (NSInteger) component;

@end
