//
//  LocationAnnotationView.m
//  COUPIES GmbH
//
//  Created by Felix Schul on 06.07.09.
//  
//  Implementierung der eigenen AnnotationView

#import "LocationAnnotationView.h"
#import "UIImageView+WebCache.h"
#import <COUPIES/COUPIES.h>

@implementation LocationAnnotationView

- (id)initWithAnnotation:(id)inAnnotation reuseIdentifier:(NSString *)inReuseIdentifier {
	if (self = [super initWithAnnotation:inAnnotation reuseIdentifier:inReuseIdentifier]) {
		UIButton *theDetailButton = [UIButton buttonWithType:UIButtonTypeDetailDisclosure];

		[self setEnabled:YES];
		[self setCanShowCallout:YES];
		[self setMultipleTouchEnabled:NO];
		[self setCenterOffset:CGPointMake(0, -22.5)];
		[self setRightCalloutAccessoryView:theDetailButton];

		imageView = [[UIImageView alloc] initWithFrame:CGRectMake(5, 2, 38, 39)];
		imageView.contentMode = UIViewContentModeScaleAspectFit;
		[self addSubview:imageView];
	}
	return self;
}

- (void)configureForAnnotation:(COUPIESLocation *)inAnnotation {
	[imageView setImageWithURL:inAnnotation.customer.imageURL];
}
	

@end
