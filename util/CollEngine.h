//
// Created by lasse on 12/29/17.
//

#ifndef PROG3_COLLENGINE_H
#define PROG3_COLLENGINE_H

#include "../PhysicsSprite.h"

namespace rootengine {
    class CollEngine {
    public:
        bool detectCollision(PhysicsSprite *, PhysicsSprite *);
        static CollEngine *getInstance();
    protected:
        CollEngine() = default;

    private:
        int getAlpha(PhysicsSprite *, int x, int y );
        std::vector<PhysicsSprite *> physObjects;
        bool pixelCollition(PhysicsSprite *, PhysicsSprite *);
        bool rectCollision(PhysicsSprite *aObject, PhysicsSprite *otherObject);
    };
}

#endif //PROG3_COLLENGINE_H
