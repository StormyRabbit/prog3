//
// Created by oskar on 22-Dec-17.
//

#ifndef PROG3_FLYINGENEMY_H
#define PROG3_FLYINGENEMY_H

#include "Enemy.h"

namespace rootengine{
    class FlyingEnemy : public Enemy {
    public:
        static FlyingEnemy* getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites);
        void tick();
    protected:
        FlyingEnemy(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites);
        ~FlyingEnemy();
    private:

    };
}


#endif //PROG3_FLYINGENEMY_H
