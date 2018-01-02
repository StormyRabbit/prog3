//
// Created by lasse on 12/5/17.
//

#include "World.h"
#include "player/JumpingState.h"

namespace rootengine {
    void World::updateWorld() {
        if(activePlayer != nullptr)
            activePlayer->tick();
        if(activeLevel != nullptr)
            //activeLevel->updateEnemies();
        //if(activeLevel->isLevelComplete()) {}
        activeLevel->updateEnemies();
        Enemy* enemy = activeLevel->checkIfEnemyCollWithPlayer(activePlayer);
        if (enemy != nullptr && enemy->getIsAlive()){
            enemy->killEnemy();
            enemy->setOnGroundBorder(activeLevel->checkIfOnGroundBorder(enemy));
        }
        activePlayer->setOnGround(activeLevel->checkIfOnGround(activePlayer));
    }

    void World::setPlayer(PhysicsSprite *player) {
        activePlayer = player;
    }

    void World::executeEvent(const SDL_Event &eve) {
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

    void World::setLevel(Level *lvl) {
        delete activeLevel;
        activeLevel = lvl;
    }

    bool World::readyForNextLvl() {
        return activeLevel == nullptr || activeLevel->isLevelComplete();
    }
}