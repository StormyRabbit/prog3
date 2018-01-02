//
// Created by Oskar on 2017-12-10.
//

#ifndef PROG3_DODGINGSTATE_H
#define PROG3_DODGINGSTATE_H

#include "PlayerState.h"

namespace jumpyboy{

    class DodgingState : public PlayerState {
    public:
        DodgingState();
        ~DodgingState();
        PlayerState* handleInput(class Player &player, std::string action, bool isDown);
        void updateState(class Player& player);
        void enterState(class Player& player);

    private:
        int nonDodgingHeight;
    };
}


#endif //PROG3_DODGINGSTATE_H
