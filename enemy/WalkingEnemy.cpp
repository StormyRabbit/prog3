//
// Created by oskar on 22-Dec-17.
//

#include "WalkingEnemy.h"

namespace rootengine{

    WalkingEnemy* WalkingEnemy::getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) {
        return new WalkingEnemy(xPos, yPos, width, height, sprites, frames, enemyValues);
    }

    WalkingEnemy::WalkingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues) : Enemy(xPos, yPos, width, height, sprites, frames, enemyValues) {
        squishFactor = enemyValues.find("squishFactor")->second;
        this->animatedTextureChange("moving");
    }

    void WalkingEnemy::tick() {
        Enemy::tick();
        if (!checkIfOnGround()){
            changeRect().y = getRect().y + movingSpeed;
        }

        if (!checkIfOnGroundBorder()){
            movingLeft = !movingLeft;
        }

        if (getIsAlive()){
            if(movingLeft){
                changeRect().x = getRect().x + movingSpeed;
            } else{
                changeRect().x = getRect().x - movingSpeed;
            }
        } else if (!getIsAlive()){
            this->animatedTextureChange("dead");
            changeRect().h = getRect().h * squishFactor;
        }
    }


}