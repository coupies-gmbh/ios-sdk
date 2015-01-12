//
//  Location.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 13.05.09.
// 
//  Datenklasse zur Abbildung einer Filiale

#import "COUPIESSAXParseable.h"
#import "COUPIESCustomer.h"
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

typedef enum {
    kProductAvailabileNo = 0,
    kProductAvailabileYes = 1,
    kProductAvailabilePossible = 2
} COUPIESLocationProductAvailable;

@interface COUPIESLocation : COUPIESSAXParseable <MKAnnotation> {
    @private
	int locationId;
	COUPIESCustomer *customer;
	int couponCount;
    COUPIESLocationProductAvailable productAvailable;
    BOOL acceptsSticker;
	double distance;
	NSString *title;
	NSString *subtitle; //Für die MapViewAnnotation (wird dort in der Bubble angezeigt)
	NSString *address;
    NSURL *website;
    NSString *phone;
	CLLocationCoordinate2D coordinate;
}

@property int locationId;
@property (strong) COUPIESCustomer *customer;
@property int couponCount;
@property COUPIESLocationProductAvailable productAvailable;
@property BOOL acceptsSticker;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (unsafe_unretained, nonatomic, readonly) NSString *distanceString;
@property (copy) NSString *address;
@property (copy) NSString *phone;
@property (strong) NSURL *website;
@property double distance;
@property CLLocationDegrees latitude;
@property CLLocationDegrees longitude;
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

+ (id)location;

@end
