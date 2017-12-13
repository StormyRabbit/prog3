//
// Created by lasse on 12/9/17.
//

#include "CollDetection.h"
namespace rootengine {

    bool CollDetection::pixelCollition(PhysicsSprite *physObj1, PhysicsSprite *physObj2) {
        if(Rect_collision(physObj1, physObj2)) {
            /*
             * TODO:
             * https://stackoverflow.com/questions/28098164/alpha-value-of-pixel-color-and-per-pixel-collision-using-sdl
            */
        }

        return false;
    }

    bool CollDetection::Rect_collision(PhysicsSprite *pSprite, PhysicsSprite *pPhysicsSprite) {
        return false;
    }
}
