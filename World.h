//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_WORLD_H
#define PROG3_WORLD_H

#import "Level.h";
#include "Player.h"

namespace rootengine {

    class World {
        public:
            void updateWorld();
            void setPlayer(Player* player);
        private:
            Player *activePlayer;
            Level *activeLevel;
    };
}

#endif //PROG3_WORLD_H
