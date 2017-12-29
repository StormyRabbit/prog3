//
// Created by oskar on 05-Dec-17.
//

#ifndef PROG3_ENEMY_H
#define PROG3_ENEMY_H

#include <map>
#include "../PhysicsSprite.h"

namespace rootengine{
    class Enemy : public PhysicsSprite{
    public:
        ~Enemy();
        void killEnemy();
        virtual void tick();
        bool getIsAlive();
    protected:
        Enemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames);
    private:
        bool isAlive;
    };
}


#endif //PROG3_ENEMY_H
