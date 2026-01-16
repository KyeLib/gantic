#include "Logger.h"
#include "Processes.h"

#include <windows.h>
#include <iphlpapi.h>
#include <iostream>
#include <sstream>

#pragma comment(lib, "iphlpapi.lib") // Link to IP Helper API

void hardwareInfo() {


    HW_PROFILE_INFO   HwProfInfo;
    if (!GetCurrentHwProfile(&HwProfInfo))
    {
        Logger::error("GetCurrentHwProfile failed");
        return;
    }

    std::string GUID{ HwProfInfo.szHwProfileGuid };
    Logger::info("Profile Guid = " + GUID);

    IP_ADAPTER_INFO AdapterInfo[16];
    DWORD dwBufLen = sizeof(AdapterInfo);

    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) != ERROR_SUCCESS) {
        Logger::error("Failed to get network adapter info.");
        return;
    }

    PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

    while (pAdapterInfo) {
        std::ostringstream mac;
        for (UINT i = 0; i < pAdapterInfo->AddressLength; i++) {
            if (i != 0) mac << "-";
            mac << std::hex << std::uppercase
                << (pAdapterInfo->Address[i] < 16 ? "0" : "")
                << (int)pAdapterInfo->Address[i];
        }

        Logger::info("MAC Address: " + mac.str());

        pAdapterInfo = pAdapterInfo->Next;
    }

}