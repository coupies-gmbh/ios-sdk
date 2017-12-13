//
//  COUPIESCameraView.h
//
//  Created by Marcel Bender.
//  Copyright (c) 2016 COUPIES GmbH. All rights reserved.
//
//  Based on IPDFCameraViewController
//  https://github.com/mmackh/IPDFCameraViewController
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, COUPIESDocumentDetectionStatus)
{
    /** An acceptable polygon was detected. */
    COUPIESDocumentDetectionStatusOK = 100,
    /** A polygon was detected, but it has too much perspective distortion. */
    COUPIESDocumentDetectionStatusOK_BadAngles = 101,
    /** A polygon was detected, but the distance is too far away. */
    COUPIESDocumentDetectionStatusOK_BadDistance = 103,
    
    /** No polygon detected at all. */
    COUPIESDocumentDetectionStatusError_NothingDetected = 200,
    /** No polygon detected, image too dark. */
    COUPIESDocumentDetectionStatusError_BrightnessLow = 201,
    /** No polygon detected, image too bright. */
    COUPIESDocumentDetectionStatusError_BrightnessHigh = 202,
    /** No polygon detected, image too noisy (background). */
    COUPIESDocumentDetectionStatusError_Noise = 203
};

@protocol COUPIESCameraViewDelegate;

@interface COUPIESCameraView : UIView

- (void)setupCameraView;
- (void)handleBorderDetectionStatus;
- (void)startCamera;
- (void)stopCamera;

@property (nonatomic, weak) id<COUPIESCameraViewDelegate> delegate;
@property (nonatomic,assign,getter=isBorderDetectionEnabled) BOOL enableBorderDetection;
@property (nonatomic,assign,getter=isTorchEnabled) BOOL enableTorch;

@property(nonatomic, strong) AVCaptureDevice *captureDevice;
@property (weak, nonatomic) IBOutlet UITabBar *tabBar;

@property(nonatomic, assign) CGFloat imageDetectionConfidence;
@property(nonatomic, assign) CGFloat imageDetectionErrorRate;
@property(nonatomic, assign) CGFloat imageDetectionBrightness;
@property(nonatomic, assign) CGFloat imageDetectionEdgeTolerance;
@property(nonatomic, assign) CGFloat imageDetectionTopEdge;
@property(nonatomic, assign) CGFloat imageDetectionLeftEdge;
@property(nonatomic, assign) CGFloat imageDetectionRightEdge;
@property(nonatomic, assign) CGFloat imageDetectionBottomEdge;
@property(nonatomic, assign) CGFloat imageDetectionAngleTolerance;
@property(nonatomic, assign) CGFloat imageDetectionAngleVertical;
@property(nonatomic, assign) CGFloat imageDetectionAngleHorizontal;

@property(nonatomic, assign) BOOL isBrightnessValid;
@property(nonatomic, assign) BOOL isEdgesValid;
@property(nonatomic, assign) BOOL isAnglesValid;
@property(nonatomic, assign) BOOL isDistanceValid;
@property(nonatomic, assign) BOOL isReadyToCapture;
@property(nonatomic, assign) BOOL isCapturing;

- (void)focusAtPoint:(CGPoint)point completionHandler:(void(^)())completionHandler;
- (void)captureImageWithCompletionHandler:(void(^)(NSString *imageFilePath))completionHandler;

@end


@protocol COUPIESCameraViewDelegate<NSObject>

- (void)captureOutputChangedWithStatus:(NSInteger)status;
- (void)updateImageDetectionStatus;

@end
