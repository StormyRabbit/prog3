//
// Created by lasse on 12/29/17.
// based on https://stackoverflow.com/questions/28098164/alpha-value-of-pixel-color-and-per-pixel-collision-using-sdl
// and http://www.sdltutorials.com/sdl-per-pixel-collision
//

#include <iostream>
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



    void CollEngine::detectCollision(PhysicsSprite *player, std::vector<PhysicsSprite *> physObjects) {
        bool collOccured = false;
        for(PhysicsSprite *ps : physObjects) {
            if (rectCollision(player, ps)) {
                collOccured = true;
                handleCollision(player, ps);
            }
        }
        if(!collOccured)
            player->setOnGround(false);

    }

   CollEngine *CollEngine::getInstance() {
        return new CollEngine();
    }

    bool CollEngine::getAlpha(PhysicsSprite *ps, int x, int y) {
        //Hämtat från http://www.sdltutorials.com/sdl-per-pixel-collision
        SDL_Rect currentFrame = ps->getCurrentFrame();
        std::string currentSpritePath = ps->getCurrentSprite();
        SDL_Surface* surface = IMG_Load(currentSpritePath.c_str());
        SDL_SetClipRect(surface, &currentFrame);

        int bpp = surface->format->BytesPerPixel;
        Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
        Uint32  pixelColor;

        switch (bpp){
            case (1):
                pixelColor = *p;
                break;
            case (2):
                pixelColor = *(Uint16 *)p;
                break;
            case (3):
                if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                    pixelColor = p[0] << 16 | p[1] << 8 | p[2];
                else
                    pixelColor = p[0] | p[1] << 8 | p[2] << 16;
                break;
            case (4):
                pixelColor = *(Uint32*)p;
                break;
        }

        Uint8 red, green, blue, alpha;
        SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);

        return alpha > 200;
    }

    void CollEngine::handleCollision(PhysicsSprite *player, PhysicsSprite *object) {
        if(player->getCollisionStrategy() != nullptr)
            player->getCollisionStrategy()->CollBehaivor(player, object);
        if(object->getCollisionStrategy() != nullptr)
            object->getCollisionStrategy()->CollBehaivor(object, player);
    }
}
