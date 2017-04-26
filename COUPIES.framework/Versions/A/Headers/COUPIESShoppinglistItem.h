//
//  COUPIESShoppinglistItem.h
//  Coupies-iOs-SDK
//
//  Created by Felix Gillen on 31.01.16.
//  Copyright © 2016 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESShoppinglistItem : COUPIESSAXParseable {
@private
    NSString *itemId;
    NSString *title;
    NSNumber *checked;
    NSDate *createdAt;
    NSDate *updatedAt;
    NSDate *deletedAt;
}

@property(copy) NSString *itemId;
@property(copy) NSString *title;
@property(copy) NSNumber *checked;
@property(copy) NSDate *createdAt;
@property(copy) NSDate *updatedAt;
@property(copy) NSDate *deletedAt;

+ (id)shoppinglistItem;

@end
