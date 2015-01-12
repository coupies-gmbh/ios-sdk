//
//  COUPIESRestService+User.h
//  COUPIES
//
//  Created by Clemens Wagner on 27.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRestService.h"

@class COUPIESUser;

@interface COUPIESRestService(AccountManagement)

- (void)registerUser:(COUPIESUser *)inUser;
- (void)updateUser:(COUPIESUser *)inUser;
- (void)refreshUser;
- (void)registerFacebookUser:(COUPIESUser *)inUser;
- (void)registerFacebookUser:(COUPIESUser *)inUser loginExisting:(BOOL)inLoginExisting;
- (void)loginUser:(COUPIESUser *)inUser;
- (void)loginUser:(COUPIESUser *)inUser singleSignon:(bool)inSso;
- (void)restorePassword:(NSString *)inEmail;
- (void)requestCashbackPayoutPayPal:(NSString *)inPayPalEmail securityToken:(NSString *)inToken;
- (void)requestCashbackPayoutAccount:(NSString *)inAccountName number:(NSString *)inAccountNumber bankcode:(NSString *)inBankcode securityToken:(NSString *)inToken;

@end
