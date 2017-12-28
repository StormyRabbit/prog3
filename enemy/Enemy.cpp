//
// Created by oskar on 05-Dec-17.
//

#include "Enemy.h"
namespace rootengine{
    Enemy::Enemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames) : PhysicsSprite(xPos,yPos, width, height, sprites, frames){}
    Enemy::~Enemy(){}

    void Enemy::tick() {}

    void Enemy::killEnemy() {
        setIsDraweble(false);
        isAlive = false;
    };
}