//
//  COUPIESDisplay.h
//  COUPIES
//
//  Created by Felix Schul on 19.10.11.
//  Copyright (c) 2011 COUPIES GmbH. All rights reserved.
//  Datenklasse zur Abbildung eines Display-Werbe-Elementes
//

#import "COUPIESSAXParseable.h"

@interface COUPIESDisplay : COUPIESSAXParseable {
    @private
	NSString  *type;
	NSURL     *image_url;
	NSURL     *target_url;
    int       duration;
	NSURL     *trackingUrlView;
	NSURL     *trackingUrlClick;
}

@property (strong) NSString *type;
@property (strong) NSURL *image_url;
@property (strong) NSURL *target_url;
@property int duration;
@property (strong) NSURL *trackingUrlView;
@property (strong) NSURL *trackingUrlClick;

+ (id)display;

@end