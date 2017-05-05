Pod::Spec.new do |s|
    s.name                    = "COUPIES"
    s.version                 = "1.10.2"
    s.platform                = :ios, "8.0"
    s.summary                 = "iOS SDK for integrating COUPIES coupons into your application."
    s.homepage                = "https://github.com/coupies-gmbh/ios-sdk"
    s.social_media_url        = "https://facebook.com/COUPIES"
    s.authors                 = { "Marcel Bender" => "marcel.bender@coupies.de" }
    s.license                 = { :type => "Copyright",
                                  :text => "Copyright 2017 COUPIES GmbH. All rights reserved." }
    s.source                  = { :git => "https://github.com/coupies-gmbh/ios-sdk.git",
                                  :tag => s.version.to_s }

    s.resources               = "COUPIES.framework/Versions/A/Resources/*.bundle"

    s.ios.vendored_frameworks = "COUPIES.framework"

    s.library                 = "iconv"

    s.frameworks              = "AdSupport", "QuartzCore", "CoreAudio", "CoreMedia", "CoreImage","CoreVideo", "CoreGraphics", "AudioToolbox", "AVFoundation", "Foundation", "UIKit", "CoreGraphics", "CoreLocation", "Mapkit", "OpenGLES", "MobileCoreServices", "ImageIO", "GLKit" 

    s.requires_arc            = true

    s.xcconfig                = { "OTHER_LDFLAGS" => "$(inherited) -ObjC -all_load",
                                  "CLANG_MODULES_AUTOLINK" => "YES" }
end
