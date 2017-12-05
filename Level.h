//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "Enemy.h"
#include "EnvironmentSprite.h"

namespace rootengine {
    class Level {
    public:
        Level(std::vector<EnvironmentSprite*> collEnvironment,
        std::vector<EnvironmentSprite*> nonCollEnvironment,
        std::vector<Enemy*> enemyCollection);
        void updateEnemies();
        bool isOccupied(SDL_Rect& rect);
        bool isLevelComplete();
        void drawLevel();
    private:
        std::vector<EnvironmentSprite*> collEnvironment;
        std::vector<EnvironmentSprite*> nonCollEnvironment;
        std::vector<Enemy*> enemyCollection;
        bool levelComplete;
    };
}

#endif //PROG3_LEVEL_H
