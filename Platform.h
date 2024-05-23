// Platform.h
#ifndef PLATFORM_H
#define PLATFORM_H

class Platform
{
public:
    virtual void Initialize() = 0;
    virtual void HandleEvents() = 0;
    virtual void Input(bool &game_running) = 0;
    virtual int Init() = 0;
    virtual void Render() = 0;
    virtual void Shutdown() = 0;
    virtual void LoadAssets() = 0;

    virtual void UpdateX(int value) = 0;
    virtual void UpdateY(int value) = 0;
};

#endif // PLATFORM_H
