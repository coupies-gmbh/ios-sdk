//
//  NSString+COUPIESExtension.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 15.01.10.
//  Copyright 2010 COUPIES. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kISODateFormat;
extern NSString * const kISOTimestampFormat;
extern NSString * const kRFC1123TimestampFormat;
extern NSString * const kRFC1123NumericTimeZoneTimestampFormat;

@interface NSString(COUPIESExtension)

+ (id)stringFromDate:(NSDate *)inDate withFormatString:(NSString *)inFormatString;
+ (id)stringFromDate:(NSDate *)inDate withFormatString:(NSString *)inFormatString locale:(NSLocale *)inLocale;
+ (id)stringWithPrice:(float)inPrice withCurrency:(NSString *)inCurrency;
+ (id)stringWithPriceCompact:(float)inPrice withCurrency:(NSString *)inCurrency;
+ (id)stringWithTemplate:(NSString *)inResourceName extension:(NSString *)inExtension;
+ (id)stringWithParameters:(NSDictionary *)inParameters;
+ (id)stringWithParameters:(NSDictionary *)inParameters boundary:(NSString *)inBoundary;
+ (id)stringWithDistance:(float)inDistance;
+ (id)stringWithData:(NSData *)inData encoding:(NSStringEncoding)inEncoding;
+ (id)stringWithCoordinate:(double)inCoordinate;
+ (id)stringWithTimeInterval:(NSTimeInterval)inInterval;
+ (id)stringWithNumber:(NSNumber*)inNumber;
- (NSDate *)dateWithFormatString:(NSString *)inFormatString locale:(NSLocale *)inLocale;
- (NSDate *)dateWithFormatString:(NSString *)inFormatString;
- (NSString *)trim;
- (NSString *)trimToNil;
- (NSString *)encodedParameterValue;
- (NSString *)cut:(NSUInteger)inLength;
- (BOOL)isValidStringForMinLength:(int)inMin maxLength:(int)inMax;
- (BOOL)isValidEmail;
- (BOOL)isNumericOnly;

@end
