#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace Engine
{
    class GraphicsManager
    {
    private:
        /* data */
        

    public:
        GraphicsManager(/* args */);
        ~GraphicsManager();
        SDL_Texture* LoadResources(char [], SDL_Renderer *renderer);
        
    };
}

#endif