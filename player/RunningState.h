//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_RUNNINGSTATE_H
#define PROG3_RUNNINGSTATE_H

#include "PlayerState.h"

namespace rootengine {
    class RunningState : public PlayerState {
    public:
        explicit RunningState(bool isLeft);
        ~RunningState();
        void updateState(class Player& player);
        PlayerState *handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void enterState(class Player& player);
    private:
        bool isLeft;
        SDL_Rect framePos[11];
    };
}


#endif //PROG3_RUNNINGSTATE_H
