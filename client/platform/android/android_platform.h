// android_platform.h
#pragma once
#include "platform.h"

class AndroidPlatform : public PlatformAPI {
public:
    void Init() override;
    void PollEvents() override;
    void PresentFrame() override;
    int GetScreenWidth() override;
    int GetScreenHeight() override;
};
