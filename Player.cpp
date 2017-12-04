//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"

namespace rootengine{
    Player::Player(int xPos, int yPos, int width, int height) : PhysicsSprite(xPos,yPos, width, height, "assets/sprites/Player/p1_front.png"){}
    Player::~Player() {}

    Player* Player::getInstance(int xPos, int yPos, int width, int height) {
        return new Player(xPos, yPos, width, height);
    }
}
