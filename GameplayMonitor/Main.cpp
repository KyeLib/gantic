#include "Logger.h"
#include "Processes.h"
#include "HardwareInfo.h"





int main()
{
    Logger::init("logs.txt");

    hardwareInfo();

    Logger::end();

    return 0;
}