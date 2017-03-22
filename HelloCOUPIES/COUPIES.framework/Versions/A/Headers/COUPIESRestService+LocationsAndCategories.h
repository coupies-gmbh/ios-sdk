//
//  COUPIESRestService+LocationsAndCategories.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRestService.h"

@class COUPIESCategory;
@class COUPIESOffer;
@class COUPIESLocation;

@interface COUPIESRestService(LocationsAndCategories)

- (void)listCouponsWithCategory:(COUPIESCategory *)inCategory radius:(float)inRadius;
- (void)listCouponsWithLocation:(COUPIESLocation *)inLocation;

- (void)listLocations;
- (void)listLocationsWithCoordinate:(CLLocationCoordinate2D)inCenter;
- (void)listLocationsWithCoordinate:(CLLocationCoordinate2D)inNorthEast coordinate:(CLLocationCoordinate2D)inSouthWest;
- (void)listClosestLocationWithCoupon:(COUPIESOffer *)inCoupon;
- (void)listLocationsWithCoupon:(COUPIESOffer *)inCoupon;
- (void)listLocationsWithCoupon:(COUPIESOffer *)inCoupon withSearchQuery:(NSString *)inQuery;
- (void)listCategoriesWithRadius:(float)inRadius;
- (void)markCoupon:(COUPIESOffer *)inCoupon unavailableForLocation:(COUPIESLocation *)inLocation;

@end
