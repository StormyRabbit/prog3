//
// Created by lasse on 1/3/18.
//

#include "FlyingEnemyBehavior.h"
#include "../../enemy/Enemy.h"

void jumpyboy::FlyingEnemyBehavior::handleCollision(rootengine::PhysicsSprite *thisObj, rootengine::PhysicsSprite *otherObj) {
    if(otherObj->getCollisionStrategy() != nullptr) {
        auto *e = (rootengine::Enemy*)thisObj;
        e->killEnemy();
    }
}
