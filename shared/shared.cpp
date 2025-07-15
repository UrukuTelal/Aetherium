#include "shared.h"
#include <iostream>
#include <chrono>
#include <ctime>

namespace Shared {

    void log(const std::string& message) {
        using namespace std::chrono;
        auto now = system_clock::now();
        std::time_t now_time = system_clock::to_time_t(now);
        std::cout << "[LOG " << std::ctime(&now_time) << "]: " << message << std::endl;
    }

} // namespace Shared
