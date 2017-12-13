//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_RUNNINGSTATE_H
#define PROG3_RUNNINGSTATE_H

#include "PlayerState.h"

namespace rootengine {
    class RunningState : public PlayerState {
    public:
        explicit RunningState(int leftOrRight); //Left (-1) or right (1)
        ~RunningState();
        PlayerState *handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void enterState(class Player& player);

    };
}


#endif //PROG3_RUNNINGSTATE_H
