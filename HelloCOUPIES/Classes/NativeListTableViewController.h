//
//  HtmlListViewController.h
//  HelloCOUPIES
//
//  Created by Felix Schul
//  Copyright 2013 COUPIES GmbH. All rights reserved.
//
#import <UIKit/UIKit.h>

@class COUPIESManager;
@class COUPIESRestService;
@class CouponCell;
@class CouponViewController;

// This example demonstrates how to use the native representation of the COUPIES-API (retrieve objects instead
// of HTML-code). To keep it simple, we mix the native and HTML-representation by displaying the list of
// coupons natively but the details in a WebView. Of course everything can be done natively we well.
// When a coupon is clicked on in the TableView, we open the details in "CouponViewController".
@interface NativeListTableViewController : UIViewController<UITableViewDataSource, UITableViewDelegate> {
    @private
    COUPIESManager *__weak coupiesManager;
    COUPIESRestService *restService;
    
    IBOutlet UITableView *tableView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
    NSData *cellData;
    NSString *cellIdentifier;
    CGFloat cellHeight;
    NSArray *coupons;
    CouponViewController *couponViewController;
}

@property (nonatomic, weak) IBOutlet COUPIESManager *coupiesManager;
@property (nonatomic, strong) COUPIESRestService *restService;
@property (nonatomic, copy) IBOutlet CouponCell *couponCell;
@property (nonatomic, strong) IBOutlet CouponViewController *couponViewController;

-(IBAction)reloadList;

@end
