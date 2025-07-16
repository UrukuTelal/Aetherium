// linux_platform.cpp
#include "linux_platform.h"
#include <cstdio>

class LinuxPlatform : public PlatformAPI {
public:
    void Init() override {
        // TODO: Choose backend (GLFW, SDL2, raw X11)
        printf("LinuxPlatform::Init()\n");
    }

    void PollEvents() override {
        // TODO: Poll system events using your chosen backend
        printf("LinuxPlatform::PollEvents()\n");
    }

    void PresentFrame() override {
        // TODO: Implement framebuffer swap
        printf("LinuxPlatform::PresentFrame()\n");
    }

    int GetScreenWidth() override {
        // TODO: Query screen resolution
        return 1920;
    }

    int GetScreenHeight() override {
        // TODO: Query screen resolution
        return 1080;
    }
};
