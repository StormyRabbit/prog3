//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "../../jumpyBoy/enemy/Enemy.h"
#include "../sprite/NonCollEnvironmentSprite.h"
#include "../sprite/PhysicsSprite.h"
#include "../sprite/EnvironmentSprite.h"
#include "../interfaces/LevelInterface.h"

namespace rootengine {
    class Level : public LevelInterface {
    public:
        void addCollEnv(EnvironmentSprite*);
        void setBackGround(NonCollEnvironment*);
        void addEnemy(jumpyboy::Enemy *);
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
        std::vector<jumpyboy::Enemy*> enemyCollection;
    };
}

#endif //PROG3_LEVEL_H
