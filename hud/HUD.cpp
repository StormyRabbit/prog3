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

    HUD *HUD::getInstance() {
        return new HUD();
    }

    void HUD::draw() {
        for(HUDSprite *hs : hudElements)
            hs->draw();
    }

    HUD::~HUD() {
        for(HUDSprite *hs : hudElements)
            delete hs;
    }
}

