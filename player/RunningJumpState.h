//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_RUNNINGJUMPSTATE_H
#define PROG3_RUNNINGJUMPSTATE_H

#include "PlayerState.h"

namespace jumpyboy {

    class RunningJumpState : public PlayerState{
    public:
        RunningJumpState(bool isLeftBool);
        ~RunningJumpState();
        PlayerState* handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void updateState(class Player& player);
        void enterState(class Player& player);

    private:
        int startingHeight = 430; //TODO change so that it implements starting height of jump!
        bool isJumpingLeft;


    };
}


#endif //PROG3_RUNNINGJUMPSTATE_H
