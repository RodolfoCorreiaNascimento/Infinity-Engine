#include "PlatformWindows.h"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "GraphicsManager.h"

using namespace Engine;

PlatformWindows::PlatformWindows() 
    : window(nullptr), renderer(nullptr), texture(nullptr), audio_device(0) {}

PlatformWindows::~PlatformWindows() {
    Shutdown();
}

int PlatformWindows::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Infinity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Surface* iconSurface = IMG_Load("C://Users//RudeB//Documents//Infinity Engine//resources//images//InfinityEngine.png");
    if (!iconSurface) {
        std::cerr << "Unable to load icon image! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetWindowIcon(window, iconSurface);
    SDL_FreeSurface(iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erro ao criar renderizador: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }

    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if ((IMG_Init(flags) & flags) != flags) {
        std::cerr << "Falha ao inicializar SDL_image: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return 1;
    }
    
    char imagePath[] = "C://Users//RudeB//Documents//Infinity Engine//resources//images//RemainOnEarth.gif";

    GraphicsManager* graphicsManager = new GraphicsManager();
    texture = graphicsManager->LoadResources(imagePath, renderer);
    
    return 0;
}

void PlatformWindows::HandleEvents(bool &game_running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            game_running = false;
        } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            game_running = false;
        }
    }
}

void PlatformWindows::Render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    SDL_Rect dstRect = {0, 0, 640, 480};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_RenderPresent(renderer);
}

bool PlatformWindows::IsSupportedImageFile(const std::string& filename) {
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    return (extension == "bmp" || extension == "gif" || extension == "jpg" || extension == "jpeg" || extension == "png");
}

void PlatformWindows::PlaySound(const std::string& sound_file) {
    SDL_AudioSpec spec;
    Uint8 *audio_buf;
    Uint32 audio_len;

    if (SDL_LoadWAV(sound_file.c_str(), &spec, &audio_buf, &audio_len) == nullptr) {
        std::cerr << "Falha ao carregar arquivo de áudio: " << SDL_GetError() << std::endl;
        return;
    }

    audio_device = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
    if (audio_device == 0) {
        std::cerr << "Falha ao abrir dispositivo de áudio: " << SDL_GetError() << std::endl;
        SDL_FreeWAV(audio_buf);
        return;
    }

    SDL_QueueAudio(audio_device, audio_buf, audio_len);
    SDL_PauseAudioDevice(audio_device, 0);

    SDL_FreeWAV(audio_buf);
}

void PlatformWindows::PauseSound() {
    if (audio_device != 0) {
        SDL_PauseAudioDevice(audio_device, 1);
    }
}

void PlatformWindows::StopSound() {
    if (audio_device != 0) {
        SDL_ClearQueuedAudio(audio_device);
        SDL_CloseAudioDevice(audio_device);
        audio_device = 0;
    }
}

void PlatformWindows::Shutdown() {
    if (audio_device != 0) {
        SDL_CloseAudioDevice(audio_device);
    }
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    IMG_Quit();
    SDL_Quit();
}

SDL_Window* PlatformWindows::getWindow() const {
    return window;
}

SDL_Renderer* PlatformWindows::getRenderer() const {
    return renderer;
}

void PlatformWindows::setWindow(SDL_Window *window) {
    if (this->window) {
        SDL_DestroyWindow(this->window);
    }
    this->window = window;
}

void PlatformWindows::setRenderer(SDL_Renderer *renderer) {
    if (this->renderer) {
        SDL_DestroyRenderer(this->renderer);
    }
    this->renderer = renderer;
}
