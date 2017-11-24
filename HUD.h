//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H


#include "Observer.h"
#include "HUDElement.h"

class HUD : public Observer {
public:
    void update(Subject subject) override;
    void addHUDElement(HUDElement* he);
    void setHUDElements(std::vector<HUDElement*> *hudElementList);
protected:

private:

};


#endif //PROG3_HUD_H
