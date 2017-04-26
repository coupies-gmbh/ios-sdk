//
//  COUPIESRestService+PrivateAPI.h
//  COUPIES
//
//  Created by Clemens Wagner on 27.10.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import "COUPIESRestService.h"
#import "COUPIESRestWrapper.h"

@interface COUPIESRestService(PrivateAPI)<COUPIESRestWrapperDelegate>

@property (retain, readwrite) COUPIESManager *manager;
@property(readwrite, copy) NSString *notificationName;
@property(retain) COUPIESRestWrapper *restWrapper;
@property(retain) COUPIESSAXParserDelegate *parserDelegate;

@end
