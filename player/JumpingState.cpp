//
// Created by Oskar on 2017-12-10.
//

#include "JumpingState.h"
#include "RunningJumpState.h"
#include "FallingState.h"

namespace rootengine{
    JumpingState::JumpingState() {}
    JumpingState::~JumpingState() {}

    void JumpingState::enterState(class Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
    }

    PlayerState* JumpingState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type == SDL_KEYUP) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    isJumpingLeft = false;
                    break;
                case SDLK_RIGHT :
                    isJumpingRight = false;
                    break;
            }
        }

        if (keyEvent.type == SDL_KEYDOWN) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    isJumpingLeft = true;
                    break;
                case SDLK_RIGHT :
                    isJumpingRight = true;
                    break;
            }
        }
        return nullptr;
    }

    void JumpingState::updateState(class Player &player) {
        if (isJumpingLeft)
            player.changeRect().x = player.getRect().x - 5;
        if (isJumpingRight)
            player.changeRect().x = player.getRect().x + 5;

        if (player.getRect().y < startingHeight - 100) {
            player.enterNewState(new FallingState());
        } else {
            player.changeRect().y = player.getRect().y - 5;
        }
    }
}