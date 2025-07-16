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
