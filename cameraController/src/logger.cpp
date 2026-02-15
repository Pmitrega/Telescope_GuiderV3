#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "logger.hpp"

// Replace #define with constexpr for modern C++
constexpr const char *RESET = "\033[0m";
constexpr const char *RED = "\033[31m";
constexpr const char *GREEN = "\033[32m";
constexpr const char *YELLOW = "\033[33m";
constexpr const char *BLUE = "\033[34m";
constexpr const char *MAGENTA = "\033[35m";
constexpr const char *CYAN = "\033[36m";
constexpr const char *WHITE = "\033[37m";

namespace Logger
{

    std::ofstream logFile;

    void loggerInit()
    {
// Create logs directory if it doesn't exist
#if defined(__linux__)
        system("mkdir -p ../logs");
#elif defined(_WIN32)
        system("mkdir . .\\logs");
#endif

        // Get current date and time
        std::time_t now = std::time(nullptr);
        std::tm *localTime = std::localtime(&now);

        // Format date and time as YYYY-MM-DD_HH-MM-SS
        std::ostringstream oss;
        oss << "logs_"
            << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S")
            << ".log";

        // Set the log file path one level higher in the directory tree
        std::string outputFilePath = "../logs/" + oss.str();

        // Open the log file
        logFile.open(outputFilePath);
        if (!logFile.is_open())
        {
            std::cerr << RED << "[ERROR] Failed to open log file: " << outputFilePath << RESET << std::endl;
        }
        else
        {
            std::cout << GREEN << "[INFO] Log file created: " << outputFilePath << RESET << std::endl;
        }
    }

    std::string getCurrentTime()
    {
        std::time_t now = std::time(nullptr);
        std::tm *localTime = std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(localTime, "%H:%M:%S");
        return oss.str();
    }

#ifdef ENABLE_LOG_INFO_BASIC
#if ENABLE_LOG_INFO_BASIC
    void logInfoBasic(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << GREEN << "[INFO] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[INFO] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logInfoBasic(const std::string &) {}
#endif
#endif

#ifdef ENABLE_LOG_INFO_DETAIL
#if ENABLE_LOG_INFO_DETAIL
    void logInfoDetail(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << GREEN << "[INFO-DETAIL] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[INFO-DETAIL] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logInfoDetail(const std::string &) {}
#endif
#endif

#ifdef ENABLE_LOG_INFO_DEBUG
#if ENABLE_LOG_INFO_DEBUG
    void logInfoDebug(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << GREEN << "[INFO-DEBUG] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[INFO-DEBUG] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logInfoDebug(const std::string &) {}
#endif
#endif

#ifdef ENABLE_LOG_WARNING_BASIC
#if ENABLE_LOG_WARNING_BASIC
    void logWarningBasic(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << YELLOW << "[WARNING] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[WARNING] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logWarningBasic(const std::string &) {}
#endif
#endif

#ifdef ENABLE_LOG_WARNING_CRITICAL
#if ENABLE_LOG_WARNING_CRITICAL
    void logWarningCritical(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << YELLOW << "[WARNING-CRITICAL] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[WARNING-CRITICAL] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logWarningCritical(const std::string &) {}
#endif
#endif

#ifdef ENABLE_LOG_ERROR
#if ENABLE_LOG_ERROR
    void logError(const std::string &message)
    {
        std::string time = getCurrentTime();
        std::cout << RED << "[ERROR] [" << time << "] " << RESET << message << std::endl;
        if (logFile.is_open())
        {
            logFile << "[ERROR] [" << time << "] " << message << std::endl;
        }
    }
#else
    void logError(const std::string &) {}
#endif
}
#endif