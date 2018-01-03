//
// Created by lasse on 12/29/17.
//

#ifndef PROG3_COLLENGINE_H
#define PROG3_COLLENGINE_H

#include "../sprite/PhysicsSprite.h"
#include <cmath>
namespace rootengine {
    class CollEngine {
    public:
        void detectCollision(PhysicsSprite *, std::vector<PhysicsSprite*> physObjects);
        static CollEngine *getInstance();
    protected:
        CollEngine() = default;

    private:
        SDL_Rect normalizeBounds(SDL_Rect*, PhysicsSprite*);
        void handleCollision(PhysicsSprite *, PhysicsSprite *);
        bool getAlpha(PhysicsSprite *,SDL_Surface*, int x, int y );
        bool pixelCollition(PhysicsSprite *, PhysicsSprite *);
        bool rectCollision(PhysicsSprite *aObject, PhysicsSprite *otherObject);
    };
}

#endif //PROG3_COLLENGINE_H
