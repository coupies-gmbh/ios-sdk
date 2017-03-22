//
//  Coupon.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 14.05.09.
//  
//  Datenklasse zur Abbildung eines Coupons (im Backend Coupontype)

#import "COUPIESOffer.h"


@class COUPIESRedemption;
@class UIWebView;

@interface COUPIESCoupon : COUPIESOffer {
    int remaining;
	int remainingInterval;
	int remainingTotal;
    BOOL closestLocationAcceptsSticker;
	BOOL isUnlimited;
    COUPIESRedemption *redemption;
}

@property int remaining;
@property int remainingInterval;
@property int remainingTotal;
@property BOOL closestLocationAcceptsSticker;
@property BOOL isUnlimited;
@property (strong) COUPIESRedemption *redemption;

+ (id)coupon;

//Parses a coupon from the HTML representation of the coupon-details
//page of the COUPIES-API in a UIWebView. This site contain tags with certain
//information that is parsed by this function.
+ (COUPIESCoupon *)couponFromHtml:(UIWebView *)inWebView;
- (int)decreaseRemaining;
- (BOOL)hasRemaining;

@end