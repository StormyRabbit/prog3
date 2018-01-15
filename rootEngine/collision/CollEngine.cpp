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
        SDL_Rect boundsA = aObject->getRect();
        SDL_Rect boundsB = otherObject->getRect();
        //SDL_Rect collisionRect = intersection(aObject,otherObject);
        std::string currentSpritePathA = aObject->getCurrentSprite();
        SDL_Surface* surfaceA = IMG_Load(currentSpritePathA.c_str());
        std::string currentSpritePathB = otherObject->getCurrentSprite();
        SDL_Surface* surfaceB = IMG_Load(currentSpritePathB.c_str());

        int top = std::max(boundsA.y, boundsB.y);
        int left = std::max(boundsA.x, boundsB.x);
        int bottom = std::min(boundsA.y + boundsA.h, boundsB.y + boundsB.h);
        int right = std::min(boundsA.x + boundsA.w, boundsB.x + boundsB.w);


        for (int y = top; y < bottom; y++){
            for (int x = left; x < right; x++){
                if (aObject->getAlphaValue(x, y) && otherObject->getAlphaValue(x, y))
                    return true;
            }
        }
        return false;



        /*SDL_Rect normalA = normalizeBounds(&collisionRect, aObject);
        SDL_Rect normalB = normalizeBounds(&collisionRect, otherObject);
        for(int y = 0; y < collisionRect.h; y++) {
            for(int x = 0; x < collisionRect.w; x++) {
                if(getAlpha(aObject, surfaceA, normalA.x + x, normalA.y + y) && getAlpha(otherObject, surfaceB, normalB.x + x, normalB.y + y)){}
                    return true;
            }

            }
            SDL_FreeSurface(surfaceA);
            SDL_FreeSurface(surfaceB);

    */
    }



    void CollEngine::detectCollision(PhysicsSprite *player, std::vector<PhysicsSprite *> physObjects) {
        bool collOccured = false;
        for(PhysicsSprite *ps : physObjects) {
            if (rectCollision(player, ps)) {
                if(pixelCollition(player, ps)){
                    collOccured = true;
                    handleCollision(player, ps);
                }
            }
        }
        if(!collOccured)
            player->setOnGround(false);
    }

   CollEngine *CollEngine::getInstance() {
        return new CollEngine();
    }

    bool CollEngine::getAlpha(PhysicsSprite *ps, SDL_Surface* surface, int x, int y) {
        /*//Hämtat från http://www.sdltutorials.com/sdl-per-pixel-collision
        SDL_Rect currentFrame = ps->getCurrentFrame();
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
                    pixelColor = p[0] | p[1] << 8 | p[2] << 16;
                break;
            case (4):
                pixelColor = *(Uint32*)p;
                break;
        }

        Uint8 red, green, blue, alpha;
        SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);
        return alpha > 200;
         */
    }

    void CollEngine::handleCollision(PhysicsSprite *player, PhysicsSprite *object) {
        if(player->getCollisionStrategy() != nullptr)
            player->getCollisionStrategy()->handleCollision(player, object);
        if(object->getCollisionStrategy() != nullptr)
            object->getCollisionStrategy()->handleCollision(object, player);
    }

    SDL_Rect CollEngine::normalizeBounds(SDL_Rect *rect, PhysicsSprite* object) {
        SDL_Rect normalized;
        normalized.x = rect->x - (Sint16)object->getRect().x + ((Sint16)object->getRect().w / 2);
        normalized.y = rect->y - (Sint16)object->getRect().y + ((Sint16)object->getRect().h / 2);
        normalized.h = rect->h;
        normalized.w = rect->w;

        return normalized;
    }

    SDL_Rect CollEngine::intersection(PhysicsSprite *aObject, PhysicsSprite *otherObject) {
        SDL_Rect boundsA = aObject->getRect();
        SDL_Rect boundsB = otherObject->getRect();
        int x1 = fmax(boundsA.x, boundsB.x);
        int y1 = fmax(boundsA.y, boundsB.y);
        int x2 = fmax(boundsA.x + boundsA.w, boundsB.x + boundsB.w);
        int y2 = fmax(boundsA.y + boundsA.h, boundsB.y + boundsB.h);

        int width = x2 - x1;
        int height = y2 - y1;

        if(width > 0 && height > 0)
        {
            SDL_Rect intersect = {x1, y1, width, height};
            return intersect;
        }
        else
        {
            SDL_Rect intersect = {0, 0, 0, 0};
            return intersect;
        }
    }
}
