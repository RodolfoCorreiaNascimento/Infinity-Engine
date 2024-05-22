#ifndef ENGINE_H
#define ENGINE_H
#define SDL_MAIN_HANDLED
#include <SDL.h>

class Engine {
public:
    Engine();
    ~Engine();
    int Init();
    void Input(bool& game_running);
    void Render();
    void SetDelay(unsigned int time);
    void SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 _alpha);
    void DrawLine(Uint32 x1, Uint32 x2, Uint32 y1, Uint32 y2);

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

    void setWindow(SDL_Window* window);
    void setRenderer(SDL_Renderer* renderer);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
