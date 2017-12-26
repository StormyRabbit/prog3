//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_USERINPUTCALLBACK_H
#define PROG3_USERINPUTCALLBACK_H

#include "UserInput.h"

namespace rootengine {
    class UserInputCallback {
    public:
        virtual void executeCallback() = 0;
        virtual UserInput* getUserInput() = 0;
    };
}


#endif //PROG3_USERINPUTCALLBACK_H
