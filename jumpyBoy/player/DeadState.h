//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_DEADSTATE_H
#define PROG3_DEADSTATE_H

#include "PlayerState.h"

namespace jumpyboy {
    class DeadState : public PlayerState {
    public:
        DeadState();
        ~DeadState();
        PlayerState* handleInput(Player &player, std::string action, bool isDown) override;
        void enterState(Player &player) override;

        void updateState(Player &player) override;
    };
}

#endif //PROG3_DEADSTATE_H
