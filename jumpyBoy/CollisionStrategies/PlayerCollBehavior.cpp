//
// Created by lasse on 1/3/18.
//

#include <iostream>
#include "PlayerCollBehavior.h"

namespace jumpyboy {
    void PlayerCollBehavior::handleCollision(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj, SDL_Rect &rect) {
        if(secondObj->getCollisionStrategy() != nullptr) {
            std::cout << secondObj->getHitAngle(rect.x, rect.y) << std::endl;
            if(secondObj->getCollisionStrategy()->standable)
                firstObj->setOnGround(true);
        }
    }
}
