//
//  COUPIESRequestFactory+LocationsAndCategories.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@class COUPIESCategory;
@class COUPIESOffer;
@class COUPIESLocation;

@interface COUPIESRequestFactory(LocationsAndCategories)

- (id)requestForCouponsWithCategory:(COUPIESCategory *)inCategory radius:(float)inRadius;
- (id)requestForCouponsWithLocation:(COUPIESLocation *)inLocation;

- (id)requestForLocations;
- (id)requestForLocationsWithCoordinate:(CLLocationCoordinate2D)inCenter;
- (id)requestForLocationsWithCoordinate:(CLLocationCoordinate2D)inNorthEast coordinate:(CLLocationCoordinate2D)inSouthWest;
- (id)requestForClosestLocationWithCoupon:(COUPIESOffer *)inCoupon;
- (id)requestForLocationsWithCoupon:(COUPIESOffer *)inCoupon;
- (id)requestForLocationsWithCoupon:(COUPIESOffer *)inCoupon withSearchQuery:(NSString *)inQuery;
- (id)requestForCategoriesWithRadius:(float)inRadius;
- (id)requestForMarkCoupon:(COUPIESOffer *)inCoupon unavailableForLocation:(COUPIESLocation *)inLocation;

@end
