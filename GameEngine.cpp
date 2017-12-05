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
#include "EnvironmentSprite.h"

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
        activeWorld = World::getInstance();
        std::string IMG_PATH = "assets/sprites/i-know-c.jpg";
        SDL_Texture *bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());
        SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);

        HUDSprite* lasse = HUDSprite::getInstance(200,200,200,20, "GIT GOD LASSE");
        Player* player = Player::getInstance(100,450,50,50);
        Sprite* bottom = EnvironmentSprite::getInstance(0, 500, 600, 100, "assets/sprites/Tiles/grassMid.png");
        int i = 0;

        while (running) {
            SDL_RenderClear(sys.getRenderer());
            SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
            player->draw();
            lasse->draw();
            bottom->draw();
            SDL_RenderPresent(sys.getRenderer());
            SDL_Event event;

            lasse->setText(std::to_string(i));
            player->checkState();

            while (SDL_PollEvent(&event)) {
                if(event.type)
                switch (event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    default:
                        activeWorld->executeEvent(event);

                } // switch end
            } // while Poll
        } // while running
    }

    void GameEngine::drawTextures() {

    }


}
/* ObserverPattern */



