// android_platform.cpp
#include "android_platform.h"
#include <cstdio>

class AndroidPlatform : public PlatformAPI {
public:
    void Init() override {
        // TODO: Implement Android-specific initialization (via JNI bridge later)
        printf("AndroidPlatform::Init()\n");
    }

    void PollEvents() override {
        // TODO: Integrate with looper/event queue (via JNI or native glue)
        printf("AndroidPlatform::PollEvents()\n");
    }

    void PresentFrame() override {
        // TODO: Swap buffers using EGL when rendering is added
        printf("AndroidPlatform::PresentFrame()\n");
    }

    int GetScreenWidth() override {
        // TODO: Query actual device screen dimensions
        return 1280;
    }

    int GetScreenHeight() override {
        // TODO: Query actual device screen dimensions
        return 720;
    }
};
