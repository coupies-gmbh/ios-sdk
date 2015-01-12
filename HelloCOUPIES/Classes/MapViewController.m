    //
//  MapViewController.m
//  HelloCOUPIES
//
//  Created by Clemens Wagner on 29.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "MapViewController.h"
#import "LocationAnnotationView.h"
#import <CoreLocation/CoreLocation.h>
#import <COUPIES/COUPIES.h>

#define IDENTIFIER @"location"

@interface MapViewController()<COUPIESRestServiceDelegate>

- (void)reset;

@end

@implementation MapViewController

@synthesize coupiesManager;
@synthesize restService;

- (void)dealloc {
    [self reset];
}

- (void)reset {
    self.coupiesManager = nil;
    self.restService = nil;
    mapView = nil;
    activityIndicatorView = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    CLLocationManager *theManager = self.coupiesManager.locationManager;
	MKCoordinateRegion theRegion = MKCoordinateRegionMake(theManager.location.coordinate, MKCoordinateSpanMake(0.01, 0.01));

    self.restService = [self.coupiesManager newRestService];
    self.restService.delegate = self;
	theRegion = [mapView regionThatFits:theRegion];
	[mapView setRegion:theRegion animated:YES];
}

- (void)viewDidUnload {
    [super viewDidUnload];
    [self reset];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return YES;
}

- (void)viewWillAppear:(BOOL)inAnimated {
    [super viewWillAppear:inAnimated];

    [self.restService listLocations];
    [activityIndicatorView startAnimating];
}

#pragma mark MKMapViewDelegate methods

- (MKAnnotationView *)mapView:(MKMapView *)inMapView viewForAnnotation:(id<MKAnnotation>) inAnnotation {
	if(inAnnotation == inMapView.userLocation) {
        return nil;
    }
    else {
		LocationAnnotationView *theView = (LocationAnnotationView *)[mapView dequeueReusableAnnotationViewWithIdentifier:IDENTIFIER];
		
		if (theView == nil) {
            theView = [[LocationAnnotationView alloc] initWithAnnotation:inAnnotation reuseIdentifier:IDENTIFIER];
		}
        [theView configureForAnnotation:(id)inAnnotation];
		return theView;
	}
}

- (void)mapView:(MKMapView *)inMapView annotationView:(MKAnnotationView *)inView calloutAccessoryControlTapped:(UIControl *)inControl {
    //COUPIESLocation *theLocation = (COUPIESLocation *) [inView annotation];
}

#pragma mark COUPIESRestServiceDelegate

- (void)restService:(COUPIESRestService *)inService receivedResult:(NSArray *)inResult {
    [activityIndicatorView stopAnimating];
    [mapView removeAnnotations:mapView.annotations];
    [mapView addAnnotations:inResult];
	[mapView setShowsUserLocation:YES];
}

- (void)restService:(COUPIESRestService *)inService receivedErrors:(NSArray *)inErrors {
    COUPIESError *theError = [inErrors lastObject];
    UIAlertView *theAlert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Fehler", @"") 
                                                       message:theError.message 
                                                      delegate:nil 
                                             cancelButtonTitle:@"OK" 
                                             otherButtonTitles:nil];
    
    [activityIndicatorView stopAnimating];
    [theAlert show];
}

- (void)restServiceHasBadCredentials:(COUPIESRestService *)inService {
    UIAlertView *theAlert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Fehler", @"") 
                                                       message:NSLocalizedString(@"Die Zugangsdaten sind nicht gültig.", @"") 
                                                      delegate:nil 
                                             cancelButtonTitle:@"OK" 
                                             otherButtonTitles:nil];
    
    [activityIndicatorView stopAnimating];
    [theAlert show];
}

@end
