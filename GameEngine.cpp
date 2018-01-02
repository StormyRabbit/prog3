//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include "GameEngine.h"
#include "System.h"

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
        preLoopProcess();
        while (running) {
            handleNextLvl();
            capTimer->start();
            SDL_RenderClear(sys.getRenderer());
            activeWorld->drawWorld();
            hud->draw();
            activeWorld->updateWorld();
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if(event.type) {
                        usrInMgr->handleEvent(event);
                    switch (event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    default:
                        activeWorld->executeEvent(event); // TODO: gör denna något efter usrInMgr är fixad ?
                    } // switch end
                }
            } // while Poll

            // pause if tick timer not completed
            pauseTickDur();
            SDL_RenderPresent(sys.getRenderer());

        } // while running
    }

    void GameEngine::setPlayer(PhysicsSprite *player) {
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

    void GameEngine::startFPSTimers() {
        fpsTimer = Timer::getInstance();
        capTimer = Timer::getInstance();
    }

    void GameEngine::pauseTickDur() {
        Uint32 frameTicks = capTimer->getTicks();
        if( frameTicks < tickRate)
            SDL_Delay( tickRate - frameTicks);
    }

    void GameEngine::runStartUpChecks() {
        if(usrInMgr == nullptr) {
        }

        if(activeWorld == nullptr) {
        }

        if(hud == nullptr) {
        }

        if(lvlMgr == nullptr) {
        }

    }

    void GameEngine::preLoopProcess() {
        runStartUpChecks();
        handleNextLvl();
        startFPSTimers();
        fpsTimer->start();
    }

    int GameEngine::getLives() {
        return lives;
    }
}
