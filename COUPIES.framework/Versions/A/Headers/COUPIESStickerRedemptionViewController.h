//
//  COUPIESStickerRedemptionViewController.h
//  COUPIES
//
//  Created by Felix Schul on 03.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZBarSDK.h"

@class COUPIESManager;
@class COUPIESCoupon;

/**
 This is the delegate for controllers using a COUPIESStickerRedemptionViewController.
 */
@protocol COUPIESStickerRedemptionViewControllerDelegate

/**
 This delegate function is called, when the user scanned a valid COUPIES Touchpoint.
 Within the delegate function, you should trigger the redemption using
 @code
 [self.restService redeemCoupon:self.coupon withStickercode:stickercode];
 @endcode
 The redemption is not automatically trigerred by this controller, this is deprecated.
 */
-(void)didScanValidStickerWithCode:(NSString *)stickercode;

/**
 This delegate function is called, when the user clicked on "no sticker" and chose to
 redeem anyway. We allow the user to do this anyways because it can always happen that
 a Touchpoint broke or was removed.
 Within the delegate function, you should trigger the redemption using
 @code
 [self.restService redeemCoupon:self.coupon];
 @endcode
 The redemption is not automatically trigerred by this controller, this is deprecated.
 */
-(void)didChooseRedeemDespiteNoSticker;

@optional

/**
 This delegate function is called, when the user clicks the "no sticker"-button
 and can be optionally used e.g. for analytics.
 */
-(void)noStickerButtonPressed;

/**
 This delegate function is called, when the user clicks the "how to"-button
 and can be optionally used e.g. for analytics.
 */
-(void)howToButtonPressed;

@end

/**
 This class handles the redemption of a coupon, which is redeemed using a COUPIES touchpoint.
 It represents the controller layer of the "Scan the COUPIES sticker" screen.
 Example usage:
 @code
 COUPIESStickerRedemptionViewController *viewController = [[COUPIESStickerRedemptionViewController alloc] initWithNibName:@"COUPIESStickerRedemptionView" bundle:[NSBundle CoupiesResourcesBundle]];
 viewController.delegate = self;
 
 [self presentViewController:viewController animated:YES completion:nil];
 @endcode
 This class uses the Zbar library for iOs to read the QR code on the COUPIES touchpoint.
 
 @see https://github.com/coupies-gmbh/ios-sdk for more information.
 @see http://zbar.sourceforge.net/iphone/sdkdoc/install.html for more information on ZBar.
 */
@interface COUPIESStickerRedemptionViewController : UIViewController <ZBarReaderViewDelegate> {
@private
    COUPIESManager *coupiesManager;
    COUPIESCoupon *coupon;
    IBOutlet UIView *howToView;
    IBOutlet UIView *reader;
}

/**
 Use this property to customize the appearance.
 */
@property (nonatomic) IBOutlet id delegate;

/**
 Access to the ZBAR reader, that scans the barcode.
 */
@property (nonatomic) IBOutlet UIView *reader;

/**
 Use this property to customize the appearance.
 */
@property (nonatomic) IBOutlet UIButton *leftButton;

/**
 Use this property to customize the appearance.
 */
@property (nonatomic) IBOutlet UIButton *rightButton;

/**
 Use this property to customize the appearance.
 */
@property (nonatomic) IBOutlet UILabel *infoLabel;

/**
 Use this property to customize the appearance.
 */
@property (nonatomic) IBOutlet UINavigationBar *navbar;

/**
 Access to the ZBar reader.
 @see http://zbar.sourceforge.net/iphone/sdkdoc/install.html for more information on ZBar.
 */
@property (nonatomic, strong) ZBarReaderView *readerView;

@end

