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

    void GameEngine::handleNextLvl() {
        activeWorld->setLevel(lvlMgr->getNextLevel());
        /*
        if(activeWorld->readyForNextLvl()) {
            Level* nextLvl = lvlMgr->getNextLevel();
            if(nextLvl != nullptr)
                activeWorld->setLevel(nextLvl);
        }
         */
    }

    void GameEngine::run() {
        preLoopProcess();
        while (running) {
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
                            break;
                    } // switch end
                }
            } // while Poll

            // pause if tick timer not completed
            pauseTickDur();
            SDL_RenderPresent(sys.getRenderer());

        } // while runnin.g
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
        tickRate =  1000 / fps;
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


    void GameEngine::preLoopProcess() {
        handleNextLvl();
        startFPSTimers();
        fpsTimer->start();
    }

    void GameEngine::setHUD(Drawable *h) {
        hud = h;
    }

    GameEngine::GameEngine() {
        this->createWorld();
        usrInMgr = UserInputMgr::getInstance();
    }

    void GameEngine::addEvent(UserInputCallback *uic) {
        usrInMgr->addEvent(uic);
    }

    void GameEngine::addLvl(LevelInterface *lvl) {
        if(lvlMgr == nullptr)
            lvlMgr = LevelManager::getInstance();
        lvlMgr->addLevel(lvl);
    }
}
