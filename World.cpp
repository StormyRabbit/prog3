//
// Created by lasse on 12/5/17.
//

#include <iostream>
#include <assert.h>
#include "World.h"
namespace rootengine {
    void World::updateWorld() {
        if(activePlayer != nullptr)
            activePlayer->tick();
        if(activeLevel != nullptr)
            //activeLevel->updateEnemies();
        //if(activeLevel->isLevelComplete()) {}
        activeLevel->updateEnemies();
        Enemy* enemy = activeLevel->checkIfEnemyCollWithPlayer(activePlayer);
        if (enemy != nullptr){
            enemy->killEnemy();
        }
    }

    void World::setPlayer(rootengine::Player *player) {
        activePlayer = player;
    }

    void World::executeEvent(const SDL_Event &eve) {
        activePlayer->handleEvent(eve);

    }

    World *rootengine::World::getInstance() {
        return new World();
    }

    void World::drawWorld() {
        if(activeLevel != nullptr)
            activeLevel->drawLevel();
        if(activePlayer != nullptr)
            activePlayer->draw();

    }

    void World::setLevel(Level *lvl) {
        if(activeLevel != nullptr)
            delete activeLevel;
        activeLevel = lvl;
    }

    bool World::readyForNextLvl() {
        return activeLevel == nullptr || activeLevel->isLevelComplete();
    }
}