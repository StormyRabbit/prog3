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
        aPlayer->handleInput("up", true);
    }

    void Controller::upActionReleased() {
        aPlayer->handleInput("up", false);
    }

    void Controller::downActionPressed() {
        aPlayer->handleInput("down", true);
    }

    void Controller::downActionReleased() {
        aPlayer->handleInput("down", false);
    }

    void Controller::leftActionPressed() {
        aPlayer->handleInput("left", true);
    }

    void Controller::leftActionReleased() {
        aPlayer->handleInput("left", false);
    }

    void Controller::rightActionPressed() {
        aPlayer->handleInput("right", true);
    }

    void Controller::rightActionReleased() {
        aPlayer->handleInput("right", false);
    }

    void Controller::jumpActionPressed() {
        aPlayer->handleInput("jump", true);
    }

    void Controller::jumpActionReleased() {
        aPlayer->handleInput("jump", false);
    }

}
