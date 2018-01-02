//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_PLAYERSTATE_H
#define PROG3_PLAYERSTATE_H

#include <SDL.h>
#include "Player.h"

namespace jumpyboy {
    class PlayerState {
    public:
        ~PlayerState();
        virtual PlayerState *handleInput(class Player &player, std::string action, bool isDown); //Tried removing class before Player&
        virtual void updateState(class Player& player);
        virtual void enterState(class Player& player);
    protected:
        PlayerState();
    };
}


#endif //PROG3_PLAYERSTATE_H
