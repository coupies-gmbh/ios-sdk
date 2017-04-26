//
//  HtmlListViewController.h
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <COUPIES/COUPIES.h>

// This is the simplest way to integrate coupons in your application: Display one or several coupons in
// a WebView. Clicks on "redeem now" are intercepted and delegated to the COUPIES-framework to handle
// redemptions using the COUPIES SDK. This example uses only the HTML representation of the COUPIES API.

@interface HtmlListViewController : UIViewController <COUPIESCashbackRedemptionViewControllerDelegate, UIWebViewDelegate, COUPIESRestServiceDelegate> {
@private
    COUPIESRequestFactory *requestFactory;
    IBOutlet UIWebView *webView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
}

@property (nonatomic, strong) COUPIESRequestFactory *requestFactory;
@property(nonatomic, strong) COUPIESCoupon *coupon;

- (IBAction)reloadList;

@end
