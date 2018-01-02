//
// Created by lasse on 11/24/17.
//

#include <iostream>
#include "Level.h"

namespace rootengine {
    void Level::updateEnemies() {
        for(Enemy* enemy : enemyCollection) {
            enemy->tick();
            enemy->setOnGround(checkIfOnGround(enemy));
        }
    }

    bool Level::isLevelComplete() {
        for(Enemy* enemy : enemyCollection) {
            if(enemy->getIsAlive())
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
             enemy->draw();
        }
    }

    bool Level::checkIfOnGroundBorder(PhysicsSprite* sprite){
        int leftObject = sprite->getRect().x;
        int rightObject = sprite->getRect().x + sprite->getRect().w;
        int topObject = sprite->getRect().y;
        int bottomObject = sprite->getRect().y + sprite->getRect().h;

        for (EnvironmentSprite* groundObj : collEnvironment) {
            SDL_Rect ground = groundObj->getRect();
            int leftGround = ground.x;
            int rightGround = ground.x + ground.w;
            int topGround = ground.y;
            int bottomGround = ground.y + ground.h;

            if (bottomObject >= topGround && leftObject >= leftGround && rightObject <= rightGround && bottomGround >= bottomObject){
                sprite->changeRect().y = sprite->getRect().y;
                return true;
            }
        }

        return false;
    }

    bool Level::checkIfOnGround(PhysicsSprite* sprite){
        int leftObject = sprite->getRect().x;
        int rightObject = sprite->getRect().x + sprite->getRect().w;
        int topObject = sprite->getRect().y;
        int bottomObject = sprite->getRect().y + sprite->getRect().h;

        for (EnvironmentSprite* groundObj : collEnvironment) {
            SDL_Rect ground = groundObj->getRect();
            int leftGround = ground.x;
            int rightGround = ground.x + ground.w;
            int topGround = ground.y;
            int bottomGround = ground.y + ground.h;

            if (bottomObject >= topGround && rightObject >= leftGround && leftObject <= rightGround && bottomGround >= bottomObject){
                sprite->changeRect().y = sprite->getRect().y;
                return true;
            }
        }

        return false;
    }

    Enemy* Level::checkIfEnemyCollWithPlayer(PhysicsSprite* player){
        for(Enemy* enemy : enemyCollection) {
            bool result = SDL_HasIntersection(&player->getRect(), &enemy->getRect());
            if (result)
                return enemy;
        }
        return nullptr;
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

    void Level::addEnemy(Enemy *en) {
        enemyCollection.push_back(en);
    }

    void Level::addCollEnv(EnvironmentSprite *collEnv) {
        collEnvironment.push_back(collEnv);
    }
}