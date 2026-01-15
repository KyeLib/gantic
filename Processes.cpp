#include "Processes.h"
#include "Logger.h"

#include <windows.h>
#include <TlHelp32.h>
#include <string>


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