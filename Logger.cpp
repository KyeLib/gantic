#include "Logger.h"


#include <string>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>



static std::ofstream logFile{ logs.txt", std::ios::app };


//Gets current date and time
static std::string getCurTime()
{

    auto getTime{ std::chrono::system_clock::now() };

    std::time_t timeNow{ std::chrono::system_clock::to_time_t(getTime) };

    std::tm localTime{};
    localtime_s(&localTime, &timeNow);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%c");

    return oss.str();

}

//Prints: "[timestamp] [log level] message"
void Logger::write(LogLevels level, const std::string& message)
{
    if (logFile.is_open())
        return;

    logFile
        << "[" << getCurTime() << "] "
        << "[" << logLevelToText(level) << "] "
        << message << "\n";

    logFile.flush();
}


//api
void Logger::info(const std::string& message)
{
    write(LogLevels::info, message);
}

void Logger::warn(const std::string& message)
{
    write(LogLevels::warn, message);
}

void Logger::error(const std::string& message)
{
    write(LogLevels::error, message);
}

void Logger::detected(const std::string& message)
{
    write(LogLevels::detected, message);
}