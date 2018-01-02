//
// Created by lasse on 12/29/17.
//

#ifndef PROG3_COLLENGINE_H
#define PROG3_COLLENGINE_H

#include "../PhysicsSprite.h"

namespace rootengine {
    class CollEngine {
    public:
        void detectCollision(PhysicsSprite *, std::vector<PhysicsSprite*> physObjects);
        static CollEngine *getInstance();
    protected:
        CollEngine() = default;

    private:
        void handleCollision(PhysicsSprite *, PhysicsSprite *);
        int getAlpha(PhysicsSprite *, int x, int y );
        bool pixelCollition(PhysicsSprite *, PhysicsSprite *);
        bool rectCollision(PhysicsSprite *aObject, PhysicsSprite *otherObject);
    };
}

#endif //PROG3_COLLENGINE_H
