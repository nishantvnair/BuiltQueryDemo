//
//  BuiltSocket.h
//  BuiltIO
//
//  Created by rawmacmini on 06/03/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^BSVoidCallback)();
typedef void(^BSErrorCallback)(id error);
typedef void(^BSCallback)(id argsData);
typedef void(^BSResponseCallback)(id error,id responseData);

@interface BuiltSocket : NSObject

-(void)connectWithApiKey:(NSString*)apikey;
-(void)disconnect;
-(void)reConnect:(BOOL)force;

-(void)on:(NSString*)eventName callback:(BSCallback)callbackBlock;

-(void)emit:(NSString*)eventName withData:(id)data;
-(void)emit:(NSString*)eventName withData:(id)data withCallback:(BSResponseCallback)callbackBlock;

-(void)send:(NSString*)message;
-(void)send:(NSString*)message withCallback:(BSResponseCallback)callbackBlock;

-(void)onMessageCallback:(BSCallback)callbackBlock;
-(void)onConnectCallback:(BSVoidCallback)callbackBlock;
-(void)onDisconnectCallback:(BSVoidCallback)callbackBlock;
-(void)onErrorCallback:(BSErrorCallback)callbackBlock;

-(void)removeAllListeners;

@property (nonatomic, assign) BOOL shouldDisconnect;

@end
