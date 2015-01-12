//
//  CouponViewController.h
//  HelloCOUPIES
//
//  Created by Clemens Wagner on 29.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <COUPIES/COUPIES.h>

// This example works together with "NativeListTableViewController". When a coupon is clicked on in this list, we open
// the details in this controller in a simple WebView. For a very simple exaple with the list and details together,
// refer "HtmlListViewController".
@interface CouponViewController : UIViewController<UIWebViewDelegate, COUPIESStickerRedemptionViewControllerDelegate, COUPIESCashbackRedemptionViewControllerDelegate> {
    @private
    COUPIESRequestFactory *requestFactory;
    COUPIESCoupon *coupon;
    IBOutlet UIWebView *webView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
}

@property (nonatomic, strong) COUPIESRequestFactory *requestFactory;
@property (nonatomic, strong) COUPIESCoupon *coupon;

@end
