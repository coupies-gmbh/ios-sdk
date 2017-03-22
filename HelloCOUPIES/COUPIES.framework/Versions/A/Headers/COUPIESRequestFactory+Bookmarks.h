//
//  COUPISRequestFactory+Bookmarks.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@interface COUPIESRequestFactory(Bookmarks)

- (id)requestForBookmarks;
- (id)requestForBookmarkCoupon:(COUPIESOffer *)inCoupon status:(BOOL)inStatus;
- (id)requestForLikeCoupon:(COUPIESOffer *)inCoupon status:(BOOL)inStatus;
- (id)requestForPushedCoupons;
- (id)requestForPushedCoupons:(BOOL)inIncludeRead;

@end
