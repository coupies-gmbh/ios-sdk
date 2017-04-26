//
//  RestService.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 24.06.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class COUPIESManager;
@class COUPIESRequestFactory;
@class COUPIESRestWrapper;
@class COUPIESSAXParserDelegate;
@class COUPIESCoupon;
@class COUPIESCategory;
@class COUPIESLocation;
@class COUPIESCustomer;

@class COUPIESSAXParseable;

@interface COUPIESRestService : NSObject {
    @private
    COUPIESManager *manager;
    COUPIESRestWrapper *restWrapper;
    COUPIESSAXParserDelegate *parserDelegate;
    NSString *notificationName;
    id __unsafe_unretained delegate;
}

@property (nonatomic, strong, readonly) COUPIESManager *manager;
@property (nonatomic, unsafe_unretained, readwrite) id delegate;
@property(unsafe_unretained, nonatomic, readonly) COUPIESRequestFactory *requestFactory;
@property(readonly, copy) NSString *notificationName;

+ (NSString *)notificationNameForClass:(Class)inParseableClass;
- (void)sendRequest:(NSURLRequest *)inRequest withParseable:(COUPIESSAXParseable *)inParseable;
- (void)sendRequest:(NSURLRequest *)inRequest withParseables:(COUPIESSAXParseable *)inParseable, ... NS_REQUIRES_NIL_TERMINATION;

@end

@protocol COUPIESRestServiceDelegate

@optional
- (void)restService:(COUPIESRestService *)inService receivedResult:(NSArray *)inResult;
- (void)restService:(COUPIESRestService *)inService receivedErrors:(NSArray *)inErrors;
- (void)restService:(COUPIESRestService *)inService didSendBodyData:(NSDictionary *)inInfo;
- (void)restServiceHasBadCredentials:(COUPIESRestService *)inService;

@end

@interface COUPIESRestService(Coupons)

- (void)showCouponWithId:(NSUInteger)inCouponId;
- (void)listCouponsWithRadius:(float)inRadius limit:(NSUInteger)inLimit;
- (void)listCouponsWithCoordinate:(CLLocationCoordinate2D)inCoordinate radius:(float)inRadius limit:(NSUInteger)inLimit;
- (void)listHighlightedCouponsWithLimit:(NSUInteger)inLimit;
- (void)listFeedCoupons;
- (void)listOnlineCoupons;
- (void)listCashbackCoupons;
- (void)listCouponsWithQuery:(NSString *)inQuery;
- (void)listCouponsWithCustomer:(COUPIESCustomer *)inCustomer;
- (void)listCouponsWithInterests;
- (void)listCouponsWithInterestsWithRadius:(NSUInteger)inRadius andLimit:(NSUInteger)inLimit;
- (void)listCouponsWithInterestsWithRadius:(NSUInteger)inRadius andLimit:(NSUInteger)inLimit andType:(NSString *)inType;
- (void)redeemCoupon:(COUPIESCoupon *)inCoupon;
- (void)redeemCoupon:(COUPIESCoupon *)inCoupon withStickercode:(NSString *)inCode;
- (void)redeemCoupon:(COUPIESCoupon *)inCoupon withReceipt:(NSData *)inImage;
- (void)redeemCoupon:(COUPIESCoupon *)inCoupon withReceipt:(NSArray *)inImages quantity:(int)inQuantity;
- (void)listShoppingList;
- (void)sendShoppingList:(NSMutableArray *)list;

@end
