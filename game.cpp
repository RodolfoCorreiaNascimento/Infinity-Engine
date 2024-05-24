// game.cpp
#include "game.h"
#include <SDL.h>
Game::Game(PlatformWindows& platformWindows) : platformWindows(platformWindows) {} // Corrigido o nome do parâmetro na inicialização

void Game::Start() {
    // Implementação da inicialização do jogo pelo usuário
    platformWindows.PlaySound("C://Users//RudeB//Documents//Infinity Engine//resources//bgm//BalambGarden.wav");
}

void Game::Update() {
    // Implementação da atualização do jogo pelo usuário 
    
}
