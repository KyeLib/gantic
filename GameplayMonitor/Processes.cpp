#include "Processes.h"
#include "Logger.h"

#include <windows.h>
#include <TlHelp32.h>
#include <string>
#include <fstream>

//list running processes
//Possible loss of data from wchar_t to char
void listProcesses() {

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32W ab{};
    ab.dwSize = sizeof(ab);

    if (Process32FirstW(snapshot, &ab)) {
        do {

            std::wstring file{ ab.szExeFile };
            std::string processName{ file.begin(), file.end() };
            DWORD pid{ ab.th32ProcessID };
            Logger::info("Process detected: " + processName + " (PID: " + std::to_string(pid) + ")");

        } while (Process32NextW(snapshot, &ab));

    }
    CloseHandle(snapshot);

}

//Checks running processes then compares name to those in blacklist.txt and warns of blacklisted program
//Same possible loss of data from wchar_t to char
void blackListedProcesses() {

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32W ab{};
    ab.dwSize = sizeof(ab);

    if (Process32FirstW(snapshot, &ab)) {
        do {

            std::wstring file{ ab.szExeFile };
            std::string processName{ file.begin(), file.end() };
            DWORD pid{ ab.th32ProcessID };

         std::ifstream blacklist("Blacklist.txt");

        if (!blacklist.is_open())
        {
        Logger::error("Failed to open Blacklist.txt");
        }

        std::string blacklisted;
        while (blacklist >> blacklisted)
        {
            if (processName == blacklisted)
            {
                Logger::detected("Blacklisted process detected: " + processName + " (PID: " + std::to_string(pid) + ")");
            }
        }

            blacklist.close();


        } while (Process32NextW(snapshot, &ab));

    }
    CloseHandle(snapshot);

}