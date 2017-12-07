//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "GameEngine.h"
#include "System.h"

namespace rootengine {

    GameEngine::~GameEngine() {
        delete player;
        delete activeWorld;
        delete lvlMgr;
        delete hud;
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
        SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
        Sprite* bottom = EnvironmentSprite::getInstance(0, 500, 600, 100, "assets/sprites/Tiles/grassMid.png");
        while (running) {
            SDL_RenderClear(sys.getRenderer());
            SDL_RenderCopy(sys.getRenderer(), bgImg, NULL, NULL);
            activeWorld->drawWorld();
            hud->draw();
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
    void GameEngine::setPlayer(Player *player) {
        GameEngine::player = player; // TODO: remove när world->draw är implementerat
        activeWorld->setPlayer(player);
    }

    GameEngine *GameEngine::getInstance() {
        return new GameEngine();
    }

    void GameEngine::createWorld() {
        activeWorld = World::getInstance();
    }
}
/* ObserverPattern */



