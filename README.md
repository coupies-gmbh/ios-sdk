# COUPIES iOs SDK

The COUPIES iOs SDK enables you to easily integrate coupons in your app. The easiest way is to display everything in a UIWebView and let COUPIES do the rendering. You can customize the appearance with CSS. It is also possible to retrieve the objects directly (e.g. coupons and locations) and do the UI natively.

## Usage

To access the COUPIES API you need to register your application and receive an API-Key (felix.schul@coupies.de). You can register multiple applications and for each of them you will receive an API-key for accessing the API resources.

To run the example project (HelloCOUPIES), clone the repo, and open the Xcode project in the "HelloCOUPES" directory. Make sure to enter your API-key in the file COUPIES.plist

## Requirements

The COUPIES SDK requires iOS 5.0 or later.

## Installation

COUPIES uses [CocoaPods](http://cocoapods.org).

To install it, simply add the following line to your Podfile:

    pod "COUPIES-iOS-SDK", "~> 1.4.0"

To install COUPIES without CocoaPods, contact felix.schul@coupies.de

## Author

Felix Schul, felix.schul@coupies.de

#Bugs

If you encounter any bugs. Please [report them](https://github.com/coupies-gmbh/ios-sdk/issues).