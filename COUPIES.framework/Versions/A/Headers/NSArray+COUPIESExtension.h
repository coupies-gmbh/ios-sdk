//
//  NSArray+COUPIESExtension.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 23.06.10.
//  Copyright 2010 COUPIES. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray(COUPIESExtension)

- (id)minimalObjectUsingSelector:(SEL)inComparisonSelector;
- (NSString *)componentsWithKeyPath:(NSString *)inKeyPath joinedByString:(NSString *)inSeparator;
- (id)objectEqualToObject:(id)inObject;

@end