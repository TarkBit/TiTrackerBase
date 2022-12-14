#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol TiTrackerBaseDelegate <NSObject>
- (NSString*) _evaluateJavascript:(NSString*)command;
@end
typedef NSDictionary WVJBMessage;
typedef void (^WVJBResponseCallback)(id responseData);
typedef void (^WVJBHandler)(id data, WVJBResponseCallback responseCallback);

@interface TiTrackerBase : NSObject
@property (weak, nonatomic) id <TiTrackerBaseDelegate> delegate;
@property (strong, nonatomic) NSMutableDictionary* responseCallbacks;
@property (strong, nonatomic) NSMutableDictionary* messageHandlers;
@property (strong, nonatomic) WVJBHandler messageHandler;

- (void)sendData:(id)data responseCallback:(WVJBResponseCallback)responseCallback handlerName:(NSString*)handlerName;
- (void)flushMessageQueue:(NSString *)messageQueueString;
@end

NS_ASSUME_NONNULL_END
