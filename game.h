#ifndef GAME_H
#define GAME_H

#include "PlatformWindows.h"

class Game {
public:
    Game(PlatformWindows& platformWindows); // Construtor recebe uma referência para Engine
    void Start();
    void Update();

private:
    PlatformWindows& platformWindows; // Membro para armazenar a referência para Engine
};

#endif
