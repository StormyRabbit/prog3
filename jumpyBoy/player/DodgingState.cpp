//
// Created by Oskar on 2017-12-10.
//

#include "DodgingState.h"
#include "StandingState.h"

namespace jumpyboy{
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

        PlayerState* DodgingState::handleInput(Player &player, std::string action, bool isDown) {

            if (!isDown) {
                if (action =="down") {
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
