//
// Created by lasse on 12/22/17.
//

#ifndef PROG3_INPUTHANDLER_H
#define PROG3_INPUTHANDLER_H


#include <SDL_keycode.h>
#include "UserInput.h"
#include "UserInputMemberFunction.h"
#include <map>
#include <SDL_events.h>

namespace rootengine {
    class InputHandler {
    public:
        void handleInput(SDL_Event &);
        void addUserInput(UserInput *);
        void addUserInput(SDL_Keycode, VirtualUserInput *);
        static InputHandler *getInstance();
    protected:
        InputHandler() = default;
    private:
        std::map<SDL_Keycode, VirtualUserInput*> memberInput;
        std::map<SDL_Keycode, UserInput *> inputMap;
    };
}


#endif //PROG3_INPUTHANDLER_H
