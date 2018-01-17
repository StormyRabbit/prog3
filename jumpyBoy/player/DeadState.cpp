//
// Created by Oskar on 2017-12-10.
//

#include "DeadState.h"

namespace jumpyboy{
    DeadState::DeadState() {}
    DeadState::~DeadState() {}

    void DeadState::enterState(class Player &player) {
        player.animatedTextureChange("dead");
    }

    PlayerState* DeadState::handleInput(Player &player, std::string action, bool isDown) {
        return nullptr;
    }

    void DeadState::updateState(class Player &player) {
    }
}
