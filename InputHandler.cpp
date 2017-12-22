//
// Created by lasse on 12/22/17.
//

#include <iostream>
#include "InputHandler.h"
namespace rootengine {

    void InputHandler::addUserInput(rootengine::UserInput *ui) {
        inputMap.insert(std::pair<SDL_Keycode , UserInput *>(ui->key, ui));
    }

    void InputHandler::handleInput(SDL_Event &e) {
        auto it = memberInput.find(e.key.keysym.sym);
        if(it != memberInput.end())
            it->second->executeCallback();
    }

    InputHandler *InputHandler::getInstance() {
        return new InputHandler();
    }

    void InputHandler::addUserInput(SDL_Keycode k, VirtualUserInput *ui) {
        memberInput.insert(std::pair<SDL_Keycode, VirtualUserInput *>(k, ui));

    }

}
