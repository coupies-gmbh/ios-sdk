//
//  UIButton+WebCache.h
//  COUPIES
//
//  Created by Clemens Wagner on 28.08.10.
//  Copyright 2010 COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDWebImageManagerDelegate.h"

@interface UIButton(WebCache)<SDWebImageManagerDelegate>

- (void)setImageWithURL:(NSURL *)inURL;
- (void)setImageWithURL:(NSURL *)inURL placeholderImage:(UIImage *)inPlaceholder;

@end
