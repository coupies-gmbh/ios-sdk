//
//  COUPIESPayout.h
//  COUPIES
//
//  Created by Felix Schul on 15.08.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"

typedef enum {
    kPaymentStatusPending = 0,
    kPaymentStatusCompleted = 1,
    kPaymentStatusCancelled = 2
} COUPIESPayoutStatus;

typedef enum {
    kTypePaypal = 3,
    kTypeBankaccount = 4,
} COUPIESPayoutType;

@interface COUPIESPayout : COUPIESSAXParseable {
    @private
    int payoutId;
    NSDate *createdAt;
    NSDate *updatedAt;
    COUPIESPayoutType paymenttype;
    double amount;
    NSString *currency;
    COUPIESPayoutStatus paymentstatus;
}

@property int payoutId;
@property (copy) NSDate *createdAt;
@property (copy) NSDate *updatedAt;
@property COUPIESPayoutType paymenttype;
@property double amount;
@property (copy) NSString *currency;
@property COUPIESPayoutStatus paymentstatus;

+ (id)payout;
- (NSString*)statusMessage;

@end