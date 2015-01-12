//
//  COUPIESRequestFactory+PrivateAPI.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRequestFactory.h"

@interface COUPIESRequestFactory(PrivateAPI)

@property (retain, readwrite) NSString *type;
@property (nonatomic, readonly) NSDictionary *credentials;
@property (nonatomic, readonly) NSString *restServer;
@property (nonatomic, readonly) NSTimeInterval timeout;

- (NSURL *)addCredentials:(NSURL *)inURL;
- (NSMutableDictionary *)headerWithContentType:(NSString *)inContentType;

@end
