#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game {
public:
    Game();
    ~Game();
    void run();
    void init();
    void clean();
    void changeScene(Scene* scene);

    void update();
    void render();
    void handleEvent(SDL_Event* event);
private:
    bool isRunning = true; // game loop
    Scene* currentScene = nullptr; // current scene
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int windowWidth = 600;
    int windowHeight = 800;
};

#endif // GAME_H
