//
// Created by lasse on 11/24/17.
//

#include "Level.h"
namespace rootengine {
    Level::Level(std::vector<EnvironmentSprite *> collEnvironment, std::vector<EnvironmentSprite *> nonCollEnvironment,
                 std::vector<Enemy *> enemyCollection) {
        Level::collEnvironment = collEnvironment;
        Level::nonCollEnvironment = nonCollEnvironment;
        Level::enemyCollection = enemyCollection;
    }

    bool Level::isOccupied(SDL_Rect &rect) {
        for(EnvironmentSprite* es : collEnvironment){

        }
        return false;
    }

    void Level::updateEnemies() {
        for(Enemy* enemy : enemyCollection) {}
    }

    bool Level::isLevelComplete() {
        return levelComplete;
    }

    void Level::drawLevel() {
        for(EnvironmentSprite* es : collEnvironment)
            es->draw();

        for(EnvironmentSprite* es : nonCollEnvironment)
            es->draw();

        for(Enemy* enemy : enemyCollection) {
            // TODO enemy->draw();
        }
    }
}