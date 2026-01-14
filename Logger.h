#pragma once
#include <string>
#include <fstream>

enum class LogLevels {
	info,
	warn,
	error,
	detected,
};

class Logger
{

public:

	static void init(const std::string& filepath = "logs.txt");

	static void end();

	static void info(const std::string& message);
	static void warn(const std::string& message);
	static void error(const std::string& message);
	static void detected(const std::string& message);


private:

	static void write(LogLevels level, const std::string& message );

	static std::string logLevelToText(LogLevels level);

	static std::ofstream logFile;

	static std::string filePath;




};