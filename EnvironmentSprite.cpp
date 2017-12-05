//
// Created by oskar on 05-Dec-17.
//

#include <SDL_image.h>
#include "EnvironmentSprite.h"
#include "System.h"

namespace rootengine{
    EnvironmentSprite::EnvironmentSprite(int xPos, int yPos, int width, int height, std::string pathToSprite) : Sprite(xPos, yPos, width, height) {
        texture = IMG_LoadTexture(sys.getRenderer(), pathToSprite.c_str());
    }
    EnvironmentSprite* EnvironmentSprite::getInstance(int xPos, int yPos, int width, int height,
                                                      std::string pathToSprite) {
        return new EnvironmentSprite(xPos,yPos, width, height, pathToSprite);
    }

    void EnvironmentSprite::draw() const {
        SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRect());
    }
    EnvironmentSprite::~EnvironmentSprite() {}
}