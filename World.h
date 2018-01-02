//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_WORLD_H
#define PROG3_WORLD_H

#include "level/Level.h"
#include "level/LevelManager.h"
#include "util/CollEngine.h"

namespace rootengine {

    class World {
    public:
        void executeEvent(const SDL_Event& eve);
        void updateWorld();
        void drawWorld();
        void setPlayer(PhysicsSprite* player);
        void setLevel(Level* lvl);
        static World *getInstance();
        bool readyForNextLvl();
    protected:
        World();
    private:
        CollEngine *ce = nullptr;
        PhysicsSprite *activePlayer = nullptr;
        Level *activeLevel = nullptr;
    };
}

#endif //PROG3_WORLD_H
