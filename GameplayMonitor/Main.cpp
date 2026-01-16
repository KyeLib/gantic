#include "Logger.h"
#include "Processes.h"






int main()
{
    Logger::init("logs.txt");

    listProcesses();

    Logger::end();

    Logger::init("logs.txt");

    blackListedProcesses();

    Logger::end();

    return 0;
}