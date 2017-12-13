//
//  COUPIESCameraPreviewViewController.h
//
//  Created by Marcel Bender
//  Copyright © 2016 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBCircularProgressBarView.h"
#import "COUPIESCashbackRedemptionViewController.h"
#import "COUPIESRestWrapper.h"

@protocol COUPIESCameraViewControllerDelegate;
@protocol COUPIESCashbackRedemptionViewControllerDelegate;
@class COUPIESRestService;
@class COUPIESCoupon;
@class COUPIESOffer;
@class COUPIESRedemption;

@interface COUPIESCameraPreviewViewController : UIViewController <UIScrollViewDelegate, UITabBarDelegate, COUPIESCashbackRedemptionViewControllerDelegate,
    UIGestureRecognizerDelegate>

@property (nonatomic, weak) id<COUPIESCameraViewControllerDelegate> delegate;
@property (nonatomic, weak) id<COUPIESCashbackRedemptionViewControllerDelegate> redemptionDelegate;
@property (strong, nonatomic) COUPIESRestService *restService;
@property (strong, nonatomic) COUPIESOffer *coupon;
@property (weak, nonatomic) IBOutlet MBCircularProgressBarView *uploadProgressBar;
@property (strong, nonatomic) IBOutlet UIVisualEffectView *quantityOverlay;
@property (strong, nonatomic) IBOutlet UIVisualEffectView *qualityOverlay;
@property (strong, nonatomic) IBOutlet UIVisualEffectView *uploadOverlay;
@property (strong, nonatomic) IBOutlet UIVisualEffectView *loadingOverlay;
@property (weak, nonatomic) IBOutlet UILabel *navigationTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *navigationSubtitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *quantityOverlayCountLabel;
@property (weak, nonatomic) IBOutlet UILabel *uploadTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *uploadInfoLabel;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *sendButtonItem;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *cancelButtonItem;
@property (weak, nonatomic) IBOutlet UIButton *quantityOverlaySendButton;
@property (weak, nonatomic) IBOutlet UIButton *qualityOverlayNextButton;
@property (weak, nonatomic) IBOutlet UIButton *uploadCloseButton;
@property (weak, nonatomic) IBOutlet UIButton *uploadAbortButton;
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (weak, nonatomic) IBOutlet UIImageView *previewImageView;
@property (weak, nonatomic) IBOutlet UITabBar *tabBar;
@property (weak, nonatomic) IBOutlet UIStepper *quantityStepper;
@property (strong, nonatomic) IBOutlet UITapGestureRecognizer *doubleTabRecognizer;
@property (strong, nonatomic) NSString *image01Path;
@property (strong, nonatomic) NSString *image02Path;
@property (strong, nonatomic) NSString *image03Path;
@property (strong, nonatomic) NSString *usedCameraMode;
@property (nonatomic) NSInteger numberOfAvailableImages;
@property (nonatomic) NSInteger numberOfPossibleRedemptions;
@property (nonatomic) NSInteger numberOfSelectedRedemptions;
@property (nonatomic) BOOL isUsingDemoReceipt;
@property (nonatomic) BOOL isUsingCoupiesUI;

- (IBAction)deleteBtnTapped:(id)sender;
- (IBAction)addSectionBtnTapped:(id)sender;
- (IBAction)helpBtnTapped:(id)sender;
- (IBAction)cancelButtonItemTapped:(id)sender;
- (IBAction)sendButtonItemTapped:(id)sender;
- (IBAction)quantityStepperChanged:(id)sender;
- (IBAction)quantityOverlaySendButtonTapped:(id)sender;
- (IBAction)quantityAbortButtonTapped:(id)sender;
- (IBAction)qualityNextButtonTapped:(id)sender;
- (IBAction)qualityAbortButtonTapped:(id)sender;
- (IBAction)uploadCloseButtonTapped:(id)sender;
- (IBAction)uploadAbortButtonTapped:(id)sender;
- (IBAction)handleDoubleTapFrom:(UITapGestureRecognizer *)recognizer;

@end

@protocol COUPIESCameraViewControllerDelegate <NSObject>

- (void)updateImageCount:(NSInteger)counter;
- (void)willAddNewSection;

@end
