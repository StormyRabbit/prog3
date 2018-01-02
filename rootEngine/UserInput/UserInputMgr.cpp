//
// Created by lasse on 12/26/17.
//

#include <iostream>
#include "UserInputMgr.h"

namespace rootengine {

    UserInputMgr *UserInputMgr::getInstance() {
        return new UserInputMgr();
    }

    void UserInputMgr::handleEvent(SDL_Event &e) {
        UserInput *ui = UserInput::getInstance(e);

        std::unordered_map<std::string,UserInputCallback*>::const_iterator got = callbackMap.find(ui->toString());
        if(got != callbackMap.end())
            got->second->executeCallback();
    }

    void UserInputMgr::addEvent(UserInputCallback *uic) {
        callbackMap.insert(std::pair<std::string, UserInputCallback*>(uic->getUserInput()->toString(), uic));

    }
}