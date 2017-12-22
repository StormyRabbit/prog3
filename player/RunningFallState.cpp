//
// Created by oskar on 13-Dec-17.
//

#include <cmath>
#include "RunningFallState.h"
#include "RunningState.h"
#include "FallingState.h"
#include "StandingState.h"

namespace rootengine{
    RunningFallState::RunningFallState(bool isLeftBool) : isFallingLeft(isLeftBool) {}
    RunningFallState::~RunningFallState() {}
    void RunningFallState::enterState(Player &player) {
        player.changeTexture("falling");
    }

    void RunningFallState::updateState(class Player &player) {
        if (isFallingLeft)
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        if (!isFallingLeft)
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();

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

        if (player.checkIfOnGround(player.changeRect(), grounds)){
            player.getYVelocity() = 0;
            player.enterNewState(new RunningState(isFallingLeft));
        } else {
            player.changeRect().y = ceil(player.getRect().y + player.getYVelocity());
            player.getYVelocity() = player.getYVelocity() + player.getGravity();
        }
    }

    PlayerState* RunningFallState::handleInput(Player &player, SDL_KeyboardEvent &keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;
        if (keyEvent.type == SDL_KEYUP) {
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new FallingState();
                case SDLK_RIGHT :
                    return new FallingState();

            }
        }

        if (keyEvent.type == SDL_KEYDOWN) {
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