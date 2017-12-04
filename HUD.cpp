//
// Created by lasse on 11/24/17.
//

#include <vector>
#include "HUD.h"
#include "HUDElement.h"
#include <algorithm>
namespace rootengine {
    std::vector<HUDElement *> hudElements;


    void HUD::addHUDElement(HUDElement *he) {
        hudElements.push_back(he);
    }

    void HUD::setHUDElements(std::vector<HUDElement *> hudElementList) {
        hudElements = hudElementList;
    }

    void Observer::update() {
        for (std::vector<HUDElement *>::const_iterator iter = hudElements.begin();
             iter != hudElements.end(); ++iter) {
            if (*iter != 0) {
                // TODO execute
            }
        }
    }
}

