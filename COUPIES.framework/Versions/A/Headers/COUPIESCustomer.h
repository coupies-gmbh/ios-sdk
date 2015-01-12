//
//  Customer.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 05.06.09.
//  
//  Datenklasse zur Abbildung eines Kunden

#import "COUPIESSAXParseable.h"

@class COUPIESLocation;

@interface COUPIESCustomer : COUPIESSAXParseable {
    @private
	int customerId;
	NSString *name;
    NSString *description;
	NSURL *imageURL;
	NSArray *locations;
}

@property int customerId;
@property (copy) NSString *name;
@property (copy) NSString *description;
@property (strong) NSURL *imageURL;
@property (copy, readwrite) NSArray *locations;
@property (strong, readonly) COUPIESLocation *nearestLocation;

+ (id)customer;

@end
