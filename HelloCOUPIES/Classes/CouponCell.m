//
//  CouponCell.m
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 25.06.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "CouponCell.h"
#import "UIImageView+WebCache.h"
#import <COUPIES/COUPIES.h>

#define TITLE_TAG 100
#define CUSTOMER_TAG 101
#define DISTANCE_TAG 102
#define COUNT_TAG 103
#define ICON_TAG 104
#define BOOKMARKS_TAG 105
#define DATE_TAG 106
#define DISCLOSURE_TAG 107

@interface CouponCell()

@property (weak, nonatomic, readonly) UILabel *titleLabel;
@property (weak, nonatomic, readonly) NSString *remainingText;

@end

@implementation CouponCell

@synthesize coupon;

- (void)dealloc {
    NSNotificationCenter *theCenter = [NSNotificationCenter defaultCenter];

    [theCenter removeObserver:self];
    self.coupon = nil;
}

- (UILabel *)titleLabel {
    return (UILabel *) [self viewWithTag:TITLE_TAG];
}

- (UILabel *)customerLabel {
    return (UILabel *) [self viewWithTag:CUSTOMER_TAG];
}

- (UILabel *)distanceLabel {
    return (UILabel *) [self viewWithTag:DISTANCE_TAG];
}

- (UILabel *)countLabel {
    return (UILabel *) [self viewWithTag:COUNT_TAG];
}

- (UILabel *)dateLabel {
    return (UILabel *) [self viewWithTag:DATE_TAG];
}

- (UIImageView *)iconView {
    return (UIImageView *) [self viewWithTag:ICON_TAG];
}

- (UIImageView *)bookmarksImageView {
    return (UIImageView *) [self viewWithTag:BOOKMARKS_TAG];
}

- (UIImageView *)disclosureImageView {
    return (UIImageView *) [self viewWithTag:DISCLOSURE_TAG];
}

- (void)applyColors {
    COUPIESOffer *theOffer = self.coupon;
    
    UIColor *theColor = [UIColor colorWithRed:0x9F / 255.0 green:0xAF / 255.0 blue:0xC3 / 255.0 alpha:1.0];
    UILabel *theCountLabel = [self countLabel];
    
    if ([theOffer isMemberOfClass:[COUPIESCoupon class]]) {
        COUPIESCoupon *theCoupon = (COUPIESCoupon*)theOffer;
        
        int theCount = theCoupon.remaining;
        
        if(!theCoupon.isUnlimited) {
            if(theCount == 2) {
                theColor = [UIColor colorWithRed:0xFF / 255.0 green:0x8F / 255.0 blue:0x00 / 255.0 alpha:1.0];
            }
            else if(theCount == 1) {
                theColor = [UIColor colorWithRed:0xFF / 255.0 green:0x41 / 255.0 blue:0x00 / 255.0 alpha:1.0];
            }
            theCountLabel.hidden = theCount <= 0;
        }
        else {
            theCountLabel.hidden = NO;
        }
    }

    [theCountLabel setTextColor:theColor];
}

- (void)applyRemaining {
	[[self countLabel] setText:self.remainingText];
	[self applyColors];
}

- (void)setCoupon:(COUPIESOffer *)inCoupon {
    if(inCoupon != coupon) {
        NSDateFormatter *theFormatter = [[NSDateFormatter alloc] init];

        [theFormatter setDateFormat:@"d.M."];
        coupon = [inCoupon copy];
        self.title = inCoupon.title;
        self.customerName = inCoupon.customer.name;
		[self.iconView setImage:[UIImage imageNamed:@"default_coupontypeimage.png"]];
        [self.iconView setImageWithURL:inCoupon.imageURL];
        [self setDistance:inCoupon.distance];
        self.isBookmarked = inCoupon.isBookmarked;
        if(inCoupon.expires == nil) {
            [[self dateLabel] setText:@""];
        }
        else {
            [[self dateLabel] setText:[NSString stringWithFormat:NSLocalizedString(@"bis %@", @""), 
                                       [theFormatter stringFromDate:inCoupon.expires]]];
        }
		[self applyRemaining];
    }
}

- (NSString *)title { 
    return [[self titleLabel] text]; 
}

- (void)setTitle:(NSString *)inTitle {
    [[self titleLabel] setText:inTitle];
}

- (NSString *)customerName { 
    return [[self customerLabel] text]; 
}

- (void)setCustomerName:(NSString *)inText {
    [[self customerLabel] setText:inText];
}

- (void)setDistance:(float)inDistance {
    [[self distanceLabel] setText:[NSString stringWithFormat:@"%.0fm", inDistance]];
}

- (BOOL)isBookmarked {
    return ![[self bookmarksImageView] isHidden];
}

- (void)setIsBookmarked:(BOOL)inIsBookmarked {
    [[self bookmarksImageView] setHidden:!inIsBookmarked];
}

- (NSString *)remainingText {
    COUPIESOffer *theOffer = self.coupon;
    
    if ([theOffer isMemberOfClass:[COUPIESCoupon class]]) {
        COUPIESCoupon *theCoupon = (COUPIESCoupon*)theOffer;
        
        if([theCoupon isUnlimited]) {
            return NSLocalizedString(@"Unbegrenzt verfügbar", @"Availability and expiration for an unlimited coupon");
        }
        else if(theCoupon.remaining == 1) {
            return NSLocalizedString(@"1 Coupon übrig", @"Availability and expiration with 1 left");
        }
        else if(theCoupon.remaining > 1) {
            return [NSString stringWithFormat:NSLocalizedString(@"%d Coupons übrig", @"Availability and expiration with x left"), theCoupon.remaining];
        }
        else {
            return NSLocalizedString(@"Nicht mehr verfügbar", @"An unavailable coupon");
        }
    }
    else {
        return nil;
    }
}

@end
