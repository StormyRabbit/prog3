//
// Created by lasse on 12/5/17.
//

#include <iostream>
#include <assert.h>
#include "World.h"
namespace rootengine {
    void rootengine::World::updateWorld() {
        if(activePlayer != nullptr)
            activePlayer->updatePlayer();
        if(activeLevel != nullptr)
            activeLevel->updateEnemies();
        if(activeLevel->isLevelComplete()) {

        }
    }

    void rootengine::World::setPlayer(rootengine::Player *player) {
        activePlayer = player;
    }

    void rootengine::World::executeEvent(const SDL_Event &eve) {
        activePlayer->handleEvent(eve);
    }

    rootengine::World *rootengine::World::getInstance() {
        return new World();
    }

    void World::drawWorld() {
        if(activeLevel != nullptr)
            activeLevel->drawLevel();
        if(activePlayer != nullptr)
            activePlayer->draw();

    }

    void World::setLevel(Level *lvl) {
        activeLevel = lvl;
    }
}