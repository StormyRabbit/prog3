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
            switch (std::stoi(action)){
                case std::stoi("left") :
                    return new RunningState(true);
                case  std::stoi("right") :
                    return new RunningState(false);
                case  std::stoi("up") :
                    return new JumpingState();
                case std::stoi("down") :
                    return new DodgingState();
            }
        }
        return nullptr;
    }

    void StandingState::updateState(Player& player){}

    void StandingState::enterState(Player &player) {
        player.animatedTextureChange("standing");
    }
}