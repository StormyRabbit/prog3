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

    bool CollEngine::pixelCollition(PhysicsSprite *aObject, PhysicsSprite *otherObject, SDL_Rect &retRect) {
        SDL_Rect boundsA = aObject->getRect();
        SDL_Rect boundsB = otherObject->getRect();
        std::string currentSpritePathA = aObject->getCurrentSprite();
        std::string currentSpritePathB = otherObject->getCurrentSprite();

        int top = std::max(boundsA.y, boundsB.y);
        int left = std::max(boundsA.x, boundsB.x);
        int bottom = std::min(boundsA.y + boundsA.h, boundsB.y + boundsB.h);
        int right = std::min(boundsA.x + boundsA.w, boundsB.x + boundsB.w);


        for (int y = top; y < bottom; y++) {
            for (int x = left; x < right; x++) {
                if (aObject->getAlphaValue(x, y) && otherObject->getAlphaValue(x, y)) {
                    retRect.x = x;
                    retRect.y = y;
                    return true;
                }
            }
        }
        return false;
    }

    void CollEngine::playerCollision(PhysicsSprite *player, std::vector<PhysicsSprite *> physObjects) {
        bool collOccured = false;
        for(PhysicsSprite *ps : physObjects) {
            if (rectCollision(player, ps)) {
                SDL_Rect rect;
                if(pixelCollition(player, ps, rect)){
                    collOccured = true;
                    handleCollision(player, ps, rect);
                }
            }
        }
        if(!collOccured)
            player->setOnGround(false);
    }

   CollEngine *CollEngine::getInstance() {
        return new CollEngine();
    }

    void CollEngine::handleCollision(PhysicsSprite *player, PhysicsSprite *object, SDL_Rect &collRect) {
        if(player->getCollisionStrategy() != nullptr)
            player->getCollisionStrategy()->handleCollision(player, object, collRect);
        if(object->getCollisionStrategy() != nullptr)
            object->getCollisionStrategy()->handleCollision(object, player, collRect);
    }

    void CollEngine::EnemyCollision(PhysicsSprite *obj, std::vector<PhysicsSprite *> physObjects) {
        for(PhysicsSprite *ps : physObjects)
            if(rectCollision(obj, ps)) {
                obj->setOnGround(true);
            }

    }
}
