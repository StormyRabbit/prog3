//
// Created by oskar on 02-Jan-18.
//

#ifndef PROG3_GROUNDBEHAIVOR_H
#define PROG3_GROUNDBEHAIVOR_H

#include "../../rootEngine/collision/CollisionStrategy.h"
// TODO: flytta till jumpyBoy
namespace jumpyboy{
    class GroundBehaivor : public rootengine::CollisionStrategy {
    public:
        void CollBehaivor(rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj) override;
    protected:
    private:
    };
}


#endif //PROG3_GROUNDBEHAIVOR_H
