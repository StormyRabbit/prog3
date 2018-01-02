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

    PlayerState* JumpingState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;

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

    void JumpingState::updateState(class Player &player) {


        if (player.getYVelocity() <= 0) {
            player.enterNewState(new FallingState());
        } else {
            player.changeRect().y = ceil(player.getRect().y - player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() - player.getGravity();

        }
    }
}