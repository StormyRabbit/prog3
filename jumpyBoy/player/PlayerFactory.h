//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_PLAYERFACTORY_H
#define PROG3_PLAYERFACTORY_H

#include "Player.h"

namespace jumpyboy {
    class PlayerFactory {
    public:
        static Player *player();
    };
}


#endif //PROG3_PLAYERFACTORY_H
