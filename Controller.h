//
// Created by lasse on 1/2/18.
//

#ifndef PROG3_CONTROLLER_H
#define PROG3_CONTROLLER_H


#include "player/Player.h"
class Controller {
public:
    void setPlayer(rootengine::Player *);
    void upActionPressed();
    void upActionReleased();
    void downActionPressed();
    void downActionReleased();
    void leftActionPressed();
    void leftActionReleased();
    void rightActionPressed();
    void rightActionReleased();
    void jumpActionPressed();
    void jumpACtionReleased();
    static Controller *getInstance();
protected:
    Controller() = default;
private:
    rootengine::Player *aPlayer;
};


#endif //PROG3_CONTROLLER_H
