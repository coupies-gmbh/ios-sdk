//
//  NSDictionary+COUPIESExtension.h
//  
//
//  Created by Clemens Wagner on 20.11.09.
//  Copyright 2009 COUPIES. All rights reserved.
//

#import "NSString+COUPIESExtension.h"
#import <CoreGraphics/CGGeometry.h>

@interface NSDictionary(COUPIESExtension)

+(id)dictionaryWithHeadOfURL:(NSURL *)inURL;
+(id)dictionaryWithArray:(NSArray *)inObjects keyFromKeyPath:(NSString *)inPath;
-(NSDate *)dateForKey:(id)inKey withDateFormatString:(NSString *)inFormat;
-(CGPoint)pointForKey:(id)inKey;
-(double)doubleForKey:(id)inKey;
-(id)objectForKey:(id)aKey withDefault:(id)inDefault;

@end
