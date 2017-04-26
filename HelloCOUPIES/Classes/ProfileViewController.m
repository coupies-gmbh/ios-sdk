//
//  ProfileViewController.m
//  HelloCOUPIES
//
//  Copyright COUPIES GmbH. All rights reserved.
//

#import "ProfileViewController.h"
#import "HelloCOUPIESAppDelegate.h"
#import <COUPIES/COUPIES.h>

@implementation ProfileViewController

@synthesize requestFactory;

- (void)dealloc {
    [self reset];
}

- (void)reset {
    activityIndicatorView = nil;
    self.requestFactory = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // This object will generate HTML requests for our WebView, that we will use to show user profile
    id theDelegate = [[UIApplication sharedApplication] delegate];
    self.requestFactory = [[theDelegate coupiesManager] requestFactoryForType:kCOUPIESRequestFactoryTypeHTML];
    [self reload];
}

- (void)viewDidUnload {
    [self reset];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)inInterfaceOrientation {
    return YES;
}

#pragma mark - Public methods

-(void)reload {
    [activityIndicatorView startAnimating];
    NSURLRequest *theRequest = [self.requestFactory requestForRefreshingUser];
    [webView loadRequest:theRequest];
}

#pragma mark - UIWebViewDelegate

- (void)webViewDidStartLoad:(UIWebView *)inWebView {    
    [activityIndicatorView startAnimating];
    inWebView.userInteractionEnabled = NO;
}

- (void)webViewDidFinishLoad:(UIWebView *)inWebView {
    [activityIndicatorView stopAnimating];
    inWebView.userInteractionEnabled = YES;
}

- (void)webView:(UIWebView *)inWebView didFailLoadWithError:(NSError *)error {
    [activityIndicatorView stopAnimating];
    inWebView.userInteractionEnabled = YES;
}

@end
