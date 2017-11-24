//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_OBSERVER_H
#define PROG3_OBSERVER_H


#include "Subject.h"

class Observer {
    virtual void update(Subject subject) = 0;
};


#endif //PROG3_OBSERVER_H
