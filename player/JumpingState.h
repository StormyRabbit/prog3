//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_JUMPINGSTATE_H
#define PROG3_JUMPINGSTATE_H

#include "PlayerState.h"

namespace rootengine {

    class JumpingState : public PlayerState {
    public:
        JumpingState();
        ~JumpingState();
        PlayerState* handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void updateState(class Player& player);
        void enterState(class Player& player);

    private:
        int startingHeight = 450; //TODO change so that it implements starting height of jump!
        bool isJumpingLeft = false;
        bool isJumpingRight = false;
    };
}


#endif //PROG3_JUMPINGSTATE_H
