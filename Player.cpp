//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"

namespace rootengine{
    Player::Player(int xPos, int yPos, int width, int height, std::string pathToTexture) : PhysicsSprite(xPos,yPos, width, height, pathToTexture){}
    Player::~Player() {}
}
