//
// Created by lasse on 1/3/18.
//

#include "FlyingEnemyBehavior.h"
#include "../../jumpyBoy/enemy/Enemy.h"

void jumpyboy::FlyingEnemyBehavior::handleCollision(rootengine::PhysicsSprite *thisObj, rootengine::PhysicsSprite *otherObj) {
    if(otherObj->getCollisionStrategy() != nullptr) {
        auto *e = (jumpyboy::Enemy*)thisObj;
        e->killEnemy();
    }
}
