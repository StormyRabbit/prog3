//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_WORLD_H
#define PROG3_WORLD_H

#include "../../jumpyBoy/LevelFactory/Level.h"
#include "../level/LevelManager.h"
#include "../collision/CollEngine.h"

namespace rootengine {

    class World {
    public:
        void updateWorld();
        void drawWorld();
        void setPlayer(PhysicsSprite* player);
        void setLevel(LevelInterface* lvl);
        static World *getInstance();
        bool readyForNextLvl();
    protected:
        World();
    private:
        CollEngine *ce = nullptr;
        PhysicsSprite *activePlayer = nullptr;
        LevelInterface *activeLevel = nullptr;
    };
}

#endif //PROG3_WORLD_H
