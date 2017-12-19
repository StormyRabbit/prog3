//
// Created by oskar on 13-Dec-17.
//

#include "RunningFallState.h"
#include "RunningState.h"
#include "FallingState.h"

namespace rootengine{
    RunningFallState::RunningFallState(bool isLeftBool) : isFallingLeft(isLeftBool) {}
    RunningFallState::~RunningFallState() {}
    void RunningFallState::enterState(Player &player) {
        player.changeTexture("assets/sprites/Player/p1_jump.png");
    }

    void RunningFallState::updateState(class Player &player) {
        if (isFallingLeft)
            player.changeRect().x = player.getRect().x - 5;
        if (!isFallingLeft)
            player.changeRect().x = player.getRect().x + 5;

        if (player.getRect().y > groundHeight){
            player.enterNewState(new RunningState(isFallingLeft));
            player.changeRect().y = groundHeight;
        } else {
            player.changeRect().y = player.getRect().y + 5;
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