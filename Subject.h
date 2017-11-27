//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_SUBJECT_H
#define PROG3_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer *o);
    virtual void pushUpdate(Subject *s);
    virtual void getLife();
    virtual void getScore();
    virtual void getAmmo();
protected:
private:
    std::vector<class Observer*> observers;
};


#endif //PROG3_SUBJECT_H
