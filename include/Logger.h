#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

enum class LogLevel { INFO, WARNING, ERROR };

class Logger {
private:

    static std::string GetTimeStamp() 
    {
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        std::tm tm = *std::localtime(&time);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    static const char* LevelToString(LogLevel level) 
    {
        switch(level) {
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR:   return "ERROR";
            default:                return "DEFAULT";
        }
    }

    static const char* sanitize(const std::string& s) { return s.c_str(); }

    template <typename T>
    static T sanitize(T t) { return t; }

public:

    template <typename... Args>
    static void Log(LogLevel level, const std::string& format, Args... args) 
    {
        std::string time = GetTimeStamp();
        const char* lvl = LevelToString(level);

        printf("[%s][%s]: ", time.c_str(), lvl);
        printf(format.c_str(), sanitize(args)...);
        printf("\n");
    }
};
