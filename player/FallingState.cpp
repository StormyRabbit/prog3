//
// Created by Oskar on 2017-12-10.
//

#include <vector>
#include <cmath>
#include "FallingState.h"
#include "StandingState.h"
#include "RunningFallState.h"

namespace jumpyboy{
    FallingState::FallingState() {}
    FallingState::~FallingState() {}
    void FallingState::enterState(Player &player) {
        player.animatedTextureChange("falling");
    }

    void FallingState::updateState(class Player &player) {
        if (player.checkIfOnGround()){
            player.getYVelocity() = 0;
            player.enterNewState(new StandingState());
        } else {
            player.changeRect().y = ceil(player.getRect().y + player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() + player.getGravity();
        }
    }

    PlayerState* FallingState::handleInput(Player &player, std::string action, bool isDown) {
        if (isDown){
            switch (std::stoi(action)) {
                case std::stoi("left") :
                    return new RunningFallState(true);
                case std::stoi("right") :
                    return new RunningFallState(false);

            }
        }
        return nullptr;
    }
}
