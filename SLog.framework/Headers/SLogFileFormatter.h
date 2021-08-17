//
//  SLogFileFormatter.h
//  SLog
//
//  Created by 张熙文 on 2021/6/24.
//

#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

@interface SLogFileFormatter : NSObject <DDLogFormatter>

/**
 *  默认初始化方法
 */
- (instancetype)init;

/**
 *  自定义NSDateFormatter初始化方法
 */
- (instancetype)initWithDateFormatter:(NSDateFormatter *)dateFormatter NS_DESIGNATED_INITIALIZER;


@end

NS_ASSUME_NONNULL_END
