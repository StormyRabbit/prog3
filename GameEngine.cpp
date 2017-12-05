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
        Player* player = Player::getInstance(100,450,50,50);
        activeWorld->setPlayer(player);
        std::string IMG_PATH = "assets/sprites/i-know-c.jpg";
        SDL_Texture *bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());
        SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);

        Sprite* bottom = EnvironmentSprite::getInstance(0, 500, 600, 100, "assets/sprites/Tiles/grassMid.png");
        int i = 0;

        while (running) {
            SDL_RenderClear(sys.getRenderer());
            SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
            hud->draw();
            player->draw();
            bottom->draw();
            SDL_RenderPresent(sys.getRenderer());
            SDL_Event event;
            player->checkState();

            while (SDL_PollEvent(&event)) {
                if(event.type)
                    switch (event.type) {
                        case SDL_QUIT:
                            running = false;
                            break;
                        default: // OM SPELAREVENT
                            activeWorld->executeEvent(event);
                    } // switch end
            } // while Poll
        } // while running
    }

    void GameEngine::drawTextures() {

    }


}
/* ObserverPattern */



