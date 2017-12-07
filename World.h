//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_WORLD_H
#define PROG3_WORLD_H

#include "Level.h"
#include "Player.h"

namespace rootengine {

    class World {
        public:
            void executeEvent(const SDL_Event& eve);
            void drawWorld();
            void updateWorld();
            void setPlayer(Player* player);
            static World* getInstance();
        protected:
            World() = default;
        private:
            Player *activePlayer;
            Level *activeLevel;
    };
}

#endif //PROG3_WORLD_H
