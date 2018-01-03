//
// Created by lasse on 1/3/18.
//

#include "FlyingEnemyBehavior.h"
#include "../../enemy/Enemy.h"

namespace jumpyboy {
    void FlyingEnemyBehavior::CollBehaivor(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) {
        if(secondObj->getCollisionStrategy() != nullptr) {
            auto* e = (rootengine::Enemy*)firstObj;
            e->killEnemy();
        }
    }
}
