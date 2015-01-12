//
//  SAXParseble.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 23.06.10.
//  Copyright 2010 COUPIES. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol COUPIESSAXParseable<NSObject>

- (NSString *)tagName;
- (void)parser:(NSXMLParser *)inParser applyAttributes:(NSDictionary *)inAttributes;
- (void)parser:(NSXMLParser *)inParser didStartElementNamed:(NSString *)inElementName withAttributes:(NSDictionary *)inAttributes;
- (void)parser:(NSXMLParser *)inParser didEndElementNamed:(NSString *)inElementName;

@end


@interface COUPIESSAXParseable : NSObject<COUPIESSAXParseable> {
    @private
}

@end
