//
// Created by lasse on 12/21/17.
//

#ifndef PROG3_TESTSTRUCT_H
#define PROG3_TESTSTRUCT_H

#include <SDL_keycode.h>

namespace rootengine {
    struct testStruct {
        void (*f)();
        template <typename aClass>
                void(aClass::*classF)();
        SDL_Keycode key;
        bool state;
    };
}

#endif //PROG3_TESTSTRUCT_H
