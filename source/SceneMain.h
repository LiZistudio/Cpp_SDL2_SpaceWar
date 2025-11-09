#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "Scene.h"

 class SceneMain : public Scene {
public:
    SceneMain();
    ~SceneMain();

    void init() override;
    void handleEvent(SDL_Event* event) override;
    void update() override;
    void render() override;
    void clean() override;
private:
    SDL_Window* mainWindow = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Rect rect;
};

#endif // SCENEMAIN_H