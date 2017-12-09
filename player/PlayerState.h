//
// Created by lasse on 12/5/17.
//

#ifndef PROG3_PLAYERSTATE_H
#define PROG3_PLAYERSTATE_H

#include <SDL.h>
#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "DeadState.h"
#include "FallingState.h"
#include "DodgingState.h"
#include "Player.h"

namespace rootengine{
    class PlayerState {
    public:
        static StandingState standing;
        static RunningState running;
        static JumpingState jumping;
        static FallingState falling;
        static DeadState dead;
        static DodgingState dodging;
        virtual PlayerState* handleInput(Player& player, SDL_KeyboardEvent keysum);



        //standing, running, jumping, runningJump, attacking, dodging, dead, falling
    };
}


#endif //PROG3_PLAYERSTATE_H
