//
// Created by lasse on 12/5/17.
//

#include "World.h"

namespace rootengine {
    void World::updateWorld() {
        if(activePlayer != nullptr)
            activePlayer->tick();
        if(activeLevel != nullptr)
            activeLevel->tickLevel();
        ce->detectCollision(activePlayer, activeLevel->getCollidableObjects());
    }

    void World::setPlayer(PhysicsSprite *player) {
        activePlayer = player;
    }

    World *World::getInstance() {
        return new World();
    }

    void World::drawWorld() {
        if(activeLevel != nullptr)
            activeLevel->drawLevel();
        if(activePlayer != nullptr)
            activePlayer->draw();
    }

    void World::setLevel(LevelInterface *lvl) {
        delete activeLevel;
        activeLevel = lvl;
    }

    bool World::readyForNextLvl() {
        return activeLevel == nullptr || activeLevel->isLevelComplete();
    }

    World::World() {
        ce = CollEngine::getInstance();
    }
}