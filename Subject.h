//
// Created by lasse on 27.11.2017.
// https://www.codeproject.com/Articles/328365/Understanding-and-Implementing-Observer-Pattern
//

#ifndef PROG3_SUBJECT_H
#define PROG3_SUBJECT_H


#include <vector>
#include "Observer.h"
namespace rootengine {
    class Subject {
        std::vector<Observer *> observerList;

    public:
        void attach(Observer *obs);

        void detach(Observer *obs);

        void notify();
    };
}

#endif //PROG3_SUBJECT_H
