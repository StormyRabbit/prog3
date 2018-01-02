//
// Created by lasse on 12/26/17.
//

#include "UserInput.h"
namespace rootengine {
    UserInput *UserInput::getInstance(SDL_Event &e) {
        return new UserInput(e);
    }

    UserInput::UserInput(SDL_Event &e):ke(e.key), asString(std::to_string(e.key.keysym.sym) + std::to_string(e.key.type)) {

    }

    SDL_Event UserInput::getAsEvent() {
        SDL_Event result;
        result.key = ke;
        return result;
    }

    UserInput *UserInput::getInstance(SDL_Keycode k, bool pressed) {
        SDL_Event event;
        event.key.keysym.sym = k;
        if(pressed)
            event.key.type = SDL_KEYDOWN;
        else
            event.key.type = SDL_KEYUP;
        return new UserInput(event);
    }

    std::string UserInput::toString() {
        return asString;
    }
}