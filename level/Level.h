//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "../Enemy.h"
#include "../EnvironmentSprite.h"

namespace rootengine {
    class Level {
    public:
        void updateEnemies();
        bool isOccupied(SDL_Rect& rect);
        bool isLevelComplete();
        void drawLevel();
        static Level* getEnemeyFreeLevel(std::vector<EnvironmentSprite *> &collEnvironment,
                                         std::vector<EnvironmentSprite *> &nonCollEnvironment);
        static Level* getInstance(std::vector<EnvironmentSprite*> &collEnvironment,
                                  std::vector<EnvironmentSprite*> &nonCollEnvironment,
                                  std::vector<Enemy*> &enemyCollection);
    protected:
        Level(std::vector<EnvironmentSprite*> &collEnvironment,
              std::vector<EnvironmentSprite*> &nonCollEnvironment);
        Level(std::vector<EnvironmentSprite*> &collEnvironment,
              std::vector<EnvironmentSprite*> &nonCollEnvironment,
              std::vector<Enemy*> &enemyCollection);
    private:
        std::vector<EnvironmentSprite*> collEnvironment;
        std::vector<EnvironmentSprite*> nonCollEnvironment;
        std::vector<Enemy*> enemyCollection;
        bool levelComplete;
    };
}

#endif //PROG3_LEVEL_H
