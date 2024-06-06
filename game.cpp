// game.cpp
#include "game.h"
#include <SDL.h>

Engine::Game::Game(PlatformWindows& platformWindows) : platformWindows(platformWindows) {} // Corrigido o nome do parâmetro na inicialização

void Engine::Game::Start() {
    // Implementação da inicialização do jogo pelo usuário
    const std::string& file = "C://Users//RudeB//Documents//Infinity Engine//resources//bgm//BalambGarden.wav";
    platformWindows.PlaySound(file);
}

void Engine::Game::Update() {
    // Implementação da atualização do jogo pelo usuário 
    
}
