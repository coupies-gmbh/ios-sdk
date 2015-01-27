//
//  HelloCOUPIESAppDelegate.m
//  HelloCOUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "HelloCOUPIESAppDelegate.h"
#import <COUPIES/COUPIES.h>

@implementation HelloCOUPIESAppDelegate

@synthesize window;
@synthesize tabBarController;
@synthesize coupiesManager;


#pragma mark Application lifecycle

/*
 Initialize your COUPIESManager
 see COUPIES.plist for additional configurations
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    /*
     Set this parameter to any unique user ID (e.g. a hashed version of your internal user ID) or leave blank.
     If you do not set this parameter, COUPIES will generate a unique user ID using SecureUDID (see http://www.secureudid.org
     for more information).
     If you experience an error when redeeming a coupon, please contact felix.schul@coupies.de to check the backend settings.
    */
    //self.coupiesManager.partnerToken = @"6";
    
    //Request an API key at felix.schul@coupies.de and remove this error message. Copy the file \"COUPIES.plist\" from the example project to your local resources and enter the API-key there.
    [NSException raise:@"Request an API key at felix.schul@coupies.de and remove this error message. Copy the file \"COUPIES.plist\" from the example project to your local resources and enter the API-key there." format:@""];
    
    self.window.rootViewController = tabBarController;
    [window makeKeyAndVisible];
    return YES;
}

@end