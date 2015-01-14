# COUPIES iOs SDK

The COUPIES iOs SDK enables you to easily integrate coupons in your app. The easiest way is to display everything in a UIWebView and let COUPIES do the rendering. You can customize the appearance with CSS. It is also possible to retrieve the objects directly (e.g. coupons and locations) and do the UI natively.

## Requirements

The COUPIES SDK requires iOS 5.0 or later.

## Installation

### Install using [CocoaPods](http://cocoapods.org)

We recommend installing COUPIES via [CocoaPods](http://cocoapods.org). Simply add the following line to your Podfile:

    pod "COUPIES-iOS-SDK", "~> 1.9"

### Install manually

To install COUPIES without CocoaPods, follow these steps:

1. Download the [latest stable version](https://github.com/coupies-gmbh/ios-sdk/).

2. Import COUPIES.framework into the Frameworks folder of your project.

3. Import ZBarSDK/libzbar.a into the Frameworks folder of your project ([more details](https://github.com/ZBar/ZBar)).

4. Import the COUPIES.bundle out of COUPIES.framework/Resources in the resources folder of your project.

5. Import the COUPIES.xcconfig configuration file to the resources of your project. You do not need to add this file to the build target.

6. Under your project settings at "Info", select the configurationset "COUPIES" for all configurations. 

## Usage

To access the COUPIES API you need to register your application and receive an API-Key (felix.schul@coupies.de). You can register multiple applications and for each of them you will receive an API-key for accessing the API resources.

Import the COUPIES.plist file into the resources folder and set your API-key.

To run the example project (HelloCOUPIES), clone the repo, and open the Xcode project in the "HelloCOUPES" directory. Make sure to enter your API-key in the file COUPIES.plist

## Author

Felix Schul, felix.schul@coupies.de

#Bugs

If you encounter any bugs. Please [report them](https://github.com/coupies-gmbh/ios-sdk/issues).