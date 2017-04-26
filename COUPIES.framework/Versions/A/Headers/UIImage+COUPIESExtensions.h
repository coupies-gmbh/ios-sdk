//
//  UIImage+COUPIESExtensions.h
//  COUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIImage(COUPIESExtension)

+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
+ (UIImage *)imageMakeWithImage:(UIImage*)originalImage andImage:(UIImage*)extraImage;
+ (UIImage *)tabBarImageWithIdentifier:(NSString *)identifier;
- (UIImage *)fixOrientation;

@end
