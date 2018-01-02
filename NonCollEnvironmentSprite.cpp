//
// Created by oskar on 05-Dec-17.
//

#include <SDL_image.h>
#include "NonCollEnvironmentSprite.h"
#include "System.h"

namespace rootengine{
    NonCollEnvironment::NonCollEnvironment(int xPos, int yPos, int width, int height, std::string pathToSprite) : Sprite(xPos, yPos, width, height) {
        texture = IMG_LoadTexture(sys.getRenderer(), pathToSprite.c_str());
    }
    NonCollEnvironment* NonCollEnvironment::getInstance(int xPos, int yPos, int width, int height,
                                                      std::string pathToSprite) {
        return new NonCollEnvironment(xPos,yPos, width, height, pathToSprite);
    }

    void NonCollEnvironment::draw() const {
        SDL_RenderCopy(sys.getRenderer(), texture, nullptr, &getRect());
    }
    NonCollEnvironment::~NonCollEnvironment() {}


}