#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "Scene.h"
#include "Object.h"
#include <list>

class Game;

 class SceneMain : public Scene {
public:
    SceneMain();
    ~SceneMain();

    void init() override;
    void handleEvent(SDL_Event* event) override;
    void update(float deltaTime) override;
    void render() override;
    void clean() override;

    void keyboardControl(float deltaTime);
private:
    Game& game;
    Player player;
    std::list<Bullet> bullets; //子弹列表
 };
#endif // SCENEMAIN_H
