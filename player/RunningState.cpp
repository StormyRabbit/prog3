//
// Created by Oskar on 2017-12-10.
//

#include "RunningState.h"

namespace rootengine{
    RunningState::RunningState(int leftOrRight) {

    }
    RunningState::~RunningState() {}
    void RunningState::enterState(Player &player) {
        //TODO ADD WORKING RUNNING TEXTURE PATH HERE
        //TODO ALSO FIX SO THERE IS RIGHT OR LEFT RUNNING
        //player.changeTexture("");
    }

    PlayerState* RunningState::handleInput(Player& player, SDL_KeyboardEvent& keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type == SDL_KEYDOWN){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    player.changeRect().x = player.changeRect().x - 10;
                    break;
                case SDLK_RIGHT :
                    player.changeRect().x = player.changeRect().x + 10;
                    break;
            }
        } else if (keyEvent.type == SDL_KEYUP){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new StandingState();
                case SDLK_RIGHT :
                    return new StandingState();
            }
        }
        return NULL;
    }

}
