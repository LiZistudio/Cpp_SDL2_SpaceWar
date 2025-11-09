#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Game.h"
#include "SceneMain.h"

int main(int, char**) {

    Game* game = new Game();
    game->init();
    game->changeScene(new SceneMain());
    game->run();
    game->clean();
    delete game;

    return 0;
}
