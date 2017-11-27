//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_OBSERVER_H
#define PROG3_OBSERVER_H


#include "Subject.h"

class Observer {
public:
    virtual void update(Subject subj) = 0;

protected:
private:
};


#endif //PROG3_OBSERVER_H
