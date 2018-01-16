//
// Created by lasse on 1/8/18.
//

#ifndef PROG3_LEVELINTERFACE_H
#define PROG3_LEVELINTERFACE_H

#include "../sprite/PhysicsSprite.h"

namespace rootengine {
    class LevelInterface {
    public:
        virtual bool isLevelComplete() = 0;
        virtual void drawLevel() = 0;
        virtual void tickLevel() = 0;
        virtual std::vector<PhysicsSprite*> getCollidableObjects() = 0;
        virtual std::vector<PhysicsSprite*> getCollidableEnvironment() = 0;
        virtual std::vector<PhysicsSprite*> getEnemyCollection() = 0;

    };
}

#endif //PROG3_LEVELINTERFACE_H
