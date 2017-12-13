//
// Created by lasse on 11/24/17.
//

#include <iostream>
#include "Level.h"
namespace rootengine {
    void Level::updateEnemies() {
        for(Enemy* enemy : enemyCollection) {}
    }

    bool Level::isLevelComplete() {
        for(Enemy* enemy : enemyCollection) {
            bool alive = false;
                return false;
        }
        return true;
    }

    void Level::drawLevel() {
        if(background != nullptr)
            background->draw();

        for(EnvironmentSprite* es : nonCollEnvironment)
            es->draw();
        for(EnvironmentSprite* es : collEnvironment)
            es->draw();

        for(Enemy* enemy : enemyCollection) {
            // enemy->draw();
        }
    }

    Level *Level::getInstance() {
        return new Level();
    }

    void Level::setBackGround(EnvironmentSprite *bgSprite) {
        background = bgSprite;
    }

    Level::~Level() {
        for(EnvironmentSprite *es : collEnvironment)
            delete es;
        for(EnvironmentSprite *es : nonCollEnvironment)
            delete es;
        for(Enemy *enemy : enemyCollection)
            delete enemy;
        delete background;
    }

    void Level::addNonCollEnv(EnvironmentSprite *es) {
        nonCollEnvironment.push_back(es);
    }

    void Level::addEnemy(Enemy *en) {
        enemyCollection.push_back(en);
    }

    void Level::addCollEnv(EnvironmentSprite *collEnv) {
        collEnvironment.push_back(collEnv);
    }
}