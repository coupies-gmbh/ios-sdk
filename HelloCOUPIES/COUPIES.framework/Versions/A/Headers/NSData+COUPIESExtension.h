//
//  NSData+COUPIESExtension.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 17.02.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSData(COUPIESExtension)

+ (id)dataWithContentsOfURL:(NSURL *)inURL method:(NSString *)inMethod data:(NSData *)inData error:(NSError **)outError;
+ (id)dataWithParameters:(NSDictionary *)inParameters encoding:(NSStringEncoding)inEncoding;
+ (id)dataWithParameters:(NSDictionary *)inParameters encoding:(NSStringEncoding)inEncoding boundary:(NSString *)inBoundary;

- (NSString *)hexadecimalString;

@end
