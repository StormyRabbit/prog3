//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_GROUNDBEHAVIOR_H
#define PROG3_GROUNDBEHAVIOR_H

#include "../../rootEngine/collision/CollisionStrategy.h"

namespace jumpyboy {
    class GroundBehavior : public rootengine::CollisionStrategy {
    public:
        void handleCollision(rootengine::PhysicsSprite *, rootengine::PhysicsSprite *) override;
        GroundBehavior() = default;
    };
}


#endif //PROG3_GROUNDBEHAVIOR_H
