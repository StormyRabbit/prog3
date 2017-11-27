//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H


#include "HUDElement.h"

class HUD {
public:
    void addHUDElement(HUDElement* he);
    void setHUDElements(std::vector<HUDElement*> *hudElementList);
protected:

private:

};


#endif //PROG3_HUD_H
