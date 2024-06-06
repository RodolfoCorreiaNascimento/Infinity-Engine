#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>

namespace Engine
{
    class RenderManager
    {
    private:
        /* data */
    public:
        RenderManager(/* args */);
        ~RenderManager();
        void Render();
    };

}

#endif