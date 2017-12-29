//
// Created by Oskar on 2017-12-10.
//

#include "DodgingState.h"
#include "StandingState.h"

namespace rootengine{
    DodgingState::DodgingState() {}
    DodgingState::~DodgingState() {}


    void DodgingState::enterState(class Player &player) {
        nonDodgingHeight = player.getRect().h;
        player.setResetHeight(player.changeRect().h * 0.8);
        int posChange = nonDodgingHeight - player.getResetHeight();

        player.changeRect().y = player.getRect().y + posChange;
        player.changeRect().h = player.getResetHeight();
        player.animatedTextureChange("dodging");
        }

        PlayerState* DodgingState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {
            SDL_Keysym keysym = keyEvent.keysym;

            if (keyEvent.type == SDL_KEYUP) {
                switch (keysym.sym) {
                    case SDLK_DOWN :
                        int posChange = nonDodgingHeight - player.getResetHeight();
                        player.changeRect().y = player.getRect().y - posChange;
                        player.setResetHeight(nonDodgingHeight);
                        return new StandingState();
                }
            }
            return nullptr;
        }

        void DodgingState::updateState(class Player &player) {
        }
    }
