//
// Created by oskar on 13-Dec-17.
//

#ifndef PROG3_RUNNINGFALLSTATE_H
#define PROG3_RUNNINGFALLSTATE_H



#include "PlayerState.h"

namespace rootengine {

    class RunningFallState : public PlayerState{
    public:
        RunningFallState(bool isLeftBool);
        ~RunningFallState();
        PlayerState* handleInput(class Player& player, SDL_KeyboardEvent& keyEvent);
        void updateState(class Player& player);
        void enterState(class Player& player);

    private:
        int groundHeight = 430; //TODO MAKE RESOPONSIVE TO ACUAL CLOSES "GROUND"
        bool isFallingLeft;


    };
}



#endif //PROG3_RUNNINGFALLSTATE_H
