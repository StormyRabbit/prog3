//
// Created by Oskar on 2017-12-10.
//

#include "StandingState.h"

namespace rootengine{
    PlayerState* StandingState::handleInput(Player& player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type == SDL_KEYDOWN){
            switch (keysym.sym){
                case SDLK_LEFT :
                    return new RunningState();
                case  SDLK_RIGHT :
                    return new RunningState();
                case  SDLK_UP :
                    return new JumpingState();
                case SDLK_DOWN :
                    return new DodgingState();

            }
        }
    }
    void StandingState::enterState(Player &player) {
        player.changeTexture("assets/sprites/Player/p1_front.png");
    }
}