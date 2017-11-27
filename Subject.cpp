//
// Created by lasse on 27.11.2017.
//

#include "Subject.h"

#include "Subject.h"
#include <algorithm>

void Subject::attach(Observer *obs) {
    observerList.push_back(obs);
}

void Subject::detach(Observer *obs) {
    observerList.erase(std::remove(observerList.begin(),
                                   observerList.end(), obs), observerList.end());
}

void Subject::notify() {
    for(std::vector<Observer*>::const_iterator iter = observerList.begin();
        iter != observerList.end(); ++iter){
        if(*iter != 0) {
            (*iter)->update();
        }
    }
}