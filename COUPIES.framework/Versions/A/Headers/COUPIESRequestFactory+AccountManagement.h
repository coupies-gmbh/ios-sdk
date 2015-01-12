//
//  COUPIESRequestFactory+AccountManagement.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@class COUPIESUser;

@interface COUPIESRequestFactory(AccountManagement)

- (id)requestForRegisterUser:(COUPIESUser *)inUser;
- (id)requestForRefreshingUser;
- (id)requestForUpdatingUser:(COUPIESUser *)inUser;
- (id)requestForRegisterFacebookUser:(COUPIESUser *)inUser;
- (id)requestForRegisterFacebookUser:(COUPIESUser *)inUser loginExisting:(BOOL)inLoginExisting;
- (id)requestForLoginUser:(COUPIESUser *)inUser singleSignon:(bool)inSso;
- (id)requestForRestorePassword:(NSString *)inEmail;
- (id)requestForCashbackPayoutPayPal:(NSString *)inPayPalEmail securityToken:(NSString *)inToken;
- (id)requestForCashbackPayoutAccount:(NSString *)inAccountName number:(NSString *)inAccountNumber bankcode:(NSString *)inBankcode securityToken:(NSString *)inToken;

@end
