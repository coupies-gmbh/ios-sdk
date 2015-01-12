//
//  MapViewController.h
//  HelloCOUPIES
//
//  Created by Clemens Wagner on 29.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
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
