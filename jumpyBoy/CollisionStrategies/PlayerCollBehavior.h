//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_PLAYERCOLLBEHAVIOR_H
#define PROG3_PLAYERCOLLBEHAVIOR_H


#include "../../rootEngine/collision/CollisionStrategy.h"
namespace jumpyboy {
    class PlayerCollBehavior : public rootengine::CollisionStrategy {
        void CollBehaivor(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) override;
    };
}


#endif //PROG3_PLAYERCOLLBEHAVIOR_H
