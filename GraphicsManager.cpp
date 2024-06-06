#include "GraphicsManager.h"
using namespace Engine;

GraphicsManager::GraphicsManager(/* args */){}

GraphicsManager::~GraphicsManager(){}

SDL_Texture *GraphicsManager::LoadResources(char img[], SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(img);
    if (!surface)
    {
        std::cerr << "Falha ao carregar imagem: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        std::cerr << "Falha ao criar textura: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}

