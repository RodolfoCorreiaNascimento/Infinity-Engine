#include "engine.h"
#include "game.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Engine engine;
    Game game(engine);

    engine.Init();
    game.Start();

    bool game_running = true;
    while (game_running)
    {
        // Atualiza o estado dos inputs
        engine.Input(game_running);

        // Atualiza o estado do jogo
        game.Update();

        // Renderiza o estado atual do jogo na tela
        engine.Render();
    }

    SDL_DestroyRenderer(engine.getRenderer());
    SDL_DestroyWindow(engine.getWindow());
    SDL_Quit();

    return 0;
}
