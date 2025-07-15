#pragma once

#include "Packets.h"
#include <vector>
#include <cstdint>
#include <cstring>

inline std::vector<uint8_t> SerializeHello(uint32_t clientId) {
    std::vector<uint8_t> buffer(sizeof(PacketType) + sizeof(clientId));
    buffer[0] = static_cast<uint8_t>(PacketType::Hello);
    std::memcpy(buffer.data() + 1, &clientId, sizeof(clientId));
    return buffer;
}
