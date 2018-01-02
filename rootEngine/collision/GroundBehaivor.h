//
// Created by oskar on 02-Jan-18.
//

#ifndef PROG3_GROUNDBEHAIVOR_H
#define PROG3_GROUNDBEHAIVOR_H

#include "CollisionStrategy.h"
// TODO: flytta till jumpyBoy
namespace rootengine{
    class GroundBehaivor : public CollisionStrategy {
    public:
        void CollBehaivor(PhysicsSprite* sprite) override;
    protected:
    private:
    };
}


#endif //PROG3_GROUNDBEHAIVOR_H
