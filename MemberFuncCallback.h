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
        static MemberFuncCallback *getInstance(T* inObj, void(T::*inf)()) {
            return new MemberFuncCallback(inObj );
        }
        UserInput* getUserInput() override;
    protected:
        MemberFuncCallback(T* aObj, void(T::*f)()): aObj(aObj), f(f) {

        }

    private:
        T* aObj;
        void (T::*f)();

    };
}

#endif //PROG3_MEMBERFUNCCALLBACK_H
