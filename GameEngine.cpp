//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "GameEngine.h"
#include "System.h"
#include "Player.h"

namespace rootengine {
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
        SDL_Texture *bgImg;
        std::string IMG_PATH;
        IMG_PATH = "assets/sprites/sample.pngs";
        bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());

        SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
        Sprite* player = Player::getInstance(100,100,70,70);
        player->draw();

        while (running) {


            SDL_RenderPresent(sys.getRenderer());
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
                } // switch end
            } // while Poll
        } // while running
    }

    void GameEngine::drawTextures() {

    }
}
/* ObserverPattern */



