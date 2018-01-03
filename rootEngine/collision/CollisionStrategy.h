//
// Created by oskar on 02-Jan-18.
//

#ifndef PROG3_COLLISIONSTRATEGY_H
#define PROG3_COLLISIONSTRATEGY_H

#include "../sprite/PhysicsSprite.h"

namespace rootengine {
    class CollisionStrategy{
    public:
        virtual void CollBehaivor(class PhysicsSprite *firstObj, PhysicsSprite *secondObj) = 0;
        bool standeble = true;
    private:
    };
}

#endif //PROG3_COLLISIONSTRATEGY_H
