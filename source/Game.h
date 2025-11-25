#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game {
public:
    static Game& getInstance() {
        static Game instance;
        return instance;
    };
    SDL_Renderer* getRenderer() { return renderer; }
    SDL_Window* getWindow() { return window; }
    int getWindowWidth() { return windowWidth; }
    int getWindowHeight() { return windowHeight; }

    Scene* getCurrentScene() { return currentScene; }

    ~Game();
    void run();
    void init();
    void clean();
    void changeScene(Scene* scene);

    void update();
    void render();
    void handleEvent(SDL_Event* event);
private:
     Game(); // singleton
     //删除拷贝与赋值构造函数
     Game(const Game&) = delete;
     Game& operator= (const Game&) = delete;
private:
    bool isRunning = true; // game loop
    Scene* currentScene = nullptr; // current scene
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int windowWidth = 600;
    int windowHeight = 800;

    Uint32 frameTime = 0; // frame time
    float deltaTime = 0.0f; // delta time
    int FPS = 60;
};

#endif // GAME_H
