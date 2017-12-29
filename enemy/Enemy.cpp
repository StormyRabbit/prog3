//
// Created by oskar on 05-Dec-17.
//

#include "Enemy.h"
namespace rootengine{
    Enemy::Enemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) : PhysicsSprite(xPos,yPos, width, height, sprites, frames){
        movingSpeed = enemyValues.find("speed")->second;
        gravity = enemyValues.find("gravity")->second;
        fallingPower = enemyValues.find("fallPower")->second;
    }
    Enemy::~Enemy(){}

    void Enemy::tick() {
        PhysicsSprite::tick();
    }

    void Enemy::killEnemy() {
        isAlive = false;
    }

    bool Enemy::getIsAlive() {
        return isAlive;
    };
}