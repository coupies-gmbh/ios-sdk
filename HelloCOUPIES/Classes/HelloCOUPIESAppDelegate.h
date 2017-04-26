//
//  HelloCOUPIESAppDelegate.h
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class COUPIESManager;

// This is a simple demo-application that shows how to use the COUPIES-framework and integrate
// coupons into your application.
// For the simplest and fastest integration, see HtmlListViewController.
// In case of questions please contact marcel.bender@coupies.de

@interface HelloCOUPIESAppDelegate : NSObject <UIApplicationDelegate, UITabBarControllerDelegate>

@property (nonatomic, strong) IBOutlet UIWindow *window;
@property (nonatomic, strong) IBOutlet UITabBarController *tabBarController;
@property (nonatomic, strong) IBOutlet COUPIESManager *coupiesManager;

@end
