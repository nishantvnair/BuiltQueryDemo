//
//  RightSocket.h
//  SocketTesterARC
//
//  Created by Reefaq on 28/02/14.
//  Copyright (c) 2014 rawengineering. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SocketIO.h"
@class SocketIOPacket;

@interface RightSocket : NSObject

-(id)initAndConnectToHost:(NSString*)host;
-(id)initAndConnectToHost:(NSString*)host isSSL:(BOOL)ssl;
-(id)initAndConnectToHost:(NSString*)host onPort:(NSInteger)port;
-(id)initAndConnectToHost:(NSString*)host onPort:(NSInteger)port isSSL:(BOOL)ssl;
-(id)initAndConnectToHost:(NSString*)host onPort:(NSInteger)port withNameSpace:(NSString*)namespace isSSL:(BOOL)ssl;
-(id)initAndConnectToHost:(NSString*)host onPort:(NSInteger)port withParams:(NSDictionary *)params withNameSpace:(NSString*)namespace isSSL:(BOOL)ssl;
-(void)reConnect:(BOOL)force;

-(void)on:(NSString*)eventName callback:(SocketIOCallback)callbackBlock;

-(void)emit:(NSString*)eventName withData:(id)data;
-(void)emit:(NSString*)eventName withData:(id)data withCallback:(SocketIOCallback)callbackBlock;

-(void)send:(NSString*)message;
-(void)send:(NSString*)message withCallback:(SocketIOCallback)callbackBlock;

-(void)onMessageCallback:(SocketIOCallback)callbackBlock;
-(void)onConnectCallback:(SocketIOCallback)callbackBlock;
-(void)onDisconnectCallback:(SocketIOCallback)callbackBlock;
-(void)onErrorCallback:(SocketIOCallback)callbackBlock;

-(void)disconnect;
-(void)disconnectForced;

-(void)removeAllListeners;

@end
