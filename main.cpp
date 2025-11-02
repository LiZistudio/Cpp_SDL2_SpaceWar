#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

int main(int, char**) {
    // 初始化SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //创建窗口
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                                  SDL_WINDOWPOS_CENTERED,
                                                  SDL_WINDOWPOS_CENTERED,
                                                  800, 600,
                                                  SDL_WINDOW_SHOWN);

    //创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //初始化图片加载器
    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) != (IMG_INIT_PNG|IMG_INIT_JPG)) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return 1;
    }

    //创建贴图
    SDL_Texture* texture = IMG_LoadTexture(renderer, "assets/image/bg.png");
    if (!texture) {
        std::cerr << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
        return 1;
    }

    //初始化音频混合器
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        return 1;
    }
    //加载音乐文件
    Mix_Music *bgm = Mix_LoadMUS("assets/music/03_Racing_Through_Asteroids_Loop.ogg");
    if (!bgm) {
        std::cerr << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
        return 1;
    }
    //播放背景音乐
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(bgm, -1); //循环播放
    }

    //初始化字体库
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return 1;
    }
    //加载字体
    TTF_Font* font = TTF_OpenFont("assets/font/VonwaonBitmap-16px.ttf", 24);
    //创建文本纹理
    SDL_Color textColor = {255, 255, 255, 255}; //白色
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, "Hello, SDL2!", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    //渲染循环
    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
        }

        //清屏
        SDL_RenderClear(renderer);
        //画一个正方形
        SDL_Rect rectangle = { 350, 200, 100, 100 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //红色
        SDL_RenderDrawRect(renderer, &rectangle);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //黑色背景

        //绘制贴图
        SDL_Rect dstRect = {450, 300, 800, 600};
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        //绘制文本
        SDL_Rect textRect = {50, 50, textSurface->w, textSurface->h};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        //更新屏幕
        SDL_RenderPresent(renderer);

        
    }
    

    //释放音乐
    Mix_FreeMusic(bgm);
    //关闭音频混合器
    Mix_CloseAudio();
    //退出音频混合器
    Mix_Quit();

    //清空贴图
    SDL_DestroyTexture(texture);
    //退出图片加载器
    IMG_Quit();

    //释放文本纹理和字体
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    //退出字体库
    TTF_Quit();

    //释放渲染器
    SDL_DestroyRenderer(renderer);
    //销毁窗口
    SDL_DestroyWindow(window);
    //退出SDL
    SDL_Quit();

    return 0;
}
