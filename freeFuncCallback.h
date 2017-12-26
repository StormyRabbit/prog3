//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_FREEFUNCCALLBACK_H
#define PROG3_FREEFUNCCALLBACK_H

#include "UserInputCallback.h"
#include "UserInput.h"

namespace rootengine {

    class freeFuncCallback : public UserInputCallback {
    public:
        void executeCallback() override;
        static freeFuncCallback *getInstance(UserInput *inUI, void(*inF)(UserInput*));
        UserInput *getUserInput() override;
        typedef void (*ftype)(UserInput *);
        ftype getFuncCall();
    protected:
        freeFuncCallback(UserInput *inUI, void(*inF)(UserInput*));
    private:
        UserInput *usrInput;
        void (*f)(UserInput*);
    };
}


#endif //PROG3_FREEFUNCCALLBACK_H
