#ifndef PLATFORMWINDOWS_H
#define PLATFORMWINDOWS_H
#include "Platform.h"
#include <SDL.h>
#include <SDL_image.h>

class PlatformWindows : Platform
{
public:
    PlatformWindows();
    ~PlatformWindows();
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

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    int x;
    int y;
};

#endif