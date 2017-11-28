//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "GameEngine.h"

//Test med sprite EJ final
void GameEngine::addSprite() {

}


GameEngine::~GameEngine() {

}

void GameEngine::addLevelCollection() {
    // TODO
}

void GameEngine::addHUDCollection() {
    // TODO
}


void GameEngine::run() {
    SDL_Delay(4000);
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_END)
                        running = true;
                    break;
            } // switch ennd
        } // while Poll
    } // while running}
}

void GameEngine::drawTextures() {

}


/* ObserverPattern */



