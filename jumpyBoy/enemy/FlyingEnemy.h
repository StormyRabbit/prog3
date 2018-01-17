//
// Created by oskar on 22-Dec-17.
//

#ifndef PROG3_FLYINGENEMY_H
#define PROG3_FLYINGENEMY_H

#include "Enemy.h"

namespace jumpyboy {
    class FlyingEnemy : public Enemy {
    public:
        static FlyingEnemy* getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues);
        void tick() override;
        void setFlyingDirection(bool isLeft);
        int getBouncyPower();
    protected:
        FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues);
        ~FlyingEnemy();
    private:
        int flyingMaxX;
        int flyingMinX;
        bool flyingLeft = false;
        bool isBouncing = false;
        int bouncyPower;
    };
}


#endif //PROG3_FLYINGENEMY_H
