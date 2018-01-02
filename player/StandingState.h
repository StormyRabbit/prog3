//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_STANDINGSTATE_H
#define PROG3_STANDINGSTATE_H

#include "PlayerState.h"

namespace jumpyboy {
    class StandingState : public PlayerState {
    public:
        StandingState() {};
        ~StandingState() {};
        PlayerState* handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void enterState(class Player& player);
        void updateState(class Player& player);
    };
}


#endif //PROG3_STANDINGSTATE_H
