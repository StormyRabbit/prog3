//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_PLAYERCOLLBEHAVIOR_H
#define PROG3_PLAYERCOLLBEHAVIOR_H


#include "../../rootEngine/collision/CollisionStrategy.h"
#include "CollisionVariables.h"

namespace jumpyboy {
    class PlayerCollBehavior : public rootengine::CollisionStrategy {
    public:
        void handleCollision(class rootengine::PhysicsSprite *firstObj, rootengine::PhysicsSprite *secondObj, SDL_Rect &rect) override;
        //rootengine::CollisionVariables *getCollisionVariables() override;
    private:
        rootengine::CollisionVariables *cv = nullptr;
    };
}


#endif //PROG3_PLAYERCOLLBEHAVIOR_H
