Pod::Spec.new do |s|
    s.name                    = "COUPIES"
    s.version                 = "1.9.12"
    s.platform                = :ios, "5.0"
    s.summary                 = "iOS SDK for integrating COUPIES coupons into your application."
    s.homepage                = "https://github.com/coupies-gmbh/ios-sdk"
    #s.documentation_url       = "http://sensorberg-dev.github.io/ios-sdk/#{s.version}/"
    s.social_media_url        = "https://facebook.com/COUPIES"
    s.authors                 = { "Felix Schul" => "felix.schul@coupies.de" }
    s.license                 = { :type => "Copyright",
                                  :text => "Copyright 2015 COUPIES GmbH. All rights reserved." }
    s.source                  = { :git => "https://github.com/coupies-gmbh/ios-sdk.git",
                                  :tag => s.version.to_s }

    s.resources               = "COUPIES.framework/Versions/A/Resources/*.bundle"

    s.ios.vendored_frameworks = "COUPIES.framework"

    s.library                 = "iconv"

    s.frameworks              = "AdSupport", "QuartzCore", "CoreAudio", "CoreMedia", "CoreVideo", "CoreGraphics", "AudioToolbox", "AVFoundation", "Foundation", "UIKit", "CoreGraphics", "CoreLocation", "Mapkit"

    s.dependency				"ZBarSDK", "~> 1.3"

    s.requires_arc            = true

    s.xcconfig                = { "OTHER_LDFLAGS" => "$(inherited) -ObjC -all_load",
                                  "CLANG_MODULES_AUTOLINK" => "YES" }
end