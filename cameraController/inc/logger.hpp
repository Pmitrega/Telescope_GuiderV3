#ifndef LOGGER_HPP
#define LOGGER_HPP
// Conditional compilation flags for enabling/disabling logs
#define ENABLE_LOG_INFO_BASIC 1
#define ENABLE_LOG_INFO_DETAIL 1
#define ENABLE_LOG_INFO_DEBUG 1
#define ENABLE_LOG_WARNING_BASIC 1
#define ENABLE_LOG_WARNING_CRITICAL 1
#define ENABLE_LOG_ERROR 1

namespace Logger {
    void loggerInit();

    void logInfoBasic(const std::string& message);
    void logInfoDetail(const std::string& message);
    void logInfoDebug(const std::string& message);

    void logWarningBasic(const std::string& message);
    void logWarningCritical(const std::string& message);

    void logError(const std::string& message);
}

#endif // LOGGER_HPP