//
// Created by lasse on 11/24/17.
//
#include "sprite.h"
#include <string>

#include

#ifndef PROG3_NONPHYSICSSPRITE_H
#define PROG3_NONPHYSICSSPRITE_H


class nonPhysicsSprite : public sprite {
public:
    nonPhysicsSprite(int x, int y, int height, int width, std::string spritePath) : sprite(x, y, height, width, spritePath) {};
};


#endif //PROG3_NONPHYSICSSPRITE_H
