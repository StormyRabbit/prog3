//
// Created by oskar on 02-Jan-18.
//

#ifndef PROG3_COLLISIONSTRATEGY_H
#define PROG3_COLLISIONSTRATEGY_H

#include "../sprite/PhysicsSprite.h"
#include "CollisionVariables.h"

namespace rootengine {
    class CollisionStrategy{
    public:
        virtual void handleCollision(class PhysicsSprite *firstObj, PhysicsSprite *secondObj, SDL_Rect &rect) = 0;

        bool standable = true;
    private:
    };
}

#endif //PROG3_COLLISIONSTRATEGY_H
