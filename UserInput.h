//
// Created by lasse on 12/22/17.
//

#ifndef PROG3_USERINPUT_H
#define PROG3_USERINPUT_H

#include <SDL_keycode.h>

namespace rootengine {
    struct UserInput {
        void(*f)();
        SDL_Keycode key;
        bool state;
    };
}


#endif //PROG3_USERINPUT_H
