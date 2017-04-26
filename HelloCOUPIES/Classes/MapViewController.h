//
//  MapViewController.h
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@class COUPIESManager;
@class COUPIESRestService;

@interface MapViewController : UIViewController<MKMapViewDelegate> {
    @private
    COUPIESManager *__weak coupiesManager;
    COUPIESRestService *restService;
	IBOutlet MKMapView *mapView;
    IBOutlet UIActivityIndicatorView *activityIndicatorView;
}

@property (nonatomic, weak) IBOutlet COUPIESManager *coupiesManager;
@property (nonatomic, strong) COUPIESRestService *restService;

@end
