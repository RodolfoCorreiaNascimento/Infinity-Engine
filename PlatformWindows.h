#ifndef PLATFORM_WINDOWS_H
#define PLATFORM_WINDOWS_H

#include <SDL.h>
#include <SDL_image.h>
#include "Platform.h"
#include "GraphicsManager.h"

namespace Engine
{
    class PlatformWindows : Platform
    {
    public:
        PlatformWindows();
        ~PlatformWindows();
        int Init() override;
        void HandleEvents(bool &game_running) override;
        void Render() override;
        void Shutdown() override;
        void PlaySound(const std::string &sound_file) override;
        void PauseSound() override;
        void StopSound() override;
        bool IsSupportedImageFile(const std::string &filename) override;

        SDL_Window *getWindow() const;
        SDL_Renderer *getRenderer() const;

        void setWindow(SDL_Window *window);
        void setRenderer(SDL_Renderer *renderer);

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;

        SDL_AudioSpec audio_spec;
        SDL_AudioDeviceID audio_device;
    };
}

#endif