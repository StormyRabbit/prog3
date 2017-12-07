//
// Created by lasse on 12/5/17.
//

#include <iostream>
#include "LevelManager.h"
namespace rootengine {

    Level *LevelManager::getNextLevel() {
        return levelCollection[currentLevel++];
    }

    void LevelManager::setLevelCollection(std::vector<Level *> &levelCollection) {
        LevelManager::levelCollection = levelCollection;
    }

    LevelManager *LevelManager::getInstance() {
        return new LevelManager();
    }
}