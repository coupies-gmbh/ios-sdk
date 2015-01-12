//
//  User.h
//  COUPIES GmbH
//
//  Created by Felix Schul on 08.07.09.
//  
//  Datenklasse zur Abbildung eines Benutzers
//  Wird bei der Registrierung befüllt.

#import "COUPIESSAXParseable.h"


@class COUPIESPayout;

@interface COUPIESUser : COUPIESSAXParseable {
    @private
    int userId;
    BOOL saved;
	NSString *email;
    NSString *facebookId;
    NSString *firstname;
    NSString *lastname;
	NSString *password;
    NSString *secret;
    NSString *fbAccessToken;
	NSString *apnsToken;
    NSString *carrier;
	NSNumber *gender;
    NSNumber *age;
    NSNumber *pushIntensity;
    NSString *currency;
    double balance;
    double savedTotal;
    BOOL pushTokenSent;
    COUPIESPayout *lastPayout;
}

@property int userId;
@property (readonly) BOOL hasCredentials;
@property (readonly) BOOL isRegisteredUser;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *facebookId;
@property (nonatomic, copy) NSString *firstname;
@property (nonatomic, copy) NSString *lastname;
@property (nonatomic, copy) NSString *password;
@property (copy) NSString *secret;
@property (copy) NSString *fbAccessToken;
@property (copy) NSString *apnsToken;
@property (copy) NSString *carrier;
@property (copy) NSNumber *gender;
@property (copy) NSNumber *age;
@property (copy) NSString *currency;
@property double balance;
@property double savedTotal;
@property (copy) NSNumber *pushIntensity;
@property BOOL pushTokenSent;
@property (strong) COUPIESPayout *lastPayout;

+ (id)user;
+ (id)userWithEMail:(NSString *)inEMail;
- (void)read;
- (BOOL)update;
- (void)save;

@end
