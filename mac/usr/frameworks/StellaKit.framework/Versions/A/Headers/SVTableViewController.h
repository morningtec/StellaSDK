/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import "SVViewController.h"
#import "SVTableView.h"

@interface UITableViewController : UIViewController

@property(nonatomic, retain) UITableView          * tableView;
@property(nonatomic) BOOL                           clearsSelectionOnViewWillAppear;


@end
