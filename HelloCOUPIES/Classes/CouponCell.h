//
//  CouponCell.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 25.06.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class COUPIESOffer;

@interface CouponCell : UITableViewCell {
    @private
    COUPIESOffer *coupon;
}

@property (nonatomic, copy) COUPIESOffer *coupon;
@property (copy) NSString *title;
@property (copy) NSString *customerName;
@property (weak, readonly) UIImageView *iconView;
@property BOOL isBookmarked;

- (void)setDistance:(float)inDistance;

@end
