//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "../enemy/Enemy.h"
#include "../NonCollEnvironmentSprite.h"
#include "../PhysicsSprite.h"
#include "../environment/EnvironmentSprite.h"

namespace rootengine {
    class Level {
    public:
        void addCollEnv(EnvironmentSprite*);
        void setBackGround(NonCollEnvironment*);
        void addEnemy(Enemy *);
        void updateEnemies();
        bool isLevelComplete();
        void drawLevel();
        ~Level();
        static Level* getInstance();
        std::vector<PhysicsSprite*> getCollVector();
    protected:
        Level() = default;
    private:
        NonCollEnvironment* background{};
        std::vector<EnvironmentSprite*> collEnvironment;
        std::vector<NonCollEnvironment*> nonCollEnvironment;
        std::vector<Enemy*> enemyCollection;
    };
}

#endif //PROG3_LEVEL_H
