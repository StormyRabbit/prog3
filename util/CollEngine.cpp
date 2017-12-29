//
// Created by lasse on 12/29/17.
// based on https://stackoverflow.com/questions/28098164/alpha-value-of-pixel-color-and-per-pixel-collision-using-sdl
// and http://www.sdltutorials.com/sdl-per-pixel-collision
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

    int CollEngine::getAlpha(PhysicsSprite *ps, int x, int y) {

        SDL_PixelFormat *pixelFormat = ps->getSurface()->format;
        int bytesPerPixel = pixelFormat->BitsPerPixel;

        Uint8 *p = (Uint8*)ps->getSurface()->pixels + y * ps->getSurface()->pitch + x * bytesPerPixel;
        Uint32 pixelColor = *p;
        Uint8 red;
        Uint8 green;
        Uint8 blue;
        Uint8 alpha;
        SDL_GetRGBA(pixelColor, pixelFormat, &red, &green, &blue, &alpha);
        return 0;
    }
}