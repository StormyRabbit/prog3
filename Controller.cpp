//
// Created by lasse on 1/2/18.
//

#include "Controller.h"

void Controller::setPlayer(rootengine::Player *p) {
    aPlayer = p;
}

Controller *Controller::getInstance() {
    return new Controller();
}
