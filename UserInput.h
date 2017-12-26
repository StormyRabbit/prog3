//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_USERINPUT_H
#define PROG3_USERINPUT_H


#include <SDL_keycode.h>
#include <SDL_events.h>
#include <string>
namespace rootengine {
    class UserInput {
    public:
        SDL_Event getAsEvent();
        static UserInput *getInstance(SDL_Keycode, bool pressed);
        static UserInput *getInstance(SDL_Event &);
        std::string toString();
    protected:
        explicit UserInput(SDL_Event &);
    private:
        std::string asString{};
        SDL_KeyboardEvent ke;
    };
}


#endif //PROG3_USERINPUT_H
