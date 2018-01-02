//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_USERINPUTMGR_H
#define PROG3_USERINPUTMGR_H

#include <SDL_events.h>
#include <unordered_map>
#include "UserInput.h"
#include "UserInputCallback.h"
#include "freeFuncCallback.h"
#include "MemberFuncCallback.h"

namespace rootengine {
    class UserInputMgr {
    public:
        void handleEvent(SDL_Event &e);
        void addEvent(UserInputCallback *);
        static UserInputMgr *getInstance();
    protected:
        UserInputMgr() = default;
    private:
        std::unordered_map<std::string, UserInputCallback*> callbackMap;
    };
}

#endif //PROG3_USERINPUTMGR_H
