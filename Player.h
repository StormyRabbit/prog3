//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include "PhysicsSprite.h"

namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        static Player* getInstance(int xPos, int yPos,int width,int height);
        ~Player();
    protected:
        Player(int xPos, int yPos, int width, int height);
    private:
        std::string frontTexture = "assets/sprites/Player/p1_front.png";
    };
}


#endif //PROG3_PLAYER_H
