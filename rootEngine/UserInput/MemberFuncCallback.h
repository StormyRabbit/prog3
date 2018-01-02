//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_MEMBERFUNCCALLBACK_H
#define PROG3_MEMBERFUNCCALLBACK_H

#include "UserInputCallback.h"
#include "UserInput.h"

namespace rootengine {
    template <typename T>
    class MemberFuncCallback : public UserInputCallback {
    public:
        void executeCallback() override {
            (aObj->*f)();
        }
        static MemberFuncCallback *getInstance(SDL_Keycode k,bool b, T* inObj, void(T::*inf)()) {
            UserInput *ui = UserInput::getInstance(k,b);
            return new MemberFuncCallback(ui, inObj, inf);
        }

        UserInput* getUserInput() override {
            return userInput;
        }
    protected:
        MemberFuncCallback(UserInput *userInput, T* aObj, void(T::*f)()):userInput(userInput), aObj(aObj), f(f) {}
    private:
        UserInput *userInput{};
        T* aObj;
        void (T::*f)();
    };
}

#endif //PROG3_MEMBERFUNCCALLBACK_H
