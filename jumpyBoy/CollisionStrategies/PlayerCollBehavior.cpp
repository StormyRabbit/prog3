//
// Created by lasse on 1/3/18.
//

#include "PlayerCollBehavior.h"

namespace jumpyboy {
    void PlayerCollBehavior::handleCollision(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) {
        if(secondObj->getCollisionStrategy() != nullptr) {
            if(secondObj->getCollisionStrategy()->standeble)
                firstObj->setOnGround(true);
        }
    }
}
