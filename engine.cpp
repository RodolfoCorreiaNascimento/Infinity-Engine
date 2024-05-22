#include "engine.h"
#include <iostream>

Engine::Engine() : window(nullptr), renderer(nullptr) {}
Engine::~Engine(){}

int Engine::Init() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Infinity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
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

    return 0;
}

void Engine::Input(bool& game_running) {
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

void Engine::Render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Engine::SetDelay(unsigned int time)
{
    SDL_Delay(time);
}

void Engine::SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 _alpha)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, _alpha);
}

void Engine::DrawLine(Uint32 x1, Uint32 x2, Uint32 y1, Uint32 y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

SDL_Window *Engine::getWindow() const
{
    return window;
}

SDL_Renderer *Engine::getRenderer() const
{
    return renderer;
}

void Engine::setWindow(SDL_Window *window)
{
    if (this->window)
    {
        SDL_DestroyWindow(this->window);
    }
    this->window = window;
}

void Engine::setRenderer(SDL_Renderer *renderer)
{
    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
    }
    this->renderer = renderer;
}
