//
// Created by lasse on 1/2/18.
//

#include "KeyBindings.h"
namespace jumpyboy {

    KeyBindings *KeyBindings::bindKeybindings(rootengine::GameEngine *ge, jumpyboy::Player *p) {
        typedef jumpyboy::Controller contr;
        typedef rootengine::MemberFuncCallback<jumpyboy::Controller> cb;
        contr *cObj = jumpyboy::Controller::getInstance();
        cObj->setPlayer(p);
        ge->addEvent(cb::getInstance(SDLK_w, true, cObj, &contr::upActionPressed));
        ge->addEvent(cb::getInstance(SDLK_w, true, cObj, &contr::upActionPressed));
        ge->addEvent(cb::getInstance(SDLK_w, false, cObj, &contr::upActionReleased));
        ge->addEvent(cb::getInstance(SDLK_a, true, cObj, &contr::leftActionPressed));
        ge->addEvent(cb::getInstance(SDLK_a, false, cObj, &contr::leftActionReleased));
        ge->addEvent(cb::getInstance(SDLK_s, true, cObj, &contr::downActionPressed));
        ge->addEvent(cb::getInstance(SDLK_s, false, cObj, &contr::downActionReleased));
        ge->addEvent(cb::getInstance(SDLK_d, true, cObj, &contr::rightActionPressed));
        ge->addEvent(cb::getInstance(SDLK_d, false, cObj, &contr::rightActionReleased));
        ge->addEvent(cb::getInstance(SDLK_SPACE, true, cObj, &contr::jumpActionPressed));
        ge->addEvent(cb::getInstance(SDLK_SPACE, false, cObj, &contr::jumpActionReleased));
    }

}