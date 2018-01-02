//
// Created by Oskar on 2017-12-10.
//

#include <cmath>
#include "JumpingState.h"
#include "RunningJumpState.h"
#include "FallingState.h"

namespace jumpyboy{
    JumpingState::JumpingState() {}
    JumpingState::~JumpingState() {}

    void JumpingState::enterState(class Player &player) {
        if(player.getYVelocity() == 0)
            player.getYVelocity() = player.getJumpingPower();

        player.animatedTextureChange("jumping");
    }

    PlayerState* JumpingState::handleInput(Player &player, std::string action, bool isDown) {
        if (isDown) {
            if (action == "left")
                return new RunningJumpState(true);
            if (action == "right")
                return new RunningJumpState(false);

        }
        return nullptr;
    }

    void JumpingState::updateState(class Player &player) {


        if (player.getYVelocity() <= 0) {
            player.enterNewState(new FallingState());
        } else {
            player.changeRect().y = ceil(player.getRect().y - player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() - player.getGravity();

        }
    }
}