//
//  UIButton+WebCache.h
//  COUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDWebImageManagerDelegate.h"

@interface UIButton(WebCache)<SDWebImageManagerDelegate>

- (void)setImageWithURL:(NSURL *)inURL;
- (void)setImageWithURL:(NSURL *)inURL placeholderImage:(UIImage *)inPlaceholder;

@end
