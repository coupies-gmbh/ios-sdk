//
//  LocationAnnotationView.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 06.07.09.
//  
//  Eigene Klasse für die AnnotationView (Aussehen der Filialen auf der Karte).
//  Hier wird zuerst ein Standard-Icon angezeigt und dann das richtige Logo asynchron nachgeladen.
//  Wenn dieses geladen ist wird das Standard-Icon ersetzt.


#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class COUPIESLocation;

@interface LocationAnnotationView : MKAnnotationView {
    @private
	UIImageView *imageView;
}

- (void)configureForAnnotation:(COUPIESLocation *)inAnnotation;

@end
