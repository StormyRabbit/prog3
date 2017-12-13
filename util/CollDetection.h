//
// Created by lasse on 12/9/17.
//

#ifndef PROG3_COLLDETECTION_H
#define PROG3_COLLDETECTION_H

#include "../PhysicsSprite.h"

namespace rootengine {

    class CollDetection {
    public:
        // TODO: besluta om dessa ska vara static eller ej
        static bool pixelCollition(PhysicsSprite *, PhysicsSprite *);
        static bool Rect_collision(PhysicsSprite *pSprite, PhysicsSprite *pPhysicsSprite);
    };

}


#endif //PROG3_COLLDETECTION_H
