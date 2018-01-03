//
// Created by oskar on 02-Jan-18.
//

#include "EnvironmentSprite.h"

namespace rootengine{
    EnvironmentSprite* EnvironmentSprite::getInstance(int xPos, int yPos, int height, int width, spritesMap sprites, fMapType frames) {
        return new EnvironmentSprite(xPos, yPos, height, width, sprites, frames);
    }

    EnvironmentSprite::EnvironmentSprite(int xPos, int yPos, int height, int width, spritesMap sprites, fMapType frames) : PhysicsSprite(xPos, yPos, height, width, sprites, frames) {
        this->animatedTextureChange(sprites.find(sprites.begin()->first)->first);
    }

    EnvironmentSprite::~EnvironmentSprite() {

    }

    void EnvironmentSprite::tick() {
        PhysicsSprite::tick();
    }
}
