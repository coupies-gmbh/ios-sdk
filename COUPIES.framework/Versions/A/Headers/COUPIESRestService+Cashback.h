//
//  COUPIESRestService+Cashback.h
//  COUPIES
//
//  Created by Felix Schul on 12.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRestService.h"

@interface COUPIESRestService(Cashback)

- (void)listCashbackRedemptions;
- (void)uploadReceipt:(NSData *)inImage;
- (void)updateReceipt:(NSInteger)inReciptId withComment:(NSString *)inComment;

@end
