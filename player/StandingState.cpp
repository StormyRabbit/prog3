//
// Created by Oskar on 2017-12-10.
//

#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "DodgingState.h"

namespace jumpyboy{
    PlayerState* StandingState::handleInput(Player& player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;

        if (keyEvent.type == SDL_KEYDOWN){
            switch (keysym.sym){
                case SDLK_LEFT :
                    return new RunningState(true);
                case  SDLK_RIGHT :
                    return new RunningState(false);
                case  SDLK_UP :
                    return new JumpingState();
                case SDLK_DOWN :
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