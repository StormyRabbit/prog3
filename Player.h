//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include "PhysicsSprite.h"

namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        ~Player();
    protected:
        Player(int xPos, int yPos, int width, int height, std::string pathToTexture);
    private:
    };
}


#endif //PROG3_PLAYER_H
