//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_FALLINGSTATE_H
#define PROG3_FALLINGSTATE_H

#include "PlayerState.h"

namespace rootengine {

    class FallingState : public PlayerState {
    public:
        FallingState();
        ~FallingState();
        void updateState(Player& player);
        PlayerState* handleInput(Player& player, SDL_KeyboardEvent& keyEvent);
        void enterState(Player& player);
    private:
        int groundHeight = 430; //TODO MAKE RESOPONSIVE TO ACUAL CLOSES "GROUND"
    };
}


#endif //PROG3_FALLINGSTATE_H
