//
//  HelloCOUPIESAppDelegate.m
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import "HelloCOUPIESAppDelegate.h"

@implementation HelloCOUPIESAppDelegate

#pragma mark - Application Lifecycle

/**
 * Initialize your COUPIESManager. See COUPIES.plist for additional configurations
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window.rootViewController = self.tabBarController;
    [self.window makeKeyAndVisible];
    
    /*
     * Set this parameter to any unique user ID (e.g. a hashed version of your internal user ID) or leave blank.
     * If you do not set this parameter, COUPIES will generate a unique user ID using SecureUDID (see http://www.secureudid.org
     * for more information).
     * If you experience an error when redeeming a coupon, please contact felix.schul@coupies.de to check the backend settings.
    */
    //self.coupiesManager.partnerToken = @"6";
    
    /*
     * Request an API key at marcel.bender@coupies.de and remove this error alert.
     * Copy the file \"COUPIES.plist\" from the example project to your local resources and enter the API-key there.
     */
    if (![self isApiKeyPresent]) {
        [self showMissingApiKeyAlert];
    }
    
    return YES;
}

#pragma mark - API Key Handling

/**
 * Checks if the kCOUPIESApiKey in the COUPIES.plist is present.
 * @return {Boolean} YES if present, NO if not present
 */
- (BOOL)isApiKeyPresent {
    NSString *plistPath = [[NSBundle mainBundle] pathForResource:@"COUPIES" ofType:@"plist"];
    NSDictionary *plistContent = [NSDictionary dictionaryWithContentsOfFile:plistPath];
    
    return plistContent[@"kCOUPIESApiKey"] != nil && [plistContent[@"kCOUPIESApiKey"] length] > 0
}

/**
 * Shows an alert controller in the root view controller informing about the missing API key.
 */
- (void)showMissingApiKeyAlert {
    UIAlertController *missingApiKeyAlert =
            [UIAlertController alertControllerWithTitle:@"Missing API Key"
                                                message:@"Request an API key at marcel.bender@coupies.de and remove this error message.\n\nCopy the file \"COUPIES.plist\" from the example project to your local resources and enter the API-key there."
                                         preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *dismissAction = [UIAlertAction actionWithTitle:@"Dismiss" style:UIAlertActionStyleDefault handler:nil];
    [missingApiKeyAlert addAction:dismissAction];

    [self.window.rootViewController presentViewController:missingApiKeyAlert animated:YES completion:nil];
}

@end
