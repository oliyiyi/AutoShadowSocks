//
//  ShadowSocksHelper.h
//  SSLinker
//
//  Created by sma11case on 2/16/16.
//  Copyright © 2016 sma11case. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "librarys/OSX/staticLibrary_OSX.h"

@interface ShadowSocksConfig : SCNetworkInfo
@property (nonatomic, strong) NSString *method;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, assign) NSUInteger timeout;
@end

@interface SSLinkConfig : ShadowSocksConfig
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *hostingId;
@property (nonatomic, assign) BOOL hostingState;
@end

@interface ShadowSocksHelper : SCObject
+ (void)runSSClientWithParam: (ShadowSocksConfig *)param listenParam: (SCNetworkInfo *)sparam;
+ (void)runSSClientWithStringParam: (NSString *)param;
+ (BOOL)verifySSWithListenParam:(SCNetworkInfo *)param url: (NSString *)url;
@end

@interface ShadowSocksHelper(SSLink)
+ (void)sslink_loginWithUser: (NSString *)user password: (NSString *)pwd block:(BoolBlock)block;
+ (void)sslink_getServersWithBlock:(ArrayBlock)block;
+ (void)sslink_getBuyServerList:(ArrayBlock)block;
+ (void)sslink_buyServerWithName: (NSString *)name block: (BoolBlock)block;
@end
