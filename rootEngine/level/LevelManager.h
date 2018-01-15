//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_LEVELMANAGER_H
#define PROG3_LEVELMANAGER_H

#include <vector>
#include "../../jumpyBoy/LevelFactory/Level.h"
#include "../interfaces/LevelInterface.h"

namespace rootengine {

class LevelManager {
public:
    void addLevel(LevelInterface* );
    LevelInterface *getNextLevel();
    static LevelManager* getInstance();
protected:
    LevelManager() = default;
private:
    std::vector<LevelInterface*> levelCollection;
    int currentLevel = 0;
};

}


#endif //PROG3_LEVELMANAGER_H
