//
// Created by Oskar on 2017-12-10.
//

#include "FallingState.h"
#include "StandingState.h"
#include "RunningFallState.h"

namespace rootengine{
    FallingState::FallingState() {}
    FallingState::~FallingState() {}
    void FallingState::enterState(Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
    }

    void FallingState::updateState(class Player &player) {
        if (player.getRect().y > groundHeight){
            player.enterNewState(new StandingState());
            player.changeRect().y = groundHeight;
        } else {
            player.changeRect().y = player.getRect().y + 5;
        }
    }

    PlayerState* FallingState::handleInput(Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type = SDL_KEYDOWN){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new RunningFallState(true);
                case SDLK_RIGHT :
                    return new RunningFallState(false);
                    break;
            }
        }
        return nullptr;
    }
}
