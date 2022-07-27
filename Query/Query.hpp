#pragma once

#include "../Globals/Include.hpp"

enum PROTECTION_TYPE
{
    DEFAULT = 0,
    INITIAL_PROTECT
};

namespace Query
{
    void MemoryRegions();
    std::string GetProtectionType(MEMORY_BASIC_INFORMATION mInfo, PROTECTION_TYPE protType);
}