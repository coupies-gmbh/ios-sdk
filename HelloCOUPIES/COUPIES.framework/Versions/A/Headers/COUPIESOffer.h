//
//  COUPIESOffer.h
//  COUPIES
//
//  Created by Pedro Ribeiro on 21.12.12.
//  Copyright (c) 2012 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"
#import "COUPIESCustomer.h"
#import "COUPIESCategory.h"
#import <UIKit/UIKit.h>

typedef enum {
    kActionNoAction = 1,
    kActionRedeemInShop = 2,
    kActionShowUrl = 3,
    kActionCashback = 4
} COUPIESOfferAction;

@class COUPIESRedemption;

@interface COUPIESOffer : COUPIESSAXParseable <UIActivityItemSource> {
@private
	int	couponId;
    NSDate *createdAt;
    NSDate *updatedAt;
	COUPIESCustomer *customer;
	NSString *title;
	NSString *text;
    NSURL *frontendURL;
	NSURL *imageURL;
    NSMutableArray *infoImagesURLs;
    NSString *youtubeVideoId;
    NSURL *imageFeaturedURL;
	double distance;
    double faceValue;
    NSString *currency;
    BOOL isUnread;
    NSDate *starts;
	NSDate *expires;
	BOOL isBookmarked;
    int priority;
    int affiliateId;
    NSString *affiliateName;
    NSString *affiliateDescription;
    NSURL *affiliateIconURL;
    NSURL *affiliateWebsiteUrl;
    COUPIESCategory *category;
    BOOL isLiked;
    int likes;
	int passId;
    COUPIESOfferAction action;
    NSURL *targetUrl;
    NSString *locationButtonText;
    NSString *onlineButtonText;
}

@property int couponId;
@property (copy) NSDate *createdAt;
@property (copy) NSDate *updatedAt;
@property (strong) COUPIESCustomer *customer;
@property (copy) NSString *title;
@property (copy) NSString *text;
@property (strong) NSURL *frontendURL;
@property (strong) NSURL *imageURL;
@property (copy) NSArray *infoImagesURLs;
@property (strong) NSURL *imageFeaturedURL;
@property (copy) NSString *youtubeVideoId;
@property double distance;
@property double faceValue;
@property (copy) NSString *currency;
@property (readonly) BOOL isNew;
@property (readonly) BOOL expiresSoon;
@property (copy) NSDate *starts;
@property (copy) NSDate *expires;
@property BOOL isBookmarked;
@property BOOL isUnread;
@property int priority;
@property int affiliateId;
@property (copy) NSString *affiliateName;
@property (copy) NSString *affiliateDescription;
@property (copy) NSURL *affiliateWebsiteUrl;
@property (strong) NSURL *affiliateIconURL;
@property (strong) COUPIESCategory *category;
@property BOOL isLiked;
@property int likes;
@property int passId;
@property COUPIESOfferAction action;
@property (strong) NSURL *targetUrl;
@property (strong) NSString *locationButtonText;
@property (strong) NSString *onlineButtonText;

+ (id)offer;
- (id)copyWithZone:(NSZone *)inZone;
- (BOOL)isPassbookEnabled;

@end