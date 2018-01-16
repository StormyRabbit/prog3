//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_FLYINGENEMYBEHAVIOR_H
#define PROG3_FLYINGENEMYBEHAVIOR_H

#include "../../rootEngine/collision/CollisionStrategy.h"

namespace jumpyboy {
    class FlyingEnemyBehavior: public rootengine::CollisionStrategy {
        void handleCollision(rootengine::PhysicsSprite *, rootengine::PhysicsSprite *, SDL_Rect &rect) override;
    };
}


#endif //PROG3_FLYINGENEMYBEHAVIOR_H
