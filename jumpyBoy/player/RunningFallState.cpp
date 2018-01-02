//
// Created by oskar on 13-Dec-17.
//

#include <cmath>
#include "RunningFallState.h"
#include "RunningState.h"
#include "FallingState.h"
#include "StandingState.h"

namespace jumpyboy {
    RunningFallState::RunningFallState(bool isLeftBool) : isFallingLeft(isLeftBool) {}
    RunningFallState::~RunningFallState() {}
    void RunningFallState::enterState(Player &player) {
        player.animatedTextureChange("falling");
    }

    void RunningFallState::updateState(class Player &player) {
        if (isFallingLeft)
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        if (!isFallingLeft)
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();

        if (player.checkIfOnGround()){
            player.getYVelocity() = 0;
            player.enterNewState(new RunningState(isFallingLeft));
        } else {
            player.changeRect().y = ceil(player.getRect().y + player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() + player.getGravity();
        }
    }

    PlayerState* RunningFallState::handleInput(Player &player, std::string action, bool isDown) {
        if (!isDown) {

            if (action == "left")
                return new FallingState();
            if (action == "right")
                return new FallingState();

        }

        if (isDown) {

            if (action == "left")
                return new RunningFallState(true);
            if (action == "right")
                return new RunningFallState(false);
        }
        return nullptr;
    }
}