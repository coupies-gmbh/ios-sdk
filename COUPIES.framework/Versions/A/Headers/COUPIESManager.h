//
//  COUPIESManager.h
//  COUPIES
//
//  Created by Clemens Wagner on 27.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@class CLLocationManager;

@interface COUPIESManager : NSObject<COUPIESRequestFactoryDelegate> {
    @private
    NSString *apiKey;
    NSString *secret;
    NSString *secretType;
    NSString *restServer;
    NSString *apiLevel;
    NSTimeInterval timeout;
    Class restServiceClass;
    Class requestFactoryClass;
    CLLocationManager *locationManager;
    struct _managerFlags {
        BOOL didSetUp;
        BOOL shouldCreateLocationManager;
        BOOL didStartLocationManager;
    } managerFlags;
    id requestFactories;
}

@property (nonatomic, copy) NSString *apiKey;
@property (nonatomic, copy) NSString *rememberKey;
@property (nonatomic, copy) NSString *partnerToken;
@property (nonatomic, copy) NSString *restServer;
@property (nonatomic, copy) NSString *apiLevel;
@property (nonatomic) NSTimeInterval timeout;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong, readonly) NSDictionary *credentials;

- (void)reset;
- (id)newRestService;
- (id)requestFactoryForType:(NSString *)inType;

@end
