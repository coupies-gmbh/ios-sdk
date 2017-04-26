//
//  NativeCouponViewController.h
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <COUPIES/COUPIES.h>

// This example works together with "NativeListTableViewController". When a coupon is clicked on in this list, we open
// the details in this controller in a simple WebView. For a very simple exaple with the list and details together,
// refer "HtmlListViewController".

@interface NativeCouponViewController : UIViewController<COUPIESCashbackRedemptionViewControllerDelegate, UIWebViewDelegate> {
    @private
    COUPIESRequestFactory *requestFactory;
    IBOutlet UIWebView *webView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
}

@property (nonatomic, strong) COUPIESRequestFactory *requestFactory;
@property (nonatomic, strong) COUPIESCoupon *coupon;

@end
