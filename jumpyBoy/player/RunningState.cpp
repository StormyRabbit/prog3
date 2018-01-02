//
// Created by Oskar on 2017-12-10.
//

#include "RunningState.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "RunningJumpState.h"
#include "DodgingState.h"
#include "FallingState.h"
#include "RunningFallState.h"

namespace jumpyboy {
    RunningState::RunningState(bool isLeftBool) {
        isLeft = isLeftBool;
    }
    RunningState::~RunningState() {}
    void RunningState::enterState(Player &player) {

        //TODO FLIP TEXTURES
        if (isLeft) {
            player.animatedTextureChange("running");
        } else {
            player.animatedTextureChange("running");
        }

    }

    PlayerState* RunningState::handleInput(Player &player, std::string action, bool isDown) {

        if (isDown){
            if (action == "up")
                return new RunningJumpState(isLeft);
            if (action == "down")
                return new DodgingState();
            }

        if (!isDown){
            if (action == "left")
                return new StandingState();
            if (action == "right")
                return new StandingState();
            }
        return nullptr;
    }

    void RunningState::updateState(Player& player){
        if (isLeft){
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        } else {
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();
        }

        if (!player.checkIfOnGround()){
            player.enterNewState(new RunningFallState(isLeft));
        }
    }

}
