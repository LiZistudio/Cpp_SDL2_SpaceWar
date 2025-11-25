#include "SceneMain.h"
#include "Game.h"

#include <SDL_image.h>

SceneMain::SceneMain() : game(Game::getInstance()) {}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
    player.texture = IMG_LoadTexture(game.getRenderer(), "assets\\image\\SpaceShip.png");
    SDL_QueryTexture(player.texture, nullptr, nullptr, &player.width, &player.height);
    player.width /= 4; //缩小为原来的1/4
    player.height /= 4;

    player.position.x = static_cast<float>((game.getWindowWidth() - player.width) / 2.0f);
    player.position.y = static_cast<float>(game.getWindowHeight() - player.height);
}

 void SceneMain::handleEvent(SDL_Event* event)
{
    
}

void SceneMain::update(float deltaTime)
{
    keyboardControl(deltaTime);
}

void SceneMain::render()
{
    SDL_Rect playerRect = {
        static_cast<int>(player.position.x),
        static_cast<int>(player.position.y),
        player.width,
        player.height
    };
    SDL_RenderCopy(game.getRenderer(), player.texture, nullptr, &playerRect);
}

void SceneMain::clean()
{
    if (player.texture != nullptr) {
        SDL_DestroyTexture(player.texture);
        player.texture = nullptr;
    }
}

void SceneMain::keyboardControl(float deltaTime)
{
    //键盘控制
    auto keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_W]) {
        player.position.y -= deltaTime * player.speed;
    }
    if (keyboardState[SDL_SCANCODE_S]) {
        player.position.y += deltaTime * player.speed;
    }
    if (keyboardState[SDL_SCANCODE_A]) {
        player.position.x -= deltaTime * player.speed;
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        player.position.x += deltaTime  * player.speed;
    }

    //边界检测
    if (player.position.x < 0) {
        player.position.x = 0;
    }
    if (player.position.x > game.getWindowWidth() - player.width) {
        player.position.x = game.getWindowWidth() - player.width;
    }
    if (player.position.y < 0) {
        player.position.y = 0;
    }
    if (player.position.y > game.getWindowHeight() - player.height) {
        player.position.y = game.getWindowHeight() - player.height;
    }
}
