//
// Created by Oskar on 2017-12-10.
//

#include "DodgingState.h"
#include "StandingState.h"

namespace rootengine{
    DodgingState::DodgingState() {}
    DodgingState::~DodgingState() {}


    void DodgingState::enterState(class Player &player) {
            player.changeRect().y = player.getRect().y + 20;
            player.changeRect().h = 50;
            player.changeTexture("dodging");
        }

        PlayerState* DodgingState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
            SDL_Keysym keysym = keyEvent.keysym;

            if (keyEvent.type == SDL_KEYUP) {
                switch (keysym.sym) {
                    case SDLK_DOWN :
                        player.changeRect().y = player.getRect().y - 20;
                        player.changeRect().h = 70;
                        return new StandingState();
                }
            }
            return nullptr;
        }

        void DodgingState::updateState(class Player &player) {
        }
    }
