#import "COUPIESSAXParseable.h"

typedef enum {
    kRedemptionStatusInvalid = 0,
    kRedemptionStatusValid = 1,
    kRedemptionStatusPending = 2
} COUPIESRedemptionStatus;

extern NSString * const kCOUPIESCouponCodeTypeEAN13;
extern NSString * const kCOUPIESCouponCodeTypeEAN128;
extern NSString * const kCOUPIESCouponCodeTypeCoupiesCode;

//Arten von Coupontypen (entsprechen den Strings in den XML-Dateien des Webservice)
#define COUPONCODE_EAN13 @"ean13"
#define COUPONCODE_EAN128 @"ean128"
#define COUPONCODE_COUPIESCODE @"coupiescode"


@class COUPIESCoupon;
@class COUPIESLocation;
@class COUPIESReceipt;

@interface COUPIESRedemption : COUPIESSAXParseable {
    @private
    int       redemptionId;
	int		  allocationId;
    int		  userId;
    COUPIESRedemptionStatus       status;
    int       rejectionReasonId;
    NSString  *rejectionReasonTitle;
    NSString  *rejectionReasonComment;
    double    cashbackValue;
    int       quantity;
	NSDate    *redemptionTime;
    COUPIESCoupon *coupon;
    COUPIESLocation *location;
    COUPIESReceipt *receipt;
	NSString  *couponCodeType;
	NSString  *couponCodeText;
	NSURL     *barcodeImageURL;
    BOOL      reuploadable;
}

@property int redemptionId;
@property int allocationId;
@property int userId;
@property COUPIESRedemptionStatus status;
@property int rejectionReasonId;
@property (copy) NSString *rejectionReasonTitle;
@property (copy) NSString *rejectionReasonComment;
@property double cashbackValue;
@property int quantity;
@property (strong) NSDate *redemptionTime;
@property (strong) COUPIESCoupon *coupon;
@property (strong) COUPIESLocation *location;
@property (strong) COUPIESReceipt *receipt;
@property (readonly) int couponId;
@property (readonly) int locationId;
@property (copy) NSString *couponCodeType;
@property (copy) NSString *couponCodeText;
@property (strong) NSURL *barcodeImageURL;
@property BOOL reuploadable;

+ (id)redemption;
+ (NSArray *)applyRedemptions:(NSArray *)inRedemptions toCoupons:(NSArray *)inCoupons;

@end
