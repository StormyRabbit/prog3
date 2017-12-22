//
// Created by lasse on 12/22/17.
//

#ifndef PROG3_USERINPUTMEMBERFUNCTION_H
#define PROG3_USERINPUTMEMBERFUNCTION_H

#include <SDL_keycode.h>
#include "VirtualUserInput.h"

template <typename aClass>
class UserInputMemberFunction : public VirtualUserInput {
public:
    void executeCallback();
    UserInputMemberFunction(aClass* obj, void(aClass::*mfp)(),
                            SDL_Keycode k, bool b) {
        aObj = obj;
        classF = mfp;
        key = k;
        state = b;
    }

protected:
private:
    SDL_Keycode key;
    bool state;
    void(aClass::*classF)();
    aClass *aObj;
};

template<typename aClass>
void UserInputMemberFunction<aClass>::executeCallback() {
    (aObj->*classF)();
}


#endif //PROG3_USERINPUTMEMBERFUNCTION_H
