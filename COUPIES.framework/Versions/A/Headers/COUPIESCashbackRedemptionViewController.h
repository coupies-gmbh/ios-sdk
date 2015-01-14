//
//  COUPIESCashbackRedemptionViewController.h
//  COUPIES
//
//  Created by Felix Schul on 01.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class COUPIESCamPreviewView;

/**
 This is the delegate for controllers using a COUPIESCashbackRedemptionViewController.
 */
@protocol COUPIESCashbackRedemptionViewControllerDelegate

/**
 This delegate function is called, when the user took the receipt picture and reviewed it.
 Within the delegate function, you should trigger the redemption using
 @code
 [self.restService redeemCoupon:self.coupon withReceipt:image];
 @endcode
 The redemption is not automatically trigerred by this controller, this is deprecated.
 */
-(void)didFinishPickingReceipt:(NSArray *)images withQuantity:(int)quantity;

@optional

/**
 This delegate function is called, when the user clicks the "how to"-button
 and can be optionally used e.g. for analytics
 */
-(void)howToButtonPressed;

/**
 This delegate function is called, when the user clicked on "yes, send now" and before
 didFinishPickingReceipt: is invoced. There is a small time lack of about 1 second between those
 because the compression of the image takes some time.
 It is advised to start displaying an ActivityIndicator at this point.
 */
-(void)didStartCompressingImage;

@end

/**
 This class handles the redemption of a coupon, which is redeemed by uploading a photo of the receipt.
 It represents the controller layer of the "Photograph the receipt" screen.
 Example usage:
 @code
 COUPIESStickerRedemptionViewController *viewController = [[COUPIESStickerRedemptionViewController alloc] initWithNibName:@"COUPIESStickerRedemptionView" bundle:[NSBundle CoupiesResourcesBundle]];
 viewController.delegate = self;
 
 [self presentViewController:viewController animated:YES completion:nil];
 @endcode
 
 @see https://github.com/coupies-gmbh/ios-sdk for more information.
 */
@interface COUPIESCashbackRedemptionViewController : UIViewController {
    @private
    int remaining;
    int quantity;
    IBOutlet UINavigationBar *navbar;
    IBOutlet COUPIESCamPreviewView *cameraView;
    IBOutlet UIView *howToView1;
    IBOutlet UIView *howToView2;
    
    IBOutlet UIView *bottomView;
    IBOutlet UIView *takePictureView;
    IBOutlet UIView *comfirmPictureView;
    IBOutlet UIView *countProductView;
    IBOutlet UIButton *cameraButton;
    IBOutlet UITextField *productCountTextField;
    IBOutlet UIButton *howToButton;
    IBOutlet UIImageView *imageLookup;
    IBOutlet UIButton *takeMorePicturesButton;
    IBOutlet UIScrollView *lookupImagesScrollView;
    IBOutlet UIImageView *cameraOverlayImage;
    IBOutlet UIView *overlayHelpView;
    
}

/**
 Set your viewController to be the delegate here.
 */
@property (nonatomic, unsafe_unretained) IBOutlet id redemptionDelegate;

/**
 Set the number of remaining redemptions for the user and the coupon here. e.g.:
 @code
 viewController.remaining = self.coupon.remaining;
 @endcode
 If you set this property, the view will not allow to enter an amount larger than the 
 remaining coupons.
 */
@property int remaining;

/**
 Triggered by the user when pressing the photo button.
 */
-(IBAction)takePicture:(id)sender;

/**
 Triggered by the user to open/close the howto view.
 */
-(IBAction)showHideHowToView:(id)sender;

/**
 Triggered by the user when the image is reviewed.
 */
-(IBAction)approveImage:(id)sender;

/**
 Triggered by the user when he wants to take the image again.
 */
-(IBAction)rejectImage:(id)sender;

/**
  Triggered by the user when he increaeses the number of redemptions.
 */
-(IBAction)incrementProductCount:(id)sender;

/**
  Triggered by the user when he decreaeses the number of redemptions.
 */
-(IBAction)decrementProductCount:(id)sender;

/**
  Starts sending the image to COUPIES.
 */
-(IBAction)sendImage:(id)sender;

/**
 Triggered when the user closes the view using the "X" button.
 */
-(IBAction)closeViewController:(id)sender;

/**
 Triggered by the user to add another photo of the receipt (up to 3)
 */
-(IBAction)takeMorePictures:(id)sender;


@end

