//
//  COUPIESRestService+Bookmarks.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRestService.h"
#import "COUPIESOffer.h"

extern NSString * const kCOUPIESWillUpdateBookmark;
extern NSString * const kCOUPIESWillUpdateLike;

@interface COUPIESRestService(Bookmarks)

- (void)listBookmarks;
- (void)bookmarkCoupon:(COUPIESOffer *)inCoupon status:(BOOL)inStatus;
- (void)likeCoupon:(COUPIESOffer *)inCoupon status:(BOOL)inStatus;
- (void)listPushedCoupons;
- (void)listPushedCoupons:(BOOL)inIncludeRead;

@end
