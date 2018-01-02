//
// Created by lasse on 11/24/17.
//

#include <iostream>
#include "Level.h"

namespace rootengine {
    void Level::updateEnemies() {
        for(Enemy *enemy : enemyCollection)
            enemy->tick();
    }

    bool Level::isLevelComplete() {
        for(Enemy *enemy : enemyCollection)
            if(enemy->getIsAlive())
                return false;

        return true;
    }

    void Level::drawLevel() {
        if(background != nullptr)
            background->draw();
        for(NonCollEnvironment *es : nonCollEnvironment)
            es->draw();
        for(EnvironmentSprite *es : collEnvironment)
            es->draw();
        for(Enemy* enemy : enemyCollection)
            enemy->draw();
    }

    Level *Level::getInstance() {
        return new Level();
    }

    Level::~Level() {
        for(EnvironmentSprite *es : collEnvironment)
            delete es;
        for(NonCollEnvironment *es : nonCollEnvironment)
            delete es;
        for(Enemy *enemy : enemyCollection)
            delete enemy;
        delete background;
    }

    void Level::addEnemy(Enemy *en) {
        enemyCollection.push_back(en);
    }

    void Level::addCollEnv(EnvironmentSprite *collEnv) {
        collEnvironment.push_back(collEnv);
    }

    std::vector<PhysicsSprite *> Level::getCollVector() {
        std::vector<PhysicsSprite *> retVector;
        retVector.reserve( enemyCollection.size() + collEnvironment.size() ); 
        retVector.insert( retVector.end(), collEnvironment.begin(), collEnvironment.end() );
        retVector.insert( retVector.end(), enemyCollection.begin(), enemyCollection.end() );
        return retVector;
    }

    void Level::setBackGround(NonCollEnvironment *bgSprite) {
        background = bgSprite;
    }
}