//
//  COUPIESPromotion.h
//  COUPIES
//
//  Created by karim wahishi on 25.03.14.
//  Copyright (c) 2014 COUPIES GmbH. All rights reserved.
//

#import "COUPIESCoupon.h"

@interface COUPIESPromotion : COUPIESCoupon {
@private
    NSString *promotionButtonText;
}

@property (copy) NSString *promotionButtonText;

+ (id)promotion;

@end
