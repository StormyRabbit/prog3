//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_LEVELMANAGER_H
#define PROG3_LEVELMANAGER_H

#include <vector>
#include "Level.h"
namespace rootengine {

class LevelManager {
public:
    void addLevel(Level* );
    Level *getNextLevel();
    static LevelManager* getInstance();
protected:
    LevelManager() = default;
private:
    std::vector<Level*> levelCollection;
    int currentLevel = 0;
};

}


#endif //PROG3_LEVELMANAGER_H
