/*
 * Copyright (c) 2011 Yeecco Limited
 */

#import <Foundation/Foundation.h>
#import <StellaGraphics/StellaGraphics.h>
#import "StellaKitExport.h"
#import "SVView.h"
#import "SVScrollView.h"

@class UIWebView;

enum {
        UIWebViewNavigationTypeLinkClicked,
        UIWebViewNavigationTypeFormSubmitted,
        UIWebViewNavigationTypeBackForward,
        UIWebViewNavigationTypeReload,
        UIWebViewNavigationTypeFormResubmitted,
        UIWebViewNavigationTypeOther
};
typedef NSUInteger UIWebViewNavigationType;

@protocol UIWebViewDelegate <NSObject>

@optional
- (BOOL) webView: (UIWebView *) webView shouldStartLoadWithRequest: (NSURLRequest *) request navigationType: (UIWebViewNavigationType) navigationType;
- (void) webViewDidStartLoad: (UIWebView *) webView;
- (void) webViewDidFinishLoad: (UIWebView *) webView;
- (void) webView: (UIWebView *) webView didFailLoadWithError: (NSError *) error;

@end

@interface UIWebView : UIView

@property(nonatomic, assign) id<UIWebViewDelegate> delegate;
- (void) loadData: (NSData *) data MIMEType: (NSString *) MIMEType textEncodingName: (NSString *) encodingName baseURL: (NSURL *) baseURL;
- (void) loadHTMLString: (NSString *) string baseURL: (NSURL *) baseURL;
- (void) loadRequest: (NSURLRequest *) request;
@property(nonatomic, readonly, retain) NSURLRequest       * request;
@property(nonatomic, readonly, getter=isLoading) BOOL       loading;
- (void) stopLoading;
- (void) reload;

@property(nonatomic, readonly, getter=canGoBack) BOOL       canGoBack;
@property(nonatomic, readonly, getter=canGoForward) BOOL    canGoForward;
- (void) goBack;
- (void) goForward;
@property(nonatomic) BOOL                                   scalesPageToFit;
@property(nonatomic, readonly, retain)                      UIScrollView *scrollView;
@property(nonatomic) BOOL                                   suppressesIncrementalRendering;
@property(nonatomic) BOOL                                  keyboardDisplayRequiresUserAction;
@property(nonatomic) BOOL                                   detectsPhoneNumbers;
- (NSString *) stringByEvaluatingJavaScriptFromString: (NSString *) script;
@property(nonatomic) UIDataDetectorTypes                    dataDetectorTypes;
@property(nonatomic) BOOL                                   allowsInlineMediaPlayback;
@property(nonatomic) BOOL                                   mediaPlaybackRequiresUserAction;
@property(nonatomic) BOOL                                   mediaPlaybackAllowsAirPlay;

@end
