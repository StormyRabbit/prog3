//
// Created by lasse on 1/2/18.
//

#include "Controller.h"
namespace jumpyboy {

void Controller::setPlayer(Player *p) {
    aPlayer = p;
}

Controller *Controller::getInstance() {
    return new Controller();
}

    void Controller::upActionPressed() {
        aPlayer->handleEvent("up", true);
    }

    void Controller::upActionReleased() {
        aPlayer->handleEvent("up", false);
    }

    void Controller::downActionPressed() {
        aPlayer->handleEvent("down", true);
    }

    void Controller::downActionReleased() {
        aPlayer->handleEvent("down", false);
    }

    void Controller::leftActionPressed() {
        aPlayer->handleEvent("left", false);
    }

    void Controller::leftActionReleased() {
        aPlayer->handleEvent("left", false);
    }

    void Controller::rightActionPressed() {
        aPlayer->handleEvent("right", true);
    }

    void Controller::rightActionReleased() {
        aPlayer->handleEvent("right", false);
    }

    void Controller::jumpActionPressed() {
        aPlayer->handleEvent("jump", true);
    }

    void Controller::jumpACtionReleased() {
        aPlayer->handleEvent("jump", false);
    }

}
