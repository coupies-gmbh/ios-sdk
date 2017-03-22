//
//  Error.h
//  COUPIES GmbH
//
//  Created by Clemens Wagner on 28.06.10.
//  Copyright 2010 COUPIES. All rights reserved.
//

#import "COUPIESSAXParseable.h"

@interface COUPIESError : COUPIESSAXParseable {
    @private
    NSString *code;
    NSString *field;
    NSString *message;
}

@property (copy) NSString *code;
@property (copy) NSString *field;
@property (copy) NSString *message;

+ (id)error;

@end
