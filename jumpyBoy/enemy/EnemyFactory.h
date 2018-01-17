//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_ENEMYFACTORY_H
#define PROG3_ENEMYFACTORY_H

#include "FlyingEnemy.h"
#include "WalkingEnemy.h"

namespace jumpyboy {
    class EnemyFactory {
    public:
        static FlyingEnemy *fly(int x, int y, int w, int h, int maxX, int mixX, int speed);
        static WalkingEnemy *slime();
    protected:
        EnemyFactory() = default;
    };
}


#endif //PROG3_ENEMYFACTORY_H
