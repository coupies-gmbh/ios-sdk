//
//  HtmlListViewController.m
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import "HtmlListViewController.h"
#import "HelloCOUPIESAppDelegate.h"
#import "NativeListTableViewController.h"

@implementation HtmlListViewController

@synthesize requestFactory;

- (void)viewDidLoad {
    [super viewDidLoad];

    // This object will generate HTML requests for our WebView, that we will use
    // to show the coupon details and fire the redemption
    id theDelegate = [[UIApplication sharedApplication] delegate];
    self.requestFactory = [[theDelegate coupiesManager] requestFactoryForType:kCOUPIESRequestFactoryTypeHTML];

    [self reloadList];
}

- (void)dealloc {
    activityIndicatorView = nil;
    self.requestFactory = nil;
    self.coupon = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)inInterfaceOrientation {
    return YES;
}

#pragma mark - Public methods

- (void)reloadList {
    [activityIndicatorView startAnimating];

    NSURLRequest *theRequest = [self.requestFactory requestForListFeedCoupons];
    [webView loadRequest:theRequest];
}

#pragma mark - Private methods

/**
 * Some coupons can be redeemed by taking a photo of the receipt after buying a product.
 * In this case, we open the photo-view in the COUPIES-framework.
 */
- (void)redeemCouponCashback:(id)sender {
    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
        id theDelegate = [[UIApplication sharedApplication] delegate];

        // Initialize COUPIESCashbackRedemptionViewController from Bundle and present it as a modal
        UIStoryboard *cashbackStoryboard = [UIStoryboard storyboardWithName:@"COUPIESCashbackRedemptionMain" bundle:[NSBundle CoupiesResourcesBundle]];
        COUPIESCashbackRedemptionViewController *viewController = [cashbackStoryboard instantiateViewControllerWithIdentifier:@"COUPIESCashbackRedemptionViewController"];
        viewController.redemptionDelegate = self;
        viewController.restService = [[theDelegate coupiesManager] newRestService];
        viewController.coupon = self.coupon;
        [self presentViewController:viewController animated:YES completion:nil];
    } else {
        // Error handling in case the device has no camera. In this case, those coupons cannot be redeemed.
    }
}

/**
 * This is a general action that triggers the redemption depending on the type of coupon
 * It could be called from an IBAction, but in this case we intercept the click on "redeem now" in the
 * WebView and trigger it from here.
 */
- (IBAction)redeemCoupon {
    // Only coupons can be redeemed. Offers and DailyDeals link to a website instead.
    if ([self.coupon isKindOfClass:[COUPIESCoupon class]]) {
        COUPIESCoupon *theCoupon = self.coupon;
        if (theCoupon.action == kActionCashback) {
            [self redeemCouponCashback:nil];
        } else {
            // In this case we can directly load the green redemption view and need no ViewController in between.
            [self didChooseRedeemDespiteNoSticker];
        }
    }
}

#pragma mark COUPIESCashbackRedemptionViewControllerDelegate

- (void)didFinishPickingReceipt:(NSArray *)images withQuantity:(int)quantity {
    [activityIndicatorView startAnimating];
    [webView loadRequest:[self.requestFactory requestForRedeemingCoupon:self.coupon withReceipt:images quantity:quantity]];
}

/**
 * Called when the user tapped on the close button after an image has been uploaded. 
 * Only called when using the COUPIES UI.
 */
- (void)userDidConfirmImageUpload {

}

/**
 * This is called when the user clicked on a non cashback coupon action
 */
- (void)didChooseRedeemDespiteNoSticker {
    [activityIndicatorView startAnimating];
    [webView loadRequest:[self.requestFactory requestForRedeemingCoupon:self.coupon]];
}

#pragma mark UIWebViewDelegate

- (void)webViewDidStartLoad:(UIWebView *)inWebView {
    [activityIndicatorView startAnimating];
    inWebView.userInteractionEnabled = NO;
}

- (void)webViewDidFinishLoad:(UIWebView *)inWebView {
    // When the details are loaded for a coupon, we parse the coupon object from the loaded HTML
    COUPIESCoupon *theCoupon = [COUPIESCoupon couponFromHtml:inWebView];
    if (theCoupon.couponId > 0) self.coupon = theCoupon;

    [activityIndicatorView stopAnimating];
    inWebView.userInteractionEnabled = YES;
}

- (void)webView:(UIWebView *)inWebView didFailLoadWithError:(NSError *)error {
    [activityIndicatorView stopAnimating];
    inWebView.userInteractionEnabled = YES;
}

/**
 * In this function, we intercept the click in "redeem now", so we can use the native camera feature
 * to take a photo of a receipt where required. In case of a cashback coupon, the HTML-representation redirects to a
 * "preview"-page, where the picture is taken. Since this page is replaced by the native part of the framework,
 * we intercept this as well.
 */
- (BOOL)webView:(UIWebView *)inWebView shouldStartLoadWithRequest:(NSURLRequest *)inRequest navigationType:(UIWebViewNavigationType)inNavigationType {
    if (inRequest.URL.path && [inRequest.URL.path rangeOfString:@"/redemptions/cashback/preview"].location != NSNotFound) {
        [self redeemCoupon];
        return NO;
    } else {
        return YES;
    }
}

@end
