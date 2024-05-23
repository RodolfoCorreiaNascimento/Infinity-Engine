#include "PlatformWindows.h"
#include <iostream>

PlatformWindows::PlatformWindows() : window(nullptr), renderer(nullptr), texture(nullptr) {}

PlatformWindows::~PlatformWindows() {}

int PlatformWindows::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Infinity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erro ao criar renderizador: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }

    int flags = (IMG_INIT_PNG | IMG_INIT_JPG);
    if (IMG_Init(flags) != flags) {
        std::cerr << "Falha ao inicializar SDL_image: " << IMG_GetError() << std::endl;
        return 1;
    }

    LoadAssets();

    return 0;
}

void PlatformWindows::Input(bool &game_running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            game_running = false;
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                game_running = false;
            }
        }
    }
}

void PlatformWindows::Render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    // Renderizar sua textura carregada
    
    SDL_Rect dstRect = {0, 0, 640, 480}; // Posição e dimensões da textura na janela
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_RenderPresent(renderer);
}

void PlatformWindows::LoadAssets() {
    // Carregar imagens aqui
    SDL_Surface* surface = IMG_Load("C://Users//RudeB//Documents//Infinity Engine//logo.png");
    if (!surface) {
        std::cerr << "Falha ao carregar imagem: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Armazenar a textura carregada
    texture = tex;
}

void PlatformWindows::UpdateX(int value) {
    x += value;
}

void PlatformWindows::UpdateY(int value) {
    y += value;
}

void PlatformWindows::HandleEvents(){}

void PlatformWindows::Shutdown(){}

void PlatformWindows::Initialize(){}

SDL_Window *PlatformWindows::getWindow() const {
    return window;
}

SDL_Renderer *PlatformWindows::getRenderer() const {
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
