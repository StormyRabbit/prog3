//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_WALKINGENEMYBEHAVIOR_H
#define PROG3_WALKINGENEMYBEHAVIOR_H


#include "../../rootEngine/collision/CollisionStrategy.h"

class WalkingEnemyBehavior : public rootengine::CollisionStrategy {
public:
    void CollBehaivor(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) override;
};


#endif //PROG3_WALKINGENEMYBEHAVIOR_H
