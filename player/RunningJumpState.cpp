//
// Created by Oskar on 2017-12-10.
//

#include "RunningJumpState.h"
#include "FallingState.h"
#include "JumpingState.h"
#include "RunningFallState.h"

namespace rootengine{
    RunningJumpState::RunningJumpState(bool isLeftBool) : isJumpingLeft(isLeftBool){}
    RunningJumpState::~RunningJumpState() {}

    void RunningJumpState::enterState(class Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
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
            player.changeRect().x = player.getRect().x - 5;
        if (!isJumpingLeft)
            player.changeRect().x = player.getRect().x + 5;

        if (player.getRect().y < startingHeight - 100) {
            player.enterNewState(new RunningFallState(isJumpingLeft));
        } else {
            player.changeRect().y = player.getRect().y - 5;
        }
    }

}