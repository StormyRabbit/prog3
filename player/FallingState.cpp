//
// Created by Oskar on 2017-12-10.
//

#include <vector>
#include <cmath>
#include "FallingState.h"
#include "StandingState.h"
#include "RunningFallState.h"

namespace rootengine{
    FallingState::FallingState() {}
    FallingState::~FallingState() {}
    void FallingState::enterState(Player &player) {
        player.animatedTextureChange("falling");
    }

    void FallingState::updateState(class Player &player) {
        /*if (player.getRect().y > groundHeight){
            player.enterNewState(new StandingState());
            player.changeRect().y = groundHeight;
        }*/
        //TODO ADD GET FUNCTION FOR ENVI OBJECTS
        //JUST TRY CODE
        SDL_Rect ground1;
        ground1.x = 0;
        ground1.y = 500;
        ground1.h = 100;
        ground1.w = 1200;
        SDL_Rect ground2;
        ground2.x = 500;
        ground2.y = 420;
        ground2.h = 20;
        ground2.w = 200;
        std::vector<SDL_Rect> grounds;
        grounds.push_back(ground1);
        grounds.push_back(ground2);

        if (player.checkIfOnGround(&player, grounds)){
            player.getYVelocity() = 0;
            player.enterNewState(new StandingState());
        } else {
            player.changeRect().y = ceil(player.getRect().y + player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() + player.getGravity();
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

            }
        }
        return nullptr;
    }
}
