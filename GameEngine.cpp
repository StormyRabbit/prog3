//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
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
        std::string IMG_PATH = "assets/sprites/i-know-c.pg";
        SDL_Texture *bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());
        SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);

        HUDSprite* lasse = HUDSprite::getInstance(200,200,200,200, "GIT GOD LASSE");
        lasse->draw();

        Sprite* player = Player::getInstance(100,100,70,70);


        while (running) {
            SDL_RenderClear(sys.getRenderer());
            SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
            player->draw();
            SDL_RenderPresent(sys.getRenderer());
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_KEYDOWN:
                        player->keyDown(event);
                        break;
                } // switch end
            } // while Poll
        } // while running
    }

    void GameEngine::drawTextures() {

    }


}
/* ObserverPattern */



