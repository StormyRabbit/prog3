//
// Created by Oskar on 2017-12-10.
//

#include <cmath>
#include "RunningJumpState.h"
#include "FallingState.h"
#include "JumpingState.h"
#include "RunningFallState.h"

namespace jumpyboy{
    RunningJumpState::RunningJumpState(bool isLeftBool) : isJumpingLeft(isLeftBool){}
    RunningJumpState::~RunningJumpState() {}

    void RunningJumpState::enterState(class Player &player) {
        if (player.getYVelocity() == 0){
            player.getYVelocity() = player.getJumpingPower();
        }
        player.animatedTextureChange("jumping");
    }

    PlayerState* RunningJumpState::handleInput(Player &player, std::string action, bool isDown) {
        if (!isDown) {
            if (action == "left")
                return new JumpingState();
            if (action == "right")
                return new JumpingState();
        }

        if (isDown) {
            if (action == "left")
                return new RunningJumpState(true);
            if (action == "right")
                return new RunningJumpState(false);
        }
        return nullptr;
    }

    void RunningJumpState::updateState(class Player &player) {
        if (isJumpingLeft)
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        if (!isJumpingLeft)
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();

        if (player.getYVelocity() <= 0) {
            player.enterNewState(new RunningFallState(isJumpingLeft));
        } else {
            player.changeRect().y = ceil(player.getRect().y - player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() - player.getGravity();

        }
    }

}