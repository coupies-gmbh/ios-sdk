//
//  HelloCOUPIESAppDelegate.h
//  HelloCOUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class COUPIESManager;

// This is a simple demo-application that shows how to use the COUPIES-framework and integrate
// coupons into your application.
// For the simplest and fastest integration, see HtmlListViewController.
// In case of questions please contact felix.schul@coupies.de
@interface HelloCOUPIESAppDelegate : NSObject <UIApplicationDelegate, UITabBarControllerDelegate> {
    UIWindow *window;
    UITabBarController *tabBarController;
    COUPIESManager *coupiesManager;
}

@property (nonatomic, strong) IBOutlet UIWindow *window;
@property (nonatomic, strong) IBOutlet UITabBarController *tabBarController;
@property (nonatomic, strong) IBOutlet COUPIESManager *coupiesManager;

@end
