//
// Created by oskar on 05-Dec-17.
//

#include <SDL_image.h>
#include "EnvironmentSprite.h"
#include "System.h"

namespace rootengine{
    EnvironmentSprite::EnvironmentSprite(int xPos, int yPos, int width, int height, std::string pathToSprite) : Sprite(xPos, yPos, width, height) {
        IMG_LoadTexture(sys.getRenderer(), pathToSprite.c_str());
    }
    EnvironmentSprite::~EnvironmentSprite() {}
}