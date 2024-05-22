#include "game.h"

Game::Game(Engine& engine) : engine(engine) {} // Inicializa a referência ao objeto Engine

void Game::Start() {
    // Implementação da inicialização do jogo pelo usuário 
    engine.LoadAssets();
}

void Game::Update() {
    // Implementação da atualização do jogo pelo usuário 
}
