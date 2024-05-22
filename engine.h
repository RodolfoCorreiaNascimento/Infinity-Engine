#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <SDL_image.h>

class Engine {
public:
    Engine();
    ~Engine();
    int Init();
    int LoadAssets();
    void Input(bool& game_running);
    void Render();
    void SetDelay(unsigned int time);
    void SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 _alpha);
    void DrawLine(Uint32 x1, Uint32 x2, Uint32 y1, Uint32 y2);

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;
    SDL_Texture* getTexture() const;

    void setWindow(SDL_Window* window);
    void setRenderer(SDL_Renderer* renderer);
    void setTexture(SDL_Texture* texture);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture; // Adicionar a textura aqui
};

#endif
