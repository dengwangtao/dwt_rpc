#pragma once

#include "dwt_block_queue.hpp"

#include <mutex>
#include <string>
#include <thread>
#include <sys/time.h>
#include <string.h>
#include <stdarg.h>           // vastart va_end
#include <assert.h>
#include <sys/stat.h>         //mkdir

#include "dwt_block_queue.hpp"
#include "dwt_buffer.h"

class DwtLogger {
public:
    void init(int level, const char* path = "./log",
                const char* suffix =".log",
                int maxQueueCapacity = 1024);

    static DwtLogger* Instance();
    static void FlushLogThread();

    void write(int level, const char *format,...);
    void flush();

    int GetLevel();
    void SetLevel(int level);
    bool IsOpen() { return isOpen_; }
    
private:
    DwtLogger();
    void AppendLogLevelTitle_(int level);
    virtual ~DwtLogger();
    void AsyncWrite_();

private:
    static const int LOG_PATH_LEN = 256;  // 日志路径的最大长度
    static const int LOG_NAME_LEN = 256;  // 日志名称的最大长度
    static const int MAX_LINES = 50000;

    const char* path_;
    const char* suffix_;

    int MAX_LINES_;

    int lineCount_;
    int toDay_;

    bool isOpen_;
 
    DwtBuffer buff_;
    int level_;
    bool isAsync_;

    FILE* fp_;
    std::unique_ptr<DwtBlockDeque<std::string>> deque_;
    std::unique_ptr<std::thread> writeThread_;
    std::mutex mtx_;
};

// level = 1
// LOG_DEBUG  0 <= 1  y
// LOG_INFO   1 <= 1  y
// LOG_WARN   2 <= 1  n
// LOG_ERROR  3 <= 1  n
#define DWT_LOG_BASE(level, format, ...) \
    do {\
        DwtLogger* log = DwtLogger::Instance();\
        if (log->IsOpen() && log->GetLevel() <= level) {\
            log->write(level, format, ##__VA_ARGS__); \
            log->flush();\
        }\
    } while(0);

#define DWT_LOG_DEBUG(format, ...) do {DWT_LOG_BASE(0, format, ##__VA_ARGS__)} while(0);
#define DWT_LOG_INFO(format, ...)  do {DWT_LOG_BASE(1, format, ##__VA_ARGS__)} while(0);
#define DWT_LOG_WARN(format, ...)  do {DWT_LOG_BASE(2, format, ##__VA_ARGS__)} while(0);
#define DWT_LOG_ERROR(format, ...) do {DWT_LOG_BASE(3, format, ##__VA_ARGS__)} while(0);
