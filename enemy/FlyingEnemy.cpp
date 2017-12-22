//
// Created by oskar on 22-Dec-17.
//

#include "FlyingEnemy.h"

namespace rootengine{
    FlyingEnemy::FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames) : Enemy(xPos, yPos, width, height, sprites, frames) {}
    FlyingEnemy::~FlyingEnemy(){}
    void FlyingEnemy::tick(){

    }
}