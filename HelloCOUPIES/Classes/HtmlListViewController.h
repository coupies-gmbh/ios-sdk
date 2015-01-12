//
//  HtmlListViewController.h
//  HelloCOUPIES
//
//  Created by Felix Schul
//  Copyright 2013 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <COUPIES/COUPIES.h>

// This is the simplest way to integrate coupons in your application: Display one or several coupons in
// a WebView. Clicks on "redeem now" are intercepted and delegated to the COUPIES-framework to handle
// redemotions using the COUPIES-Touchpoint. This example uses only the HTML representation of the COUPIES-API.
@interface HtmlListViewController : UIViewController<COUPIESStickerRedemptionViewControllerDelegate, COUPIESCashbackRedemptionViewControllerDelegate, COUPIESRestServiceDelegate> {
    @private
    COUPIESRequestFactory *requestFactory;
    IBOutlet UIWebView *webView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
    COUPIESCoupon *coupon;
}

@property (nonatomic, strong) COUPIESRequestFactory *requestFactory;

-(IBAction)reloadList;

@end
