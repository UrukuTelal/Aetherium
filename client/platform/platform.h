// platform.h
#pragma once

struct PlatformAPI {
    virtual void Init() = 0;
    virtual void PollEvents() = 0;
    virtual void PresentFrame() = 0;
    virtual int GetScreenWidth() = 0;
    virtual int GetScreenHeight() = 0;
    virtual ~PlatformAPI() = default;
};

PlatformAPI* CreatePlatform();

// platform.cpp
#include "platform.h"

#if defined(_WIN32)
#include "windows/windows_platform.h"
PlatformAPI* CreatePlatform() { return new WindowsPlatform(); }
#elif defined(__linux__)
#include "linux/linux_platform.h"
PlatformAPI* CreatePlatform() { return new LinuxPlatform(); }
#elif defined(__ANDROID__)
#include "android/android_platform.h"
PlatformAPI* CreatePlatform() { return new AndroidPlatform(); }
#else
#error "Unsupported platform"
#endif

// windows/windows_platform.cpp
#include "windows/windows_platform.h"
#include <windows.h>

class WindowsPlatform : public PlatformAPI {
public:
    void Init() override {
        // Initialize window and OpenGL/Vulkan context here
    }
    void PollEvents() override {
        // Handle Windows messages
    }
    void PresentFrame() override {
        // Swap buffers
    }
    int GetScreenWidth() override { return 1920; }
    int GetScreenHeight() override { return 1080; }
};

// linux/linux_platform.cpp
#include "linux/linux_platform.h"
// NOTE: This requires X11 development libraries; placeholder only
// #include <X11/Xlib.h>

class LinuxPlatform : public PlatformAPI {
public:
    void Init() override {
        // Init X11 or use SDL/GLFW
    }
    void PollEvents() override {
        // Handle X11 events
    }
    void PresentFrame() override {
        // Swap buffers
    }
    int GetScreenWidth() override { return 1920; }
    int GetScreenHeight() override { return 1080; }
};

// android/android_platform.cpp
#include "platform\android\android_platform.h"
// NOTE: This requires Android NDK; placeholder only
// #include <android/native_window.h>

class AndroidPlatform : public PlatformAPI {
public:
    void Init() override {
        // Hook into Java via JNI
    }
    void PollEvents() override {
        // Android event loop / looper
    }
    void PresentFrame() override {
        // EGL swap
    }
    int GetScreenWidth() override { return 1280; }
    int GetScreenHeight() override { return 720; }
};
