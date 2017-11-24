//
// Created by lasse on 11/24/17.
//

#include <vector>
#include "HUD.h"
#include "HUDElement.h"

std::vector<HUDElement*> *hudElements;
void HUD::update(Subject subject) {
    for(HUDElement* he : *hudElements){

    }
}


void HUD::addHUDElement(HUDElement* he) {
    hudElements->push_back(he);
}

void HUD::setHUDElements(std::vector<HUDElement *> *hudElementList) {
    hudElements = hudElementList;
}

