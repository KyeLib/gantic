#include <chrono>
#include <iostream>



//Gets current time
//Will move in future
std::string getCurTime()
{

    auto getTime{ std::chrono::system_clock::now() };

    std::time_t timeNow{ std::chrono::system_clock::to_time_t(getTime) };

    std::tm localTime{};
    localtime_s(&localTime, &timeNow);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%c");

    return oss.str();

}


int main()
{

    std::cout << getCurTime();
       
}