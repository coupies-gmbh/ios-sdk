//
//  COUPIESShoppinglist.h
//  Coupies-iOs-SDK
//
//  Created by Felix Gillen on 31.01.16.
//  Copyright © 2016 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESShoppinglist : COUPIESSAXParseable {
@private
    NSMutableArray *listItems;
}

@property(copy) NSMutableArray *listItems;

+ (id)shoppinglist;

@end
