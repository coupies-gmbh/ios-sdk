//
//  SAXParserBase.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 15.07.09.
//  Copyright 2009 COUPIES GmbH. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESSAXParserDelegate : NSObject<COUPIESSAXParseable> {
    @private
    NSDictionary *tagsDictionary;
    NSMutableString *characters;
    NSMutableArray *stack;
    NSMutableArray *elements;
    NSMutableArray *errors;
}

@property(strong, readonly) NSDictionary *tagsDictionary;
@property(nonatomic, strong, readonly) NSString *characters;
@property(unsafe_unretained, readonly) NSString *trimmedCharacters;
@property(readonly) BOOL boolValue;
@property(unsafe_unretained, readonly) NSDate *dateValue;
@property(unsafe_unretained, readonly) NSDate *timestampValue;
@property(unsafe_unretained, readonly) NSNumber *integerValue;
@property(unsafe_unretained, readonly) NSNumber *floatValue;
@property(unsafe_unretained, readonly) NSNumber *doubleValue;
@property(unsafe_unretained, readonly) NSURL *url;

+ (id)parserDelegateWithParseables:(id)inParseable, ... NS_REQUIRES_NIL_TERMINATION;
- (id)initWithTagsDictionary:(NSDictionary *)inTagsDictionary;
- (id)initWithParseables:(id)inParseable, ... NS_REQUIRES_NIL_TERMINATION;
- (void)push:(id<COUPIESSAXParseable>)inParseable;
- (id<COUPIESSAXParseable>)pop;
- (id<COUPIESSAXParseable>)peek;
- (NSArray *)parseData:(NSData *)inData withErrors:(NSArray **)outErrors;

@end