//
// Created by oskar on 05-Dec-17.
//

#include "Enemy.h"
namespace rootengine{
    Enemy::Enemy(int xPos, int yPos, int width, int height) : PhysicsSprite(xPos,yPos, width, height, "assets/sprites/Enemy/fishSwim1.png"){}

    Enemy* Enemy::getInstance(int xPos, int yPos, int width, int height) {
        return new Enemy(xPos, yPos, width, height);
    }
}