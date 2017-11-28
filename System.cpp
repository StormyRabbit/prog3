//
// Created by lasse on 11/28/17.
//

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "System.h"

SDL_Renderer *System::getRenderer() {
    return ren;
}

System::System() {
    System::init();
    System::createWindow(600, 600, "Engine test");
    System::createRenderer();
}

System::~System() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

void System::init() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "SDL_init-fel" << SDL_GetError() << std::endl;
        exit(-1);
    }
    int imgFlags = IMG_INIT_PNG;
    if(!( IMG_Init( imgFlags ) & imgFlags) ) {
        std::cerr << "SDL_imig_init-fel:" << SDL_GetError() << std::endl;
    }

}

void System::createWindow(int width, int height, std::string name) {
    win = SDL_CreateWindow(name.c_str(),
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width, height, SDL_WINDOW_SHOWN);
    if(win == nullptr) {
        std::cerr << "window error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }

}

void System::createRenderer() {
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr) {
        std::cerr << "render error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(-1);
    }
}
System sys;
