//
// Created by lasse on 12/21/17.
//

#ifndef PROG3_INPUTMGR_H
#define PROG3_INPUTMGR_H

#include "UserInput.h"
#include <vector>
#include <SDL_events.h>
#include <map>

namespace rootengine {
    class InputMgr {
    public:
        void executeBinding(SDL_Keycode);
        void addBinding(UserInput *);
        static InputMgr* getInstance();
    protected:
        InputMgr() = default;

    private:
        std::map<SDL_Keycode, UserInput *> callBack;

    };

}


#endif //PROG3_INPUTMGR_H
