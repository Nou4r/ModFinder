#include "Query.hpp"

void Query::MemoryRegions()
{
    IMAGE_DOS_HEADER dosHeader = { 0 };
    MEMORY_BASIC_INFORMATION memInfo = { 0 };

    const HANDLE procHandle = Process::GetHandle(Globals::procName.c_str());
    const HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    uintptr_t currentAddress = 0;
    void* suspectAddress = (void*)memInfo.BaseAddress;
    unsigned int addressCount = 0;

    static std::vector<void*>arr;

    while (VirtualQueryEx(procHandle, (LPCVOID)currentAddress, &memInfo, sizeof(memInfo)))
    {
        // Don't repeatedly set.
        if (!SetConsoleTitleA("Scanning..."))
            SetConsoleTitleA("Scanning...");

        // Calculation for next address.
        currentAddress = (uintptr_t)memInfo.BaseAddress + memInfo.RegionSize;

        // Ignore 0x0 address or a NULL address.
        if (!memInfo.BaseAddress)
            continue;

        // Ignore any region with a size less than 4KB.
        if (memInfo.RegionSize < 4096)
            continue;

        // Ignore non private regions.
        // NOTE -> Manual-mapped modules are ALWAYS going to have a private type.
        if (memInfo.Type != MEM_PRIVATE)
            continue;

        // Enumerate addresses and find the DOS header.
        ReadProcessMemory(Process::GetHandle(Globals::procName.c_str()), memInfo.BaseAddress, &dosHeader, sizeof(dosHeader), NULL);

        bool hasValidDosHeader = dosHeader.e_magic == IMAGE_DOS_SIGNATURE;

        // Initial protection is ERW && current protection is R = typically mapped code.
        // Initial protection is ERW && current protection is ERW = typically mapped code.
        if (memInfo.AllocationProtect == PAGE_EXECUTE_READWRITE && memInfo.Protect == PAGE_READONLY ||
            memInfo.AllocationProtect == PAGE_EXECUTE_READWRITE && memInfo.Protect == PAGE_EXECUTE_READWRITE)
        {
            addressCount++;

            std::cout << "\n0x" << std::hex << memInfo.BaseAddress << "\n";
            std::cout << "  |_ Region size      --> " << std::dec << memInfo.RegionSize << "Kb" << "\n";
            std::cout << "  |_ Initial rights   --> " << GetProtectionType(memInfo, PROTECTION_TYPE::INITIAL_PROTECT) << "\n";
            std::cout << "  |_ Current rights   --> " << GetProtectionType(memInfo, PROTECTION_TYPE::DEFAULT) << "\n";
            std::cout << "  |_ DOS header       --> ";

            if (hasValidDosHeader)
            {
                // Set to current looped address.
                suspectAddress = memInfo.BaseAddress;

                // Append current suspect address to array.
                arr.push_back(suspectAddress);

                // Green
                SetConsoleTextAttribute(consoleHandle, 10);

                printf("Yes\n");

                // Normal
                SetConsoleTextAttribute(consoleHandle, 7);
            }
            else
                printf("No\n");
            
            std::cout << "__________________________________________" << "\n";
        }
    }

    if (addressCount >= 0)
    {
        SetConsoleTitleA("Finished");

        std::cout << "\nSummary\n";
        std::cout << "  |_ Address count    --> " << addressCount << "\n";
        
        std::cout << "  |_ Most suspicious  --> ";

        for (unsigned int i = 0; i < arr.size(); i++)
        {
            std::cout << "0x" << arr[i];

            std::cout << i << "\n";

            // Seperate when the value is less then max - 1.
            if (i != arr.size() - 1)
                std::cout << ", ";
        }

        std::cout << "\n";
    }

    // Prevent auto closing.
    std::cin.get();
}