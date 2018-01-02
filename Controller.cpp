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

}
