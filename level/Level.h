//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_LEVEL_H
#define PROG3_LEVEL_H

#include <vector>
#include "../enemy/Enemy.h"
#include "../EnvironmentSprite.h"
#include "../PhysicsSprite.h"
#include "../player/Player.h"

namespace rootengine {
    class Level {
    public:
        void addNonCollEnv(EnvironmentSprite*);
        void addCollEnv(EnvironmentSprite*);
        void setBackGround(EnvironmentSprite*);

        void addEnemy(Enemy *);
        void updateEnemies();
        bool isLevelComplete();
        void drawLevel();
        ~Level();
        static Level* getInstance();
        Enemy *checkIfEnemyCollWithPlayer(rootengine::Player *player);
        bool checkIfOnGround(PhysicsSprite *sprite);
    protected:
        Level() = default;
    private:
        EnvironmentSprite* background;
        std::vector<EnvironmentSprite*> collEnvironment;
        std::vector<EnvironmentSprite*> nonCollEnvironment;
        std::vector<Enemy*> enemyCollection;



    };
}

#endif //PROG3_LEVEL_H
