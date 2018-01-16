//
// Created by lasse on 11/24/17.
//

#include <iostream>
#include "Level.h"

namespace jumpyboy {

    bool Level::isLevelComplete() {
        for(jumpyboy::Enemy *enemy : enemyCollection)
            if(enemy->getIsAlive())
                return false;

        return true;
    }

    void Level::drawLevel() {
        if(background != nullptr)
            background->draw();
        for(rootengine::NonCollEnvironment *es : nonCollEnvironment)
            es->draw();
        for(auto* es : collEnvironment)
            es->draw();
        for(jumpyboy::Enemy* enemy : enemyCollection)
            enemy->draw();
    }

    Level *Level::getInstance() {
        return new Level();
    }

    Level::~Level() {
        for(auto *es : collEnvironment)
            delete es;
        for(rootengine::NonCollEnvironment *es : nonCollEnvironment)
            delete es;
        for(jumpyboy::Enemy *enemy : enemyCollection)
            delete enemy;
        delete background;
    }

    void Level::addEnemy(jumpyboy::Enemy *en) {
        enemyCollection.push_back(en);
    }

    void Level::addCollEnv(rootengine::EnvironmentSprite *collEnv) {
        collEnvironment.push_back(collEnv);
    }

    void Level::setBackGround(rootengine::NonCollEnvironment *bgSprite) {
        background = bgSprite;
    }

    void Level::tickLevel() {
        for(jumpyboy::Enemy *enemy : enemyCollection)
            enemy->tick();
    }

    std::vector<rootengine::PhysicsSprite *> Level::getCollidableObjects() {
        std::vector<rootengine::PhysicsSprite *> retVector;
        retVector.reserve( enemyCollection.size() + collEnvironment.size() );
        retVector.insert( retVector.end(), collEnvironment.begin(), collEnvironment.end() );
        retVector.insert( retVector.end(), enemyCollection.begin(), enemyCollection.end() );
        return retVector;
    }

    std::vector<rootengine::PhysicsSprite *> Level::getCollidableEnvironment() {
        std::vector<rootengine::PhysicsSprite *> retVector;
        retVector.insert(retVector.end(), collEnvironment.begin(), collEnvironment.end());
        return retVector;
    }

    std::vector<rootengine::PhysicsSprite *> Level::getEnemyCollection() {
        std::vector<rootengine::PhysicsSprite *> retVector;
        retVector.insert(retVector.end(), enemyCollection.begin(), enemyCollection.end());
        return retVector;
    }
}