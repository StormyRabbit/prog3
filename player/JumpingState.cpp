//
// Created by Oskar on 2017-12-10.
//

#include "JumpingState.h"
#include "RunningJumpState.h"
#include "FallingState.h"

namespace rootengine{
    JumpingState::JumpingState(int startingYPos) : startingHeight(startingYPos) {}
    JumpingState::~JumpingState() {}

    void JumpingState::enterState(class Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
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
        if (player.getRect().y < startingHeight - 100) {
            player.enterNewState(new FallingState());
        } else {
            player.changeRect().y = player.getRect().y - 5;
        }
    }
}