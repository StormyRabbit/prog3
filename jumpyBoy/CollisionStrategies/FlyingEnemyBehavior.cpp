//
// Created by lasse on 1/3/18.
//

#include "FlyingEnemyBehavior.h"
#include "../../jumpyBoy/enemy/Enemy.h"
#include "../enemy/FlyingEnemy.h"

void jumpyboy::FlyingEnemyBehavior::handleCollision(rootengine::PhysicsSprite *thisObj, rootengine::PhysicsSprite *otherObj, SDL_Rect &rect) {
    if(otherObj->getCollisionStrategy() != nullptr) {
        auto *e = (jumpyboy::FlyingEnemy*)thisObj;
        SDL_Point normRect = e->getNormalizedValue(rect.x, rect.y);

        if (normRect.y < (static_cast<double>(e->getRect().h * 0.25))){
            if (normRect.x < (static_cast<double>(e->getRect().w * 0.5))){
                e->setFlyingDirection(false);
            } else {
                e->setFlyingDirection(true);
            }
            e->killEnemy();
        }
    }
}
