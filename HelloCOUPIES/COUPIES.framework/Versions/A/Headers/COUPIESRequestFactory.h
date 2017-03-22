//
//  COUPIESRequestFactory.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

extern NSString * const kCOUPIESRequestFactoryTypeHTML;
extern NSString * const kCOUPIESRequestFactoryTypeXML;

@class COUPIESOffer;
@class COUPIESManager;
@class COUPIESRedemption;
@class COUPIESCustomer;

@interface COUPIESRequestFactory : NSObject {
    @private
    id __unsafe_unretained delegate;
    NSString *mimeType;
}

@property (strong, readonly) NSString *type;
@property (nonatomic, unsafe_unretained) id delegate;
@property (nonatomic, copy) NSString *mimeType;
@property (unsafe_unretained, nonatomic, readonly) CLLocation *location;
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

- (id)requestForPath:(NSString *)inPath withParameters:(NSDictionary *)inParameters method:(NSString *)inMethod contentType:(NSString *)inContentType;
- (id)requestForPath:(NSString *)inPath withParameters:(NSDictionary *)inParameters method:(NSString *)inMethod;
- (id)secureRequestForPath:(NSString *)inPath withParameters:(NSDictionary *)inParameters method:(NSString *)inMethod contentType:(NSString *)inContentType;
- (id)requestForURL:(NSURL *)inURL withParameters:(NSDictionary *)inParameters method:(NSString *)inMethod contentType:(NSString *)inContentType;
- (id)requestForURL:(NSURL *)inURL withParameters:(NSDictionary *)inParameters method:(NSString *)inMethod;

@end

@protocol COUPIESRequestFactoryDelegate<NSObject>

@required
- (NSString *)restServerForRequestFactory:(COUPIESRequestFactory *)inFactory;
- (NSDictionary *)credentialsForRequestFactory:(COUPIESRequestFactory *)inFactory;
- (CLLocation *)locationForRequestFactory:(COUPIESRequestFactory *)inFactory;

@optional
- (NSTimeInterval)timeoutForRequestFactory:(COUPIESRequestFactory *)inFactory;

@end

typedef enum {
    kCOUPIESBarcodeScaleSmall = 1,
    kCOUPIESBarcodeScaleMedium = 2,
    kCOUPIESBarcodeScaleLarge = 3
} COUPIESBarcodeScale;

@interface COUPIESRequestFactory(Coupons)

- (NSURL *)barcodeImageURLForRedemption:(COUPIESRedemption *)inRedemption withScale:(COUPIESBarcodeScale)inScale;
                                                                                     
- (id)requestForCouponsWithRadius:(float)inRadius limit:(NSUInteger)inLimit;
- (id)requestForCouponsWithCoordinate:(CLLocationCoordinate2D)inCoordinate radius:(float)inRadius limit:(NSUInteger)inLimit;
- (id)requestForHighlightedCouponsWithLimit:(NSUInteger)inLimit;
- (id)requestForListFeedCoupons;
- (id)requestForListOnlineCoupons;
- (id)requestForListCashbackCoupons;
- (id)requestForListWithInterests;
- (id)requestForListWithInterestsWithRadius:(NSUInteger)inRadius andLimit:(NSUInteger)inLimit;
- (id)requestForCouponsWithQuery:(NSString *)inQuery;
- (id)requestForCouponsWithCustomer:(COUPIESCustomer *)inCustomer;
- (id)requestForCouponWithId:(NSUInteger)couponId;
- (id)requestForPassWithId:(NSUInteger)passId;
- (id)requestForRedeemingCoupon:(COUPIESOffer *)inCoupon;
- (id)requestForRedeemingCoupon:(COUPIESOffer *)inCoupon withStickercode:(NSString *)inCode;
- (id)requestForRedeemingCoupon:(COUPIESOffer *)inCoupon withReceipt:(NSArray *)inImages quantity:(int)inQuantity;

@end