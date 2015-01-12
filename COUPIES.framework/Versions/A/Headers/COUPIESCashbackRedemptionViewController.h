//
//  COUPIESCashbackRedemptionViewController.h
//  COUPIES
//
//  Created by Felix Schul on 01.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "COUPIESCamPreviewView.h"

@protocol COUPIESCashbackRedemptionViewControllerDelegate

//This delegate function is called, when the user took the receipt pickture and reviewed it.
//Within the delegate function, you should trigger the redemption using
//[self.restService redeemCoupon:self.coupon withReceipt:image];
//The redemption is not automatically trigerred by this controller, this is deprecated
-(void)didFinishPickingReceipt:(NSArray *)images withQuantity:(int)quantity;

@optional

//This delegate function is called, when the user clicks the "how to"-button
//and can be optionally used e.g. for analytics
-(void)howToButtonPressed;

//This delegate function is called, when the user clicked on "yes, send now" and before
//didFinishPickingReceipt: is invoced. There is a small time lack of about 1 second between those
//because the compression of the image takes some time.
//It is advised to start displaying an ActivityIndicator at this point.
-(void)didStartCompressingImage;

@end

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

@property (nonatomic, unsafe_unretained) IBOutlet id redemptionDelegate;
@property int remaining;


-(IBAction)takePicture:(id)sender;
-(IBAction)showHideHowToView:(id)sender;
-(IBAction)approveImage:(id)sender;
-(IBAction)rejectImage:(id)sender;
-(IBAction)incrementProductCount:(id)sender;
-(IBAction)decrementProductCount:(id)sender;
-(IBAction)sendImage:(id)sender;
-(IBAction)closeViewController:(id)sender;
-(IBAction)takeMorePictures:(id)sender;


@end

