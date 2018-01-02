//
// Created by oskar on 05-Dec-17.
//

#ifndef PROG3_ENEMY_H
#define PROG3_ENEMY_H

#include <map>
#include "../rootEngine/sprite/PhysicsSprite.h"

namespace rootengine{
    class Enemy : public PhysicsSprite{
    public:
        ~Enemy();
        void killEnemy();
        void tick() override;
        bool getIsAlive();
    protected:
        Enemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues);
        double movingSpeed;
        double gravity;
        double fallingPower;
        double yVelocity;
    private:
        bool isAlive = true;
    };
}


#endif //PROG3_ENEMY_H
