//
//  COUPIESTutorialPageRootController.h
//
//  Created by Marcel Bender.
//  Copyright © 2016 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "COUPIESTutorialPageContentController.h"

@interface COUPIESTutorialPageRootController : UIViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UIButton *captureBtn;

@property (strong, nonatomic) UIPageViewController *pageViewController;
@property (strong, nonatomic) NSArray *pageTitles;
@property (strong, nonatomic) NSArray *pageImages;

- (IBAction)captureBtnTapped:(id)sender;
- (IBAction)skipBtnTapped:(id)sender;

@end
