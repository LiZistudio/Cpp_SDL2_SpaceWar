#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>

typedef struct Player {
    int width = 0;
    int height = 0;
    SDL_Texture* texture = nullptr;
    SDL_FPoint position = {0.0f, 0.0f};
    float speed = 0.5f; //移动速度
}Player;

typedef struct Bullet {
    int width = 0;
    int height = 0;
    SDL_Texture* texture = nullptr;
    SDL_FPoint position = {0.0f, 0.0f};
    float speed = 0.5f; //移动速度
}Bullet;

#endif //OBJECT_H
 