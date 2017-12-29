//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include "GameEngine.h"
#include "System.h"
#include "util/Timer.h"

namespace rootengine {

    GameEngine::~GameEngine() {
        delete activeWorld;
        delete lvlMgr;
        delete hud;
        delete usrInMgr;
    }

    void GameEngine::setLvlMgr(LevelManager *lvlMgr) {
        GameEngine::lvlMgr = lvlMgr;
    }

    void GameEngine::setHUD(HUD *hud) {
        GameEngine::hud = hud;
    }
    void GameEngine::handleNextLvl() {
        if(activeWorld->readyForNextLvl()) {
            Level* nextLvl = lvlMgr->getNextLevel();
            if(nextLvl != nullptr)
                activeWorld->setLevel(nextLvl);
            else
                endGame();
        }
    }
    void GameEngine::run() {
        handleNextLvl();
        Timer *fpsTimer = Timer::getInstance();
        Timer *capTimer = Timer::getInstance();
        fpsTimer->start();
        while (running) {
            handleNextLvl();
            capTimer->start();
            SDL_RenderClear(sys.getRenderer());
            activeWorld->drawWorld();
            hud->draw();
            SDL_Event event;
            activeWorld->updateWorld();
            while (SDL_PollEvent(&event)) {
                if(event.type) {
                    SDL_KeyboardEvent keyEvent = event.key;
                    SDL_Keysym keysym = keyEvent.keysym;
                    if (keysym.sym == SDLK_h) {
                        Level *nxtLvl = lvlMgr->getNextLevel();
                        if(nxtLvl != nullptr)
                            activeWorld->setLevel(nxtLvl);
                    }
                    if(usrInMgr != nullptr)
                        usrInMgr->handleEvent(event);
                    switch (event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    default:
                        activeWorld->executeEvent(event);
                } // switch end
                }
            } // while Poll
            Uint32 frameTicks = capTimer->getTicks();
            if( frameTicks < tickRate)
                SDL_Delay( tickRate - frameTicks);

            SDL_RenderPresent(sys.getRenderer());

        } // while running
    }

    void GameEngine::setPlayer(Player *player) {
        activeWorld->setPlayer(player);
    }

    GameEngine *GameEngine::getInstance() {
        return new GameEngine();
    }

    void GameEngine::createWorld() {
        activeWorld = World::getInstance();
    }

    void GameEngine::setFPS(int fps) {
        tickRate = 1000 / fps;
    }

    int GameEngine::getScore() {
        return score;
    }

    void GameEngine::endGame() {
        // TODO
    }

    void GameEngine::setUsrInMgr(UserInputMgr *uim) {
        usrInMgr = uim;
    }
}
