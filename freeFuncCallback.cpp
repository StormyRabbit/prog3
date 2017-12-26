//
// Created by lasse on 12/26/17.
//

#include "freeFuncCallback.h"
namespace rootengine  {

    void freeFuncCallback::executeCallback() {
        (f)(usrInput);
    }


    freeFuncCallback::freeFuncCallback(UserInput *inUI, void (*inF)(UserInput *)) {
        usrInput = inUI;
        f = inF;
    }

    freeFuncCallback *freeFuncCallback::getInstance(UserInput *inUI, void (*inF)(UserInput *)) {

        return new freeFuncCallback(inUI, inF);
    }

    UserInput *freeFuncCallback::getUserInput() {
        return usrInput;
    }

    freeFuncCallback::ftype freeFuncCallback::getFuncCall() {
        return f;
    }
}