//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_WORLD_H
#define PROG3_WORLD_H

#include "level/Level.h"
#include "player/Player.h"
#include "level/LevelManager.h"

namespace rootengine {

    class World {
        public:
            void executeEvent(const SDL_Event& eve);
            void drawWorld();
            void updateWorld();
            void setPlayer(Player* player);
            void setLevel(Level* lvl);
            static World* getInstance();
            bool readyForNextLvl();
        protected:
            World() = default;
        private:
            Player *activePlayer;
            Level *activeLevel;
    };
}

#endif //PROG3_WORLD_H
