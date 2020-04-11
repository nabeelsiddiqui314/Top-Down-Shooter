#pragma once
#include <cstdint>
#include <bitset>

using Entity_ID = std::uint32_t;
using Component_ID = std::uint8_t;

constexpr int COMPONENTS_LIMIT = 256;
using ComponentList = std::bitset<COMPONENTS_LIMIT>;