//
// Created by Oskar on 2017-12-10.
//

#include "FallingState.h"

namespace rootengine{
    FallingState::FallingState() {}
    FallingState::~FallingState() {}
    void FallingState::enterState(Player &player) {
        //TODO ADD FALLING TEXTURE!
        //player.changeTexture("");
    }

    void FallingState::updateState(class Player &player) {
        if (player.getRect().y < groundHeight){
            //TODO CHANGE TO STANDING PLZ HELP
            player.changeRect().y = groundHeight;
        } else {
            player.changeRect().y = player.getRect().y + 10;
        }
    }

    PlayerState* FallingState::handleInput(Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type = SDL_KEYDOWN){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    //TODO MAKE FALLING RUNNING CLASS OR CHANGE EXISTING JUMPINGRUNNING CLASS TO WORK
                    break;
                case SDLK_RIGHT :
                    //TODO MAKE FALLING RUNNING CLASS OR CHANGE EXISTING JUMPINGRUNNING CLASS TO WORK
                    break;
            }
        }
    }
}
