//
//  UIImage+COUPIESExtensions.h
//  COUPIES
//
//  Created by Felix Schul on 07.02.13.
//  Copyright (c) 2013 COUPIES GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIImage(COUPIESExtension)

+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
+(UIImage*) imageMakeWithImage:(UIImage*)originalImage andImage:(UIImage*)extraImage;
+(UIImage*) imageMakeWithImage:(UIImage*)image AndCropInRect:(CGRect) rect InSize:(CGSize) size;
- (UIImage *)fixOrientation;

@end
