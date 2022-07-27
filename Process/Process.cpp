#include "Process.hpp"

// From stackoverflow.
HANDLE Process::GetHandle(PCSTR proc)
{
    DWORD pid = 0;

    // Create toolhelp snapshot
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    ZeroMemory(&process, sizeof(process));
    process.dwSize = sizeof(process);

    // Enumerate processes
    if (Process32First(snapshot, &process))
    {
        do
        {
            // Compare process.szExeFile based on format of name, i.e., trim file path
            // trim .exe if necessary, etc.
            if (std::string(process.szExeFile) == std::string(proc))
            {
                pid = process.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &process));
    }

    // Cleanup.
    CloseHandle(snapshot);

    if (pid != 0)
        return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    // Not found.
    return NULL;
}