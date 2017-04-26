//
//  UIButton+WebCache.m
//  COUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import "UIButton+WebCache.h"
#import "SDWebImageManager.h"

@implementation UIButton(WebCache)

- (void)setImageWithURL:(NSURL *)inURL {
    [self setImageWithURL:inURL placeholderImage:nil];
}

- (void)setImageWithURL:(NSURL *)inURL placeholderImage:(UIImage *)inPlaceholder {
    SDWebImageManager *theManager = [SDWebImageManager sharedManager];
    UIImage *theImage;
    
    [theManager cancelForDelegate:self];
    theImage = [theManager imageWithURL:inURL];
    if(theImage) {
        [self webImageManager:theManager didFinishWithImage:theImage];
    }
    else {
        if(inPlaceholder) {
            [self webImageManager:theManager didFinishWithImage:inPlaceholder];
        }
        [theManager downloadWithURL:inURL delegate:self];
    }
}

- (void)webImageManager:(SDWebImageManager *)inManager didFinishWithImage:(UIImage *)inImage {
    [self setImage:inImage forState:UIControlStateNormal];
}

@end