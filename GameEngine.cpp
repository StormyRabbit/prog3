//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include "GameEngine.h"

GameEngine::running = true;


void GameEngine::initiateGameEngine() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "SDL_init-fel" << SDL_GetError() << std::endl;
        exit(-1);
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

SDL_Renderer *GameEngine::createREnderer(SDL_Window *win) {
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cerr << "render error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(-1);
    }
    return renderer;
}

SDL_Surface *GameEngine::createSurface() {
    SDL_Surface *surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, rmask, gmask, bmask, amask );
    if(surface == nullptr)
        std::cerr << "surface error:" << SDL_GetError() << std::endl;
    return nullptr;
}

void GameEngine::startLoop() {
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type) {

            }
        }
    }
}


/*
 * Subject implementation
 */

void Subject::addObserver(Observer *o) {
    Subject::observers.push_back(o);
}

void Subject::pushUpdate(Subject *s) {
    for(Observer* obs : observers)
        obs->update(*this);
}

void Subject::getAmmo() {

}

void Subject::getLife() {

}

void Subject::getScore() {

}




