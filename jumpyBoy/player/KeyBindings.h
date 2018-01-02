//
// Created by lasse on 1/2/18.
//

#ifndef PROG3_KEYBINDINGS_H
#define PROG3_KEYBINDINGS_H


#include "../../rootEngine/System/GameEngine.h"
#include "Player.h"
namespace jumpyboy {
    class KeyBindings {
    public:
        static KeyBindings *bindKeybindings(rootengine::GameEngine *, jumpyboy::Player *);
    private:
        KeyBindings() = default;
    };
}

#endif //PROG3_KEYBINDINGS_H
