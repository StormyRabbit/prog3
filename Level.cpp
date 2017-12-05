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
}