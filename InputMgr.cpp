//
// Created by lasse on 12/21/17.
//

#include "InputMgr.h"


rootengine::InputMgr *rootengine::InputMgr::getInstance() {
    return new InputMgr();
}

void rootengine::InputMgr::executeBinding(SDL_Keycode) {


}

void rootengine::InputMgr::addBinding(rootengine::UserInput *ui) {
}

