//
// Created by lasse on 12/5/17.
//

#include <iostream>
#include "LevelManager.h"
namespace rootengine {

    Level *LevelManager::getNextLevel() {
        int lvlToReturn = currentLevel++;
        if(lvlToReturn > levelCollection.size())
            return nullptr;
        return levelCollection[lvlToReturn];
    }

    void LevelManager::addLevel(Level* aLvl) {
        LevelManager::levelCollection.push_back(aLvl);
    }

    LevelManager *LevelManager::getInstance() {
        return new LevelManager();
    }
}