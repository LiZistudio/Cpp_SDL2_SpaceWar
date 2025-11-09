#include "SceneMain.h"

void SceneMain::init()
{
    mainWindow = SDL_CreateWindow("PlaneWar",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  800,
                                  600,
                                  SDL_WINDOW_SHOWN);
    rect = { 50, 50, 200, 150 };
}

 void SceneMain::handleEvent(SDL_Event* event)
{
    event->type; // suppress unused parameter warning
}

void SceneMain::update()
{
    SDL_RenderDrawRect(renderer, &rect);
}

void SceneMain::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SceneMain::clean()
{
}
