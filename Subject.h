//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_SUBJECT_H
#define PROG3_SUBJECT_H


#include "Observer.h"

class Subject {
    virtual void addObserver(Observer o) = 0;
    virtual void pushUpdate(Subject s) = 0;
    virtual void getLife() = 0;
    virtual void getScore() = 0;
    virtual void getAmmo() = 0;

};


#endif //PROG3_SUBJECT_H
