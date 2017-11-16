//
// Created by lasse on 11/16/17.
//

#include <SDL_image.h>
#include <iostream>
#include <string>
#include "GameEngine.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[]) {
    sdlInit();
    SDL_Window* win = createWindow();
    SDL_Renderer* ren = createRender(win);
    
    SDL_Quit();
    return 0;
}

SDL_Renderer* createRender(SDL_Window *win) {
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cerr << "Fel: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(-1);
    }
    return renderer;
}


SDL_Window* createWindow() {
    SDL_Window* win = SDL_CreateWindow("fönster",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(win == nullptr) {
        std::cerr << "Fel: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }
    else
        return win;
}

void sdlInit() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "SDL_init-fel" << SDL_GetError() << std::endl;
        exit(-1);
    }
}

