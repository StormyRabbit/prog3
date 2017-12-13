//
// Created by lasse on 11/24/17.
//

#include <vector>
#include "HUD.h"
#include <algorithm>
namespace rootengine {

    void HUD::addHUDElement(HUDSprite *he) {
        hudElements.push_back(he);
    }

    void HUD::setHUDElements(std::vector<HUDSprite *> hudElementList) {
        hudElements = hudElementList;
    }

    void HUD::update() {

    }

    HUD::HUD() {

    }

    HUD *HUD::getInstance() {
        return new HUD();
    }

    void HUD::draw() {
        for(HUDSprite *hs : hudElements)
            hs->draw();
    }


    void Observer::update() {
        // TODO FIX
        /*
        for (std::vector<HUDSprite *>::const_iterator iter = hudElements.begin();
             iter != hudElements.end(); ++iter) {
            if (*iter != 0) {
                // TODO execute
            }
        }
         */
    }
}

