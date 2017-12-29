//
// Created by oskar on 22-Dec-17.
//

#include <cmath>
#include "FlyingEnemy.h"
#include "../System.h"

namespace rootengine{
    FlyingEnemy* FlyingEnemy::getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) {
        return new FlyingEnemy(xPos, yPos, width, height, sprites, frames, enemyValues);
    }

    FlyingEnemy::FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) : Enemy(xPos, yPos, width, height, sprites, frames, enemyValues) {
        flyingMinX = enemyValues.find("maxX")->second;
        flyingMaxX = enemyValues.find("minX")->second;

        this->animatedTextureChange("moving");
    }
    FlyingEnemy::~FlyingEnemy(){}

    void FlyingEnemy::tick(){
        Enemy::tick();
        if (this->getRect().x <= flyingMaxX)
            flyingLeft = false;
        if (this->getRect().x >= flyingMinX)
            flyingLeft = true;

        if (flyingLeft){
            this->changeRect().x = this->getRect().x - floor(movingSpeed);
        } else {
            this->changeRect().x = this->getRect().x + floor(movingSpeed);
        }

        if (!getIsAlive()){
            this->animatedTextureChange("dead");

            if ((checkIfOnGround())){
                yVelocity = 0;
                isBouncing = true;
            }
            if ((checkIfOnGround() || isBouncing)){
                if(yVelocity <= 0){
                    yVelocity = fallingPower;
                }

                fallingPower = fallingPower * 0.97;
                movingSpeed = movingSpeed * 0.99;

                changeRect().y = ceil(getRect().y - yVelocity);
                yVelocity = yVelocity - gravity;

                if (yVelocity <= 0){
                    isBouncing = false;
                }

            } else {
                changeRect().y = ceil(getRect().y + yVelocity);
                yVelocity = yVelocity + gravity;
            }

        }
    }
}