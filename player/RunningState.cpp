//
// Created by Oskar on 2017-12-10.
//

#include "RunningState.h"
#include "StandingState.h"

namespace rootengine{
    RunningState::RunningState(bool isLeftBool) {
        isLeft = isLeftBool;
    }
    RunningState::~RunningState() {}
    void RunningState::enterState(Player &player) {
        if (isLeft) {
            player.changeTexture("assets/sprites/Player/p2_duck.png");
        } else {
            player.changeTexture("assets/sprites/Player/p2_jump.png");
        }
    }

    PlayerState* RunningState::handleInput(Player& player, SDL_KeyboardEvent& keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;

        /*
        if (keyEvent.type == SDL_KEYDOWN){
            if (keysym.sym == SDLK_RIGHT && isLeft){
                return new StandingState();
            } else if (keysym.sym == SDLK_LEFT && !isLeft){
                return new StandingState();
            }
        }
        */


        if (keyEvent.type == SDL_KEYUP){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new StandingState();
                case SDLK_RIGHT :
                    return new StandingState();
            }
        }

        return NULL;
    }

    void RunningState::updateState(Player& player){
        if (isLeft){
            player.changeRect().x = player.getRect().x - 5;
        } else {
            player.changeRect().x = player.getRect().x + 5;
        }
    }

}
