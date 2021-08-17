//
//  SLog.h
//  SLog
//
//  Created by 张熙文 on 2021/6/24.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>


//! Project version number for SLog.
FOUNDATION_EXPORT double SLogVersionNumber;

//! Project version string for SLog.
FOUNDATION_EXPORT const unsigned char SLogVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SLog/PublicHeader.h>

#undef DDLogError
#undef DDLogWarn
#undef DDLogInfo
#undef DDLogDebug
#undef DDLogVerbose

#define SLOG_FLAG_ERROR   (1 << 0)  // 0...0000001
#define SLOG_FLAG_WARN    (1 << 1)  // 0...0000010
#define SLOG_FLAG_INFO    (1 << 2)  // 0...0000100
#define SLOG_FLAG_DEBUG   (1 << 3)  // 0...0001000
#define SLOG_FLAG_VERBOSE (1 << 4)  // 0...0010000

#define SLOG_LEVEL_ERROR   (SLOG_FLAG_ERROR)                      // 0...0000001
#define SLOG_LEVEL_WARN    (SLOG_FLAG_WARN | SLOG_LEVEL_ERROR)    // 0...0000011
#define SLOG_LEVEL_INFO    (SLOG_FLAG_INFO | SLOG_LEVEL_WARN)     // 0...0000111
#define SLOG_LEVEL_DEBUG   (SLOG_FLAG_DEBUG | SLOG_LEVEL_INFO)    // 0...0001111
#define SLOG_LEVEL_VERBOSE (SLOG_FLAG_VERBOSE | SLOG_LEVEL_DEBUG) // 0...0011111

#define SLOG_ERROR   (sLogLevel & LOG_FLAG_ERROR)
#define SLOG_WARN    (sLogLevel & LOG_FLAG_WARN)
#define SLOG_INFO    (sLogLevel & LOG_FLAG_INFO)
#define SLOG_DEBUG   (sLogLevel & LOG_FLAG_DEBUG)
#define SLOG_VERBOSE (sLogLevel & LOG_FLAG_VERBOSE)


#define SLogError(frmt, ...)   LOG_MAYBE(NO,  sLogLevel, SLOG_FLAG_ERROR, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SLogWarn(frmt, ...)    LOG_MAYBE(YES, sLogLevel, SLOG_FLAG_WARN, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SLogInfo(frmt, ...)    LOG_MAYBE(YES, sLogLevel, SLOG_FLAG_INFO, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SLogDebug(frmt, ...)   LOG_MAYBE(YES, sLogLevel, SLOG_FLAG_DEBUG, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SLogVerbose(frmt, ...) LOG_MAYBE(YES, sLogLevel, SLOG_FLAG_VERBOSE, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


extern DDLogLevel sLogLevel;


NS_ASSUME_NONNULL_BEGIN


@interface SLog : NSObject

///日志文件最大个数，超出部分会删除
@property (nonatomic, assign) int maximumNumberOfLogFiles;
///允许日志文件增长的最大大小(以字节为单位)。 如果日志文件大于这个值， 将会生成一个新的日志文件进行继续写入
@property (nonatomic, assign) int maximumFileSize;
///日志文件频率 频率以NSTimeInterval的形式给出，它是一个双精度浮点数，指定以秒为单位的间隔。 一旦日志文件变得这么旧，它就会被重新生成
@property (nonatomic, assign) NSTimeInterval rollingFrequency;
///是否打开Apple System Logs
@property (nonatomic, assign) BOOL isOpenASL;
///是否输入到控制台
@property (nonatomic, assign) BOOL isOpenConsole;
///日志等级 传入 SLOG_LEVEL_XXX
@property (nonatomic, assign) DDLogLevel logLevel;



/**
 获取单例
 
 @return 单例
 */
+ (instancetype)sharedInstance;

/**
 开启日志文件系统
 */
- (void)enbleFileLogSystem;


@end

NS_ASSUME_NONNULL_END
