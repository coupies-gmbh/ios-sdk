//
//  COUPIESDeal.h
//  COUPIES
// 
//  Diese Klasse beschreibt einen Kauf-Deal ala Groupon
//
//  Created by Felix Schul on 23.03.12.
//  Copyright (c) 2012 COUPIES GmbH. All rights reserved.
//

#import "COUPIESCoupon.h"

@interface COUPIESDeal : COUPIESCoupon {
    @private
    NSString *fineprint;
    NSString *highlights;
    double price;
    double originalPrice;
    double discount;
}

@property (copy) NSString *fineprint;
@property (copy) NSString *highlights;
@property double price;
@property double originalPrice;
@property double discount;

+ (id)deal;

@end
