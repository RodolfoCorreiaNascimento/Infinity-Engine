#include "Platform.h"
#include "game.h"
#include <iostream>
using namespace std;

// Definições de pré-processador para selecionar a plataforma
#if defined(_WIN32) || defined(_WIN64)
#include "PlatformWindows.h"
#define PLATFORM PlatformWindows
#elif defined(__linux__)
#include "PlatformLinux.h"
#define PLATFORM PlatformLinux
#elif defined(_android_)
#include "PlatformAndroid.h"
#define PLATFORM PlatformAndroid
#else
#error "Platform not supported"
#endif

int main(int argc, char *argv[])
{
    PLATFORM platform;
    Game game(platform);

    platform.Init();
    game.Start();

    bool game_running = true;
    while (game_running)
    {
        // Atualiza o estado dos inputs
        platform.Input(game_running);

        // Atualiza o estado do jogo
        game.Update();

        // Renderiza o estado atual do jogo na tela
        platform.Render();
    }

    SDL_DestroyRenderer(platform.getRenderer());
    SDL_DestroyWindow(platform.getWindow());
    IMG_Quit();
    SDL_Quit();

    return 0;
}
