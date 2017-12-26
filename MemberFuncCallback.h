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
            (aObj->*f)(usrInput);
        }
        static MemberFuncCallback *getInstance(UserInput *ui, T* inObj, void(T::*inf)(UserInput*)) {
            return new MemberFuncCallback(ui, inObj, inf);
        }
        UserInput* getUserInput() override;
    protected:
        MemberFuncCallback(UserInput *ui, T* inObj, void(T::*inf)(UserInput*)) {
            usrInput = ui;
            aObj = inObj;
            f = inf;
        }

    private:
        UserInput* usrInput;
        T* aObj;
        void (T::*f)(UserInput*);

    };

    template<typename T>
    UserInput *MemberFuncCallback<T>::getUserInput() {
        return usrInput;
    }
}

#endif //PROG3_MEMBERFUNCCALLBACK_H
