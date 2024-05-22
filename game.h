#ifndef GAME_H
#define GAME_H

#include "engine.h"

class Game {
public:
    Game(Engine& engine); // Construtor recebe uma referência para Engine
    void Start();
    void Update();

private:
    Engine& engine; // Membro para armazenar a referência para Engine
};

#endif
