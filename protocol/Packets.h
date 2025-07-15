#pragma once

#include <cstdint>

enum class PacketType : uint8_t {
    Hello,
    WorldState
};

struct HelloPacket {
    uint32_t clientId;
};

struct WorldStatePacket {
    float time;
};
