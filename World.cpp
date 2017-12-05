//
// Created by lasse on 12/5/17.
//

#include "World.h"

void rootengine::World::updateWorld() {
    if(activePlayer != nullptr)
        activePlayer->updatePlayer();

}

void rootengine::World::setPlayer(rootengine::Player *player) {
    activePlayer = player;
}
