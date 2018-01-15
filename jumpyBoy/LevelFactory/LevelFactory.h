//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_LEVELFACTORY_H
#define PROG3_LEVELFACTORY_H

#include "Level.h"

namespace jumpyboy {
    class LevelFactory {
    public:
        static Level *firstLvl();
        static Level *secondLvl();
    protected:
    private:
    };
}


#endif //PROG3_LEVELFACTORY_H
