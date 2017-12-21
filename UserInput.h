//
// Created by lasse on 12/21/17.
//

#ifndef PROG3_USERINPUT_H
#define PROG3_USERINPUT_H

#include <SDL_keycode.h>

namespace rootengine {

    template <typename aClass>
    class UserInput {
    public:
        void executeCallback() {
            if(freeFunc != nullptr)
                (*freeFunc)(key, state);
            if(classFunc != nullptr)
                (obj->*classFunc)(key, state);
        }
        void setCallback(aClass *aObj, void(aClass:: *f)(SDL_Keycode, bool)) {
            if(freeFunc != nullptr)
                freeFunc = nullptr;
            obj = aObj;
            classFunc = f;
        }

        void setCallback(void(*f)(SDL_Keycode, bool)) {
            freeFunc = f;
            if(classFunc != nullptr)
                classFunc = nullptr;
        }

        static UserInput* getInstance(SDL_Keycode inKey, bool inState) {
            return new UserInput<aClass>(inKey, inState);
        }
        ~UserInput() {
            delete obj;
            delete freeFunc;
            delete classFunc;
        }

    protected:
        UserInput(SDL_Keycode inKey, bool inState) {
            key = inKey;
            state = inState;
        }

    private:
        SDL_Keycode key;
        bool state;
        aClass *obj;
        void(*freeFunc)(SDL_Keycode, bool) {};
        void(aClass::*classFunc)(SDL_Keycode, bool);
    };
}
#endif //PROG3_USERINPUT_H
