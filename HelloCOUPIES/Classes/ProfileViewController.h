//
//  ProfileViewController.h
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <COUPIES/COUPIES.h>

// This is the simplest way to display the user profile.
// The user profile is only required, when you use the cashback functionality (API-Level 4)

@interface ProfileViewController : UIViewController {
    @private
    COUPIESRequestFactory *requestFactory;
    IBOutlet UIWebView *webView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
}

@property (nonatomic, strong) COUPIESRequestFactory *requestFactory;

-(IBAction)reload;

@end
