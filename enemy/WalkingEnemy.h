//
// Created by oskar on 22-Dec-17.
//

#ifndef PROG3_WALKINGENEMY_H
#define PROG3_WALKINGENEMY_H

#include "Enemy.h"

namespace rootengine {
    class WalkingEnemy : public Enemy {
    public:
        static WalkingEnemy* getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues);
        void tick() override;
    protected:
        WalkingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> enemyValues);
    private:
        double squishFactor;
        bool movingLeft = false;
    };
}


#endif //PROG3_WALKINGENEMY_H
