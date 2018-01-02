//
// Created by Oskar on 2017-12-10.
//

#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "DodgingState.h"

namespace jumpyboy{

    PlayerState* StandingState::handleInput(Player &player, std::string action, bool isDown) {
        if (isDown){
            if (action == "left")
                return new RunningState(true);
            if (action == "right")
                return new RunningState(false);
            if (action == "up")
                    return new JumpingState();
            if (action == "down")
                return new DodgingState();

        }

        return nullptr;
    }

    void StandingState::updateState(Player& player){}

    void StandingState::enterState(Player &player) {
        player.animatedTextureChange("standing");
    }

}