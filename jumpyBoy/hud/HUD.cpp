//
// Created by lasse on 11/24/17.
//

#include <vector>
#include "HUD.h"
#include <algorithm>
namespace jumpyboy {

    void HUD::addHUDElement(rootengine::HUDSprite *he) {
        hudElements.push_back(he);
    }

    HUD *HUD::getInstance(rootengine::GameEngine *game) {
        return new HUD(game);
    }

    void HUD::draw() {
        for(rootengine::HUDSprite *hs : hudElements)
            hs->draw();
    }

    HUD::~HUD() {
        for(rootengine::HUDSprite *hs : hudElements)
            delete hs;
    }

    HUD::HUD(rootengine::GameEngine *game) {
        rootengine::HUDSprite* scoreSprite = rootengine::HUDSprite::getInstance(0,0,200,20, "SCORE: ");
        scoreSprite->setValueToObserver(game, &rootengine::GameEngine::getScore);
        rootengine::HUDSprite* lifeSprite = rootengine::HUDSprite::getInstance(0,20,200,20, "CURRENT LIFE: ");
        lifeSprite->setValueToObserver(game, &rootengine::GameEngine::getLives);
        rootengine::HUDSprite* enemyLeft = rootengine::HUDSprite::getInstance(500,0,200,20, "ENEMIES LEFT: ");
        addHUDElement(scoreSprite);
        addHUDElement(lifeSprite);
        addHUDElement(enemyLeft);
    }
}

