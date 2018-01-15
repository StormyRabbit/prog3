//
// Created by lasse on 12/5/17.
//

#include <iostream>
#include "LevelManager.h"
namespace rootengine {

    LevelInterface *LevelManager::getNextLevel() {
        int lvlToReturn = currentLevel++;
        if(lvlToReturn > levelCollection.size())
            return nullptr;
        return levelCollection[lvlToReturn];
    }

    void LevelManager::addLevel(LevelInterface* aLvl) {
        LevelManager::levelCollection.push_back(aLvl);
    }

    LevelManager *LevelManager::getInstance() {
        return new LevelManager();
    }
}