//
//  COUPIESRequestFactory+Cashback.h
//  COUPIES
//
//  Created by Felix Schul on 12.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@interface COUPIESRequestFactory(Cashback)

- (id)requestForListCashbackRedemptions;
- (id)requestForUploadingReceipt:(NSData *)inImage;

@end
