//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "GameEngine.h"

void GameEngine::initiateSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "SDL_init-fel" << SDL_GetError() << std::endl;
        exit(-1);
    }
    int imgFlags = IMG_INIT_PNG;
    if(!( IMG_Init( imgFlags ) & imgFlags) ) {
        std::cerr << "SDL_imig_init-fel:" << SDL_GetError() << std::endl;
    }
}

SDL_Window *GameEngine::createWindow(int width, int height) {
    SDL_Window* win = SDL_CreateWindow("fönster",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       width, height, SDL_WINDOW_SHOWN);
    if(win == nullptr) {
        std::cerr << "window error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }
    else
        return win;
}

SDL_Renderer *GameEngine::createRenderer(SDL_Window *win) {
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cerr << "render error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(-1);
    }
    return renderer;
}

SDL_Surface *GameEngine::createSurface(std::string path, SDL_Window* win) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if(loadedSurface == NULL) {
        std::cerr << "surface rror: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }
    SDL_Surface *surface = SDL_GetWindowSurface(win);
    optimizedSurface = SDL_ConvertSurface( loadedSurface, surface->format, NULL );
    if(optimizedSurface == NULL) {
        std::cerr << "surface error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }
    SDL_FreeSurface(loadedSurface);
    return optimizedSurface;
}

void GameEngine::startLoop() {
    while(running) {
        std::cout << "running...";
    }
    std::cout << "running ended..";
}


/* ObserverPattern */



