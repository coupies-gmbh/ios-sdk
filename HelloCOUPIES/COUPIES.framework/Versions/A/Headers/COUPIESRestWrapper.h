@interface COUPIESRestWrapper : NSObject {
    @private
    NSMutableData *data;
    NSString *mimeType;
    NSURLConnection *connection;
    BOOL asynchronous;
    id __unsafe_unretained delegate;
}

@property (strong, readonly) NSData *receivedData;
@property (nonatomic) BOOL asynchronous;
@property (copy) NSString *mimeType;
@property (unsafe_unretained) id delegate;

+ (id)restWrapper;
- (void)sendRequest:(NSURLRequest *)inRequest;
- (void)cancelConnection;

@end

@protocol COUPIESRestWrapperDelegate<NSObject>

@required
- (void)restWrapper:(COUPIESRestWrapper *)inRestWrapper didRetrieveData:(NSData *)inData;

@optional
- (void)restWrapperHasBadCredentials:(COUPIESRestWrapper *)inRestWrapper;
- (void)restWrapper:(COUPIESRestWrapper *)inRestWrapper didCreateResourceAtURL:(NSString *)inURL;
- (void)restWrapper:(COUPIESRestWrapper *)inRestWrapper didFailWithError:(NSError *)inError;
- (void)restWrapper:(COUPIESRestWrapper *)inRestWrapper didReceiveStatusCode:(int)inStatusCode;
- (void)restWrapper:(COUPIESRestWrapper *)inRestWrapper didSendBodyData:(NSDictionary*)inInfo;
    
@end