#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include <SDL.h>

class Game {
public:
    Game();
    ~Game();
    void run();
    void init();
    void clean();
    void changeScene(Scene* scene);
private:
    bool isRunning = true; // game loop
    Scene* currentScene = nullptr; // current scene
};

#endif // GAME_H
