//
// Created by Oskar on 2017-12-04.
//

#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine{
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, std::string pathToDraw) : Sprite(xPos, yPos, width, height) {
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::changeTexture(std::string pathToNewTexture) {
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToNewTexture.c_str());
    }

    void PhysicsSprite::draw() const {
        SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRect());
    }
}
