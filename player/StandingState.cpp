//
// Created by Oskar on 2017-12-10.
//

#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "DodgingState.h"

namespace rootengine{
    PlayerState* StandingState::handleInput(Player& player, SDL_KeyboardEvent &keyEvent) {
        const Uint8* keyStatus = SDL_GetKeyboardState(NULL);
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyStatus[SDL_SCANCODE_RIGHT]){
            return new RunningState(false);
        }
        if (keyStatus[SDL_SCANCODE_LEFT]){
            return new RunningState(true);
        }
        if (keyStatus[SDL_SCANCODE_UP]){
            return new JumpingState();
        }
        if (keyStatus[SDL_SCANCODE_DOWN]){
            return new DodgingState();
        }



        /*if (keyEvent.type == SDL_KEYDOWN){
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
        }*/

        return nullptr;
    }

    void StandingState::updateState(Player& player){}

    void StandingState::enterState(Player &player) {
        player.changeTexture("assets/sprites/Player/p1_front.png");
    }
}