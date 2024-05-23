#ifndef PLATFORM_ANDROID_H
#define PLATFORM_ANDROID_H
#include "Platform.h"
#include <SDL.h>
#include <SDL_image.h>

class PlatformAndroid : Platform
{
public:
    PlatformAndroid();
    ~PlatformAndroid();
    void LoadAssets() override;
    int Init() override;
    void Initialize() override;
    void Input(bool &game_running) override;
    void HandleEvents() override;
    void Render() override;
    void Shutdown() override;
    void UpdateX(int value) override;
    void UpdateY(int value) override;

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;

    void setWindow(SDL_Window *window);
    void setRenderer(SDL_Renderer *renderer);

    int x = 0;
    int y = 0;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};

#endif