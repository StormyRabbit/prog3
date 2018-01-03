//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_FLYINGENEMYBEHAVIOR_H
#define PROG3_FLYINGENEMYBEHAVIOR_H


#include "../../rootEngine/collision/CollisionStrategy.h"
#include "../../rootEngine/sprite/PhysicsSprite.h"
namespace jumpyboy {
    class FlyingEnemyBehavior : public rootengine::CollisionStrategy{
        void CollBehaivor(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) override;

    };
}


#endif //PROG3_FLYINGENEMYBEHAVIOR_H
