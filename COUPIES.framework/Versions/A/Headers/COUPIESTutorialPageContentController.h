//
//  TutorialPageContentController.h
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface COUPIESTutorialPageContentController : UIViewController

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UILabel *descriptionLabel;

@property (weak, nonatomic) NSString *descriptionText;
@property (strong, nonatomic) NSString *imageFile;
@property (nonatomic) NSUInteger pageIndex;

@end
