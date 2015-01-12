//
//  COUPIESReceipt.h
//  COUPIES
//
//  Created by Felix Schul on 15.08.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESReceipt : COUPIESSAXParseable {
    @private
    int receiptId;
    NSDate *date;
    NSURL *imageURL;
    double sum;
}

@property int receiptId;
@property (copy) NSDate *date;
@property (copy) NSURL *imageURL;
@property double sum;

+ (id)receipt;

@end