//
// Created by oskar on 05-Dec-17.
//

#include "Enemy.h"
namespace rootengine{
    Enemy::Enemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites) : PhysicsSprite(xPos,yPos, width, height, sprites){}
    Enemy::~Enemy(){}

    void Enemy::tick() {}

    void Enemy::killEnemy() {
        isAlive = false;
    };
}