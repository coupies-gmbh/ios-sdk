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

@protocol COUPIESStickerRedemptionViewControllerDelegate

//This delegate function is called, when the user scanned a valid COUPIES Touchpoint
//Within the delegate function, you should trigger the redemption using
//[self.restService redeemCoupon:self.coupon withStickercode:stickercode];
//The redemption is not automatically trigerred by this controller, this is deprecated
-(void)didScanValidStickerWithCode:(NSString *)stickercode;

//This delegate function is called, when the user clicked on "no sticker" and chose to
//redeem anyways. We allow the user to do this anyways because it can always happen that
//a Touchpoint broke or was removed
//Within the delegate function, you should trigger the redemption using
//[self.restService redeemCoupon:self.coupon];
//The redemption is not automatically trigerred by this controller, this is deprecated
-(void)didChooseRedeemDespiteNoSticker;

@optional

//This delegate function is called, when the user clicks the "no sticker"-button
//and can be optionally used e.g. for analytics
-(void)noStickerButtonPressed;

//This delegate function is called, when the user clicks the "how to"-button
//and can be optionally used e.g. for analytics
-(void)howToButtonPressed;

@end

@interface COUPIESStickerRedemptionViewController : UIViewController <ZBarReaderViewDelegate> {
@private
    COUPIESManager *coupiesManager;
    COUPIESCoupon *coupon;
    IBOutlet UIView *howToView;
    IBOutlet UIView *reader;
}

@property (nonatomic) IBOutlet id delegate;
@property (nonatomic) IBOutlet UIView *reader;
@property (nonatomic) IBOutlet UIButton *leftButton;
@property (nonatomic) IBOutlet UIButton *rightButton;
@property (nonatomic) IBOutlet UILabel *infoLabel;
@property (nonatomic) IBOutlet UINavigationBar *navbar;
@property (nonatomic, strong) COUPIESCoupon *coupon;
@property (nonatomic, strong) ZBarReaderView *readerView;

@end

