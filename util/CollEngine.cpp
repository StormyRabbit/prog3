//
// Created by lasse on 12/29/17.
//

#include "CollEngine.h"
namespace rootengine {
    bool CollEngine::rectCollision(rootengine::PhysicsSprite *aObject, rootengine::PhysicsSprite *otherObject) {
        // object 1
        int leftA = aObject->getRect().x;
        int rightA = aObject->getRect().x + aObject->getRect().w;
        int topA = aObject->getRect().y;
        int botA = aObject->getRect().y + aObject->getRect().h;

        // object 2
        int leftB = otherObject->getRect().x;
        int rightB = otherObject->getRect().x + otherObject->getRect().w;
        int topB = otherObject->getRect().y;
        int botB = otherObject->getRect().y + otherObject->getRect().h;

        // rect coll tests (testar för "touch" och inte overlap
        if (botA < topB)
            return false;

        if (topA > botB)
            return false;

        if (rightA < leftB)
            return false;

        if (leftA > rightB)
            return false;

        // coll har hittats
        return true;
    }

    bool CollEngine::pixelCollition(PhysicsSprite *aObject, PhysicsSprite *otherObject) {

        return false;
    }

    bool CollEngine::detectCollision(PhysicsSprite *aObject, PhysicsSprite *otherObject) {
            if (aObject == otherObject)
                return false;
            if (rectCollision(aObject, otherObject))
                    return true;
            return false;
    }

   CollEngine *CollEngine::getInstance() {
        return new CollEngine();
    }
}
