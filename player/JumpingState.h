//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_JUMPINGSTATE_H
#define PROG3_JUMPINGSTATE_H

#include "PlayerState.h"

namespace jumpyboy {

    class JumpingState : public PlayerState {
    public:
        JumpingState();
        ~JumpingState();
        PlayerState* handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void updateState(class Player& player);
        void enterState(class Player& player);
    };
}


#endif //PROG3_JUMPINGSTATE_H
