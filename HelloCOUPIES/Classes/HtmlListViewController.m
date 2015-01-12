#import "HtmlListViewController.h"
#import "HelloCOUPIESAppDelegate.h"
#import <COUPIES/COUPIES.h>

@interface HtmlListViewController()<COUPIESRestServiceDelegate>{
    //We will intercept the regular redemption call in the webview in order
    //to open the camera for Touchpoint-redemption or cashback redemption.
    //This variable stores whether we triggered the redemption manually
    //after the scan of the touchpoint, so it is not intercepted again and forms a loop.
    BOOL didTriggerRedemption;
}

@property (nonatomic, strong) COUPIESCoupon *coupon;

- (void)reset;

@end

@implementation HtmlListViewController

@synthesize requestFactory;
@synthesize coupon;

- (void)dealloc {
    [self reset];
}

- (void)reset {
    activityIndicatorView = nil;
    self.requestFactory = nil;
    self.coupon = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    id theDelegate = [[UIApplication sharedApplication] delegate];
    //This object will genereate HTML requests for our WebView, that we will use to show the coupon
    //details and fire the redemption
    self.requestFactory = [[theDelegate coupiesManager] requestFactoryForType:kCOUPIESRequestFactoryTypeHTML];
    [self reloadList];
}

- (void)viewDidUnload {
    [self reset];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)inInterfaceOrientation {
    return YES;
}

#pragma mark public methods

-(void)reloadList {
    [activityIndicatorView startAnimating];
    NSURLRequest *theRequest = [self.requestFactory requestForListFeedCoupons];
    [webView loadRequest:theRequest]; //Load the couponlist
}

#pragma mark private methods

//Some coupons can be redeemed in the branch by scanning the COUPIES-Touchpoint (or sticker)
//In this case, we open the scan-view in the COUPIES-framework
- (void)redeemCouponViaSticker:(id)sender {
    COUPIESStickerRedemptionViewController *viewController = [[COUPIESStickerRedemptionViewController alloc] initWithNibName:@"COUPIESStickerRedemptionView" bundle:[NSBundle CoupiesResourcesBundle]];
    viewController.delegate = self;
    
    [self presentModalViewController:viewController animated:YES];
}

//Some coupons can be redeemed by taking a photo of the receipt after buying a product.
//In this case, we open the photo-view in the COUPIES-framework
- (void)redeemCouponCashback:(id)sender {
    if([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
        COUPIESCashbackRedemptionViewController *viewController = [[COUPIESCashbackRedemptionViewController alloc] initWithNibName:@"COUPIESCashbackRedemptionView" bundle:[NSBundle CoupiesResourcesBundle]];
        viewController.redemptionDelegate = self;
        
        //Optionally set the number of remaining redemptions. This will let the user choose the number of coupons he wants to redeem
        //at once on this receipt. If not set, COUPIES will decide.
        viewController.remaining = self.coupon.remaining;
        
        [self presentModalViewController:viewController animated:YES];
    } else {
        //Error handling in case the device has no camera. In this case, those coupons cannot be redeemed.
    }
}

//This is a general action that triggers the redemption depending on the type of coupon
//It could be called from an IBAction, but in this case we intercept the click on "redeem now" in the
//WebView and trigger it from here
- (IBAction)redeemCoupon {
    //Only coupons can be redeemd. Offers and DailyDeals link to a website instead.
    if ([self.coupon isKindOfClass:[COUPIESCoupon class]]) {
        
        COUPIESCoupon *theCoupon = (COUPIESCoupon *)self.coupon;
        
        if (theCoupon.action == kActionCashback) {
            [self redeemCouponCashback:nil];
        } else if (theCoupon.action == kActionRedeemInShop) {
            if (theCoupon.closestLocationAcceptsSticker) {
                [self redeemCouponViaSticker:nil];
            } else {
                //In this case we can directly load the green redemption view and need no viewController in between.
                [self didChooseRedeemDespiteNoSticker];
            }
        }
    }
}

#pragma mark COUPIESStickerRedemptionViewControllerDelegate

//This is called after the user scanned a COUPIES-Touchpoint
-(void)didScanValidStickerWithCode:(NSString *)stickercode {
    [activityIndicatorView startAnimating];
    didTriggerRedemption = YES;
    [webView loadRequest:[self.requestFactory requestForRedeemingCoupon:self.coupon withStickercode:stickercode]];
}

//This is called when the user clicked on "no sticker"
-(void)didChooseRedeemDespiteNoSticker {
    [activityIndicatorView startAnimating];
    didTriggerRedemption = YES;
    [webView loadRequest:[self.requestFactory requestForRedeemingCoupon:self.coupon]];
}

#pragma mark COUPIESCashbackRedemptionViewControllerDelegate

-(void)didFinishPickingReceipt:(NSArray *)images withQuantity:(int)quantity {
    didTriggerRedemption = YES;
    [webView loadRequest:[self.requestFactory requestForRedeemingCoupon:self.coupon withReceipt:images quantity:quantity]];
}

-(void)didStartCompressingImage {
    //For a more sophisticated implementation, you could use a UIProgressView and implement
    //restService:didSendBodyData: to show the progress of the upload
    [activityIndicatorView startAnimating];
}

#pragma mark COUPIESRestServiceDelegate

- (void)restService:(COUPIESRestService *)inService receivedResult:(NSArray *)inResult {
    
}

- (void)restService:(COUPIESRestService *)inService receivedErrors:(NSArray *)inErrors {
    
}

- (void)restService:(COUPIESRestService *)inService didSendBodyData:(NSDictionary *)inInfo {
    
}

#pragma mark UIWebViewDelegate

- (void)webViewDidStartLoad:(UIWebView *)inWebView {    
    [activityIndicatorView startAnimating];
    inWebView.userInteractionEnabled = NO;
}

- (void)webViewDidFinishLoad:(UIWebView *)inWebView {
    
    //When the details are loaded for a coupon, we parse the coupon object from the loaded HTML
    COUPIESCoupon *theCoupon = [COUPIESCoupon couponFromHtml:inWebView];
    if (theCoupon.couponId > 0) self.coupon = theCoupon; //Found a coupon in the HTML-code
    
    [activityIndicatorView stopAnimating];
    didTriggerRedemption = NO;
    inWebView.userInteractionEnabled = YES;
}

- (void)webView:(UIWebView *)inWebView didFailLoadWithError:(NSError *)error {
    [activityIndicatorView stopAnimating];
    inWebView.userInteractionEnabled = YES;
}

//In this function, we intercept the click in "redeem now", so we can use the native camera feature
//to scan the COUPIES-Touchpoint or take a photo of a receipt where required
- (BOOL)webView:(UIWebView *)inWebView shouldStartLoadWithRequest:(NSURLRequest *)inRequest navigationType:(UIWebViewNavigationType)inNavigationType {

    NSURLRequest *theRequest = [self.requestFactory requestForRedeemingCoupon:self.coupon];
    
    //We compare the request to a generated redemption request. If it is the same (and was not just triggered by us)
    //we intercept.
    if ([theRequest.URL.path isEqualToString:inRequest.URL.path] && didTriggerRedemption == NO) {
        [self redeemCoupon];
        return NO;
    } else if ([inRequest.URL.path rangeOfString:@"/redemptions/cashback/preview"].location != NSNotFound) {
        //In case of a Cashback-Coupon, the HTML-representation redirects to a "preview"-page, where the picture
        //is taken. Since this page is replaced by the native part of the framework, we intercept this as well.
        [self redeemCouponCashback:nil];
        return NO;
    } else {
        return YES;
    }
}

@end
