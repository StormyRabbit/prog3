//
// Created by Oskar on 2017-12-10.
//

#include "JumpingState.h"
#include "RunningJumpState.h"

namespace rootengine{
    JumpingState::JumpingState() {}
    JumpingState::~JumpingState() {}

    void JumpingState::enterState(class Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
    }

    PlayerState* PlayerState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;

        if (keyEvent.type == SDL_KEYDOWN) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new RunningJumpState();
                case SDLK_RIGHT :
                    return new RunningJumpState();
            }
        }
    }

    void JumpingState::updateState(class Player &player) {
        if (player.getRect().y > startingHeight + 100) {
            //TODO CALL FALLING STATE, NO IDE HOW PLZ HELP
        } else {
            player.changeRect().y = player.getRect().y - 10;
        }
    }
}