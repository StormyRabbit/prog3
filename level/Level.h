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
        void setBackGround(EnvironmentSprite*);
        void updateEnemies();
        bool isLevelComplete();
        void drawLevel();
        ~Level();
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
        EnvironmentSprite* background;
        std::vector<EnvironmentSprite*> collEnvironment;
        std::vector<EnvironmentSprite*> nonCollEnvironment;
        std::vector<Enemy*> enemyCollection;
        bool levelComplete;
    };
}

#endif //PROG3_LEVEL_H
