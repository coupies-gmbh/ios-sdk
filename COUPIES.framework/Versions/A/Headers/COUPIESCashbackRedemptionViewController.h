//
//  COUPIESCashbackRedemptionViewController.h
//  COUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class COUPIESRestService;
@class COUPIESCoupon;

/**
 * This is the delegate for controllers using a COUPIESCashbackRedemptionViewController.
 */
@protocol COUPIESCashbackRedemptionViewControllerDelegate

/**
 * This delegate function is called, when the user took the receipt picture and reviewed it.
 * Within the delegate function, you should trigger the redemption using
 * @code
 * [self.restService redeemCoupon:self.coupon withReceipt:image];
 * @endcode
 * The redemption is not automatically triggered by this controller, this is deprecated.
 */
- (void)didFinishPickingReceipt:(NSArray *)images withQuantity:(int)quantity;

/**
 * This delegate function is called when the user tapped on the confirm button after
 * an image has been uploaded to the server.
 */
- (void)userDidConfirmImageUpload;

@end

/**
 * This class handles the redemption of a coupon, which is redeemed by uploading a photo of the receipt.
 * It represents the controller layer of the "Photograph the receipt" screen.
 * Example usage:
 * @code
 * COUPIESStickerRedemptionViewController *viewController = [[COUPIESStickerRedemptionViewController alloc] initWithNibName:@"COUPIESStickerRedemptionView" bundle:[NSBundle CoupiesResourcesBundle]];
 * viewController.delegate = self;
 *
 * [self presentViewController:viewController animated:YES completion:nil];
 * @endcode
 *
 * @see https://github.com/coupies-gmbh/ios-sdk for more information.
 */
@interface COUPIESCashbackRedemptionViewController : UIViewController

/**
 Set your viewController to be the delegate here.
 */
@property (nonatomic, unsafe_unretained) IBOutlet id redemptionDelegate;

/**
 * Sets the COUPIESRestService instance to handle the image upload process, e.g.
 * @code
 * id theDelegate = [[UIApplication sharedApplication] delegate];
 * ...
 * viewController.restService = [[theDelegate coupiesManager] newRestService];
 * @endcode
 */
@property (nonatomic, strong) COUPIESRestService *restService;

/**
 * Set the coupon for the current redemption process here, e.g.:
 * @code
 * viewController.coupon = self.coupon;
 * @endcode
 */
@property (nonatomic, strong) COUPIESCoupon *coupon;

/**
 * Sets the number of available images that the user already took. This value is updated by the CameraPreviewController
 * as soon as the user adds or removes another section. Normally there is no need to overwrite this value.
 *
 * Example:
 * @code
 * viewController.numberOfAvailableImages = 0;
 * @endcode
 */
@property (nonatomic) NSInteger numberOfAvailableImages;

/**
 * If set the dismiss animation has already been triggered by another view to avoid a duplicate animation
 */
@property (nonatomic) BOOL dismissAnimationIsRunning;

/**
 * If set a default receipt image is shown in the camera preview.
 */
@property (nonatomic) BOOL isUsingDemoCoupon;

/**
 * If set a progress indicator and success/error message is shown after the
 * image upload like it's used inside the COUPIES application. If set refreshing
 * the coupon detail view has to handled manually, e.g. by using the
 * provided COUPIESCashbackRedemptionViewControllerDelegate method called
 * didFinishImageUploadWithSuccess.
 */
@property (nonatomic) BOOL isUsingCoupiesUI;

/**
 * Triggered by the user when he wants to take a picture
 */
- (IBAction)captureButtonTapped:(id)sender;

/**
 * Triggered by the user when he wants to enable or disable the light at the back of the phone
 */
- (IBAction)lightBtnTapped:(id)sender;

/**
 * Triggered by the user when he wants to switch between the manual or auto camera mode (default)
 */
- (IBAction)cameraModeBtnTapped:(id)sender;

/**
 * Triggered by the user when he wants to dismiss the camera view
 */
- (IBAction)closeBtnTapped:(id)sender;

@end

