//
// Created by Oskar on 2017-12-10.
//

#include <cmath>
#include "RunningJumpState.h"
#include "FallingState.h"
#include "JumpingState.h"
#include "RunningFallState.h"

namespace rootengine{
    RunningJumpState::RunningJumpState(bool isLeftBool) : isJumpingLeft(isLeftBool){}
    RunningJumpState::~RunningJumpState() {}

    void RunningJumpState::enterState(class Player &player) {
        if (player.getYVelocity() == 0){
            player.getYVelocity() = player.getJumpingPower();
        }
        player.animatedTextureChange("jumping");
    }

    PlayerState* RunningJumpState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type == SDL_KEYUP) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new JumpingState(player.getRect().y);
                case SDLK_RIGHT :
                    return new JumpingState(player.getRect().y);

            }
        }

        if (keyEvent.type == SDL_KEYDOWN) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new RunningJumpState(true);
                case SDLK_RIGHT :
                    return new RunningJumpState(false);
            }
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