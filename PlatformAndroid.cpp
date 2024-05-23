#include "PlatformAndroid.h"
#include <iostream>

PlatformAndroid::PlatformAndroid() : window(nullptr), renderer(nullptr), texture(nullptr){}
PlatformAndroid::~PlatformAndroid(){}

int PlatformAndroid::Init() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
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

void PlatformAndroid::Input(bool& game_running) {
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

void PlatformAndroid::Render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    // Renderizar sua textura carregada
    
    SDL_Rect dstRect = {x, y, 640, 480}; // Posição e dimensões da textura na janela
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_RenderPresent(renderer);
}

void PlatformAndroid::LoadAssets() {
    // Carregar imagens aqui
    SDL_Surface* surface = IMG_Load("C://Users//RudeB//Documents//Infinity Engine//logo.png");
    if (!surface) {
        std::cerr << "Falha ao carregar imagem: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Armazenar a textura carregada, você pode ter um vetor, mapa ou outra estrutura de dados para armazenar várias texturas
    // Aqui, vou armazená-la em uma variável membro da classe para fins de exemplo
    // No entanto, é melhor criar uma estrutura de dados adequada para armazenar várias texturas
    // Exemplo: std::map<std::string, SDL_Texture*> textures;
    this->texture = texture;
}

void PlatformAndroid::UpdateX(int value) {
    x += value;
}

void PlatformAndroid::UpdateY(int value) {
    y += value;
}

void PlatformAndroid::Initialize() 
{

}

void PlatformAndroid::HandleEvents()
{

}

void PlatformAndroid::Shutdown()
{
    
}

SDL_Window *PlatformAndroid::getWindow() const
{
    return window;
}

SDL_Renderer *PlatformAndroid::getRenderer() const
{
    return renderer;
}

void PlatformAndroid::setWindow(SDL_Window *window)
{
    if (this->window)
    {
        SDL_DestroyWindow(this->window);
    }
    this->window = window;
}

void PlatformAndroid::setRenderer(SDL_Renderer *renderer)
{
    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
    }
    this->renderer = renderer;
}
