//
//  NSDateFormatter+COUPIESExtension.h
//  
//
//  Created by Clemens Wagner on 03.02.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSDateFormatter(COUPIESExtension)

+ (id)dateFormatterWithLocale:(NSLocale *)inLocale dateStyle:(NSDateFormatterStyle)inDateStyle timeStyle:(NSDateFormatterStyle)inTimeStyle;

@end
