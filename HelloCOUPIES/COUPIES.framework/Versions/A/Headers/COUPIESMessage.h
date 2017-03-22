//
//  News.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 03.11.09.
//  Copyright 2009 COUPIES. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESMessage : COUPIESSAXParseable {
    @private
    NSDate *creationTime;
	NSString *message;
}

@property (nonatomic, strong) NSDate *creationTime;
@property (nonatomic, strong) NSString *message;

+ (id)message;

@end
