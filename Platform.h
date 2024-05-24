// Platform.h
#ifndef PLATFORM_H
#define PLATFORM_H
#include <string>

class Platform
{
public:
    virtual void Initialize() = 0;
    virtual void HandleEvents(bool &game_running) = 0;
    virtual int Init() = 0;
    virtual void Render() = 0;
    virtual void Shutdown() = 0;
    virtual void LoadAssets() = 0;
    virtual void PlaySound(const std::string& sound_file) = 0;
    virtual void PauseSound() = 0;
    virtual void StopSound() = 0;
};

#endif // PLATFORM_H
