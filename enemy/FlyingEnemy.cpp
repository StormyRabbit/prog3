//
// Created by oskar on 22-Dec-17.
//

#include "FlyingEnemy.h"

namespace rootengine{
    FlyingEnemy::FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites) : Enemy(xPos, yPos, width, height, sprites) {}
    FlyingEnemy::~FlyingEnemy(){}
    void FlyingEnemy::tick(){

    }
}