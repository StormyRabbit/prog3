//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <bits/ios_base.h>
#include <ios>
#include "GameEngine.h"
#include "System.h"
#include "Player.h"
#include "HUDSprite.h"

namespace rootengine {
//Test med sprite EJ final
    void GameEngine::addSprite() {

    }

    GameEngine::~GameEngine() {

    }

    void GameEngine::setLvlMgr(LevelManager *lvlMgr) {
        GameEngine::lvlMgr = lvlMgr;
    }

    void GameEngine::setHUD(HUD *hud) {
        GameEngine::hud = hud;
    }


    void GameEngine::run() {
        std::string IMG_PATH = "assets/sprites/bg_castle.png";
        
        SDL_Texture *bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());
        SDL_RenderCopy(sys.getRenderer(), bgImg, nullptr, nullptr);
        HUDSprite* testSprite = HUDSprite::getInstance(100, 100, 250, 250, "test");
        testSprite->draw();
        Sprite* player = Player::getInstance(100,100,70,70);
        player->draw();
        std::cout << IMG_GetError();
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



