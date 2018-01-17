//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "../enemy/Enemy.h"
#include "../../rootEngine/sprite/NonCollEnvironmentSprite.h"
#include "../../rootEngine/sprite/PhysicsSprite.h"
#include "../../rootEngine/sprite/EnvironmentSprite.h"
#include "../../rootEngine/interfaces/LevelInterface.h"

namespace jumpyboy {
    class Level : public rootengine::LevelInterface {
    public:
        void addCollEnv(rootengine::EnvironmentSprite*);
        void setBackGround(rootengine::NonCollEnvironment*);
        void addEnemy(jumpyboy::Enemy *);
        void tickLevel() override;
        bool isLevelComplete() override;
        void drawLevel() override;
        std::vector<rootengine::PhysicsSprite*> getCollidableEnvironment() override;
        std::vector<rootengine::PhysicsSprite*> getCollidableObjects() override;
        std::vector<rootengine::PhysicsSprite*> getEnemyCollection();

        ~Level();
        static Level* getInstance();
    protected:
        Level() = default;
    private:
        rootengine::NonCollEnvironment* background{};
        std::vector<rootengine::EnvironmentSprite*> collEnvironment;
        std::vector<rootengine::NonCollEnvironment*> nonCollEnvironment;
        std::vector<jumpyboy::Enemy*> enemyCollection;
    };
}

#endif //PROG3_LEVEL_H
