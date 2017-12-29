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

    FlyingEnemy::FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) : Enemy(xPos, yPos, width, height, sprites, frames) {
        flyingSpeed = enemyValues.find("speed")->second;
        flyingMinX = enemyValues.find("maxX")->second;
        flyingMaxX = enemyValues.find("minX")->second;
        gravity = enemyValues.find("gravity")->second;
        fallingPower = enemyValues.find("fallPower")->second;

        this->animatedTextureChange("flying");
    }
    FlyingEnemy::~FlyingEnemy(){}

    void FlyingEnemy::tick(){
        FlyingEnemy::animatedTick();
        if (this->getRect().x <= flyingMaxX)
            flyingLeft = false;
        if (this->getRect().x >= flyingMinX)
            flyingLeft = true;

        if (flyingLeft){
            this->changeRect().x = this->getRect().x - floor(flyingSpeed);
        } else {
            this->changeRect().x = this->getRect().x + floor(flyingSpeed);
        }

        if (!getIsAlive()){
            this->animatedTextureChange("dead");

            //TODO ADD GET FUNCTION FOR ENVI OBJECTS
            //JUST TRY CODE
            SDL_Rect ground1;
            ground1.x = 0;
            ground1.y = 500;
            ground1.h = 100;
            ground1.w = 1200;
            SDL_Rect ground2;
            ground2.x = 500;
            ground2.y = 420;
            ground2.h = 20;
            ground2.w = 200;
            std::vector<SDL_Rect> grounds;
            grounds.push_back(ground1);
            grounds.push_back(ground2);

            if ((checkIfOnGround(this, grounds) || isBouncing)){
                if(yVelocity <= 0){
                    yVelocity = fallingPower;
                }

                fallingPower = fallingPower * 0.99;
                flyingSpeed = flyingSpeed * 0.99;

                changeRect().y = ceil(getRect().y - yVelocity);
                yVelocity = yVelocity - gravity;

                if (yVelocity <= 0){
                    isBouncing = false;
                }

            } else {
                changeRect().y = ceil(getRect().y + yVelocity);
                yVelocity = yVelocity + gravity;
                if(checkIfOnGround(this, grounds)) {
                    yVelocity = 0;
                    isBouncing = true;
                }
            }

        }
    }
}