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
        PlayerState* handleInput(Player &player, std::string action, bool isDown);
        void updateState(class Player& player);
        void enterState(class Player& player);

    private:
        bool isJumpingLeft;
    };
}


#endif //PROG3_RUNNINGJUMPSTATE_H
