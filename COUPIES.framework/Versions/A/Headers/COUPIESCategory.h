//
//  Interest.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 18.05.09.
//  
//  Datenklasse zur Abbildung einer Interessenskategorie

#import "COUPIESSAXParseable.h"

@interface COUPIESCategory : COUPIESSAXParseable {
    @private
	int       categoryId;
	int       couponCount;
	NSString  *title;
	NSString  *text;
}

@property int categoryId;
@property int couponCount;
@property (copy) NSString *title;
@property (copy) NSString *text;

+ (id)category;

@end