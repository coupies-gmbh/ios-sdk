#import "NativeListTableViewController.h"
#import "NativeCouponViewController.h"
#import "CouponCell.h"
#import <COUPIES/COUPIES.h>

@interface NativeListTableViewController()<COUPIESRestServiceDelegate>

@property (copy) NSArray *coupons;
@property (strong) NSData *cellData;
@property (strong) NSString *cellIdentifier;

- (void)reset;

@end

@implementation NativeListTableViewController

@synthesize coupiesManager;
@synthesize restService;
@synthesize coupons;
@synthesize cellData;
@synthesize cellIdentifier;
@synthesize couponViewController;

- (void)viewDidLoad {
    [super viewDidLoad];
    self.restService = [self.coupiesManager newRestService];
    self.restService.delegate = self;
    [self reloadList];
}

- (void)viewDidUnload {
    [self reset];
    [super viewDidUnload];
}

- (void)dealloc {
    [self reset];
}

- (void)reset {
    tableView = nil;
    activityIndicatorView = nil;
    self.coupons = nil;
    self.restService = nil;
    self.coupiesManager = nil;
    self.cellData = nil;
    self.cellIdentifier = nil;
    self.couponViewController = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)inInterfaceOrientation {
    return YES;
}

#pragma mark public methods

-(void)reloadList {
    self.coupons = nil;
    [tableView reloadData];
    [activityIndicatorView startAnimating];
    [self.restService listFeedCoupons];
}

#pragma mark UITableViewDataSource

- (NSInteger)tableView:(UITableView *)inTableView numberOfRowsInSection:(NSInteger)inSection {
    return [self.coupons count];
}

- (UITableViewCell *)tableView:(UITableView *)inTableView cellForRowAtIndexPath:(NSIndexPath *)inIndexPath {
    COUPIESOffer *theCoupon = [self.coupons objectAtIndex:inIndexPath.row];
    CouponCell *theCell = (CouponCell *)[inTableView dequeueReusableCellWithIdentifier:self.cellIdentifier];
    
    if (theCell == nil) {
        theCell = [self createCouponCell];
    }
    theCell.coupon = theCoupon;
    return theCell;
}

- (CouponCell *)couponCell {
    return nil;
}

- (CouponCell *)createCouponCell {
    return [NSKeyedUnarchiver unarchiveObjectWithData:self.cellData];
}

- (void)setCouponCell:(CouponCell *)inCell {
    self.cellData = [NSKeyedArchiver archivedDataWithRootObject:inCell];
    self.cellIdentifier = inCell.reuseIdentifier;
    cellHeight = CGRectGetHeight(inCell.frame);
}

#pragma mark UITableViewDelegate

- (CGFloat)tableView:(UITableView *)inTableView heightForRowAtIndexPath:(NSIndexPath *)inIndexPath {
    return cellHeight;
}

- (void)tableView:(UITableView *)inTableView didSelectRowAtIndexPath:(NSIndexPath *)inIndexPath {
    NativeCouponViewController *theController = self.couponViewController;
    COUPIESCoupon *theCoupon = [self.coupons objectAtIndex:inIndexPath.row];
    theController.coupon = theCoupon;
    theController.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:theController animated:YES];
}

#pragma mark COUPIESRestServiceDelegate

- (void)restService:(COUPIESRestService *)inService receivedResult:(NSArray *)inResult {
    self.coupons = inResult;
    [tableView reloadData];
    [activityIndicatorView stopAnimating];
}

- (void)restService:(COUPIESRestService *)inService receivedErrors:(NSArray *)inErrors {
    COUPIESError *theError = [inErrors lastObject];
    UIAlertView *theAlert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Fehler", @"") 
                                                       message:theError.message 
                                                      delegate:nil 
                                             cancelButtonTitle:@"OK" 
                                             otherButtonTitles:nil];
    
    [theAlert show];
    [activityIndicatorView stopAnimating];
}

- (void)restServiceHasBadCredentials:(COUPIESRestService *)inService {
    UIAlertView *theAlert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Fehler", @"") 
                                                       message:NSLocalizedString(@"Die Zugangsdaten sind nicht gültig.", @"") 
                                                      delegate:nil 
                                             cancelButtonTitle:@"OK" 
                                             otherButtonTitles:nil];
    
    [theAlert show];
    [activityIndicatorView stopAnimating];
}

@end
