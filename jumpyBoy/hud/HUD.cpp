//
// Created by lasse on 11/24/17.
//

#include <vector>
#include "HUD.h"
#include "../../rootEngine/sprite/ObserveringHUDSprite.h"
#include <algorithm>
namespace jumpyboy {

    void HUD::addHUDElement(rootengine::HUDSprite *he) {
        hudElements.push_back(he);
    }

    HUD *HUD::getInstance(Player *p) {
        return new HUD(p);
    }

    void HUD::draw() {
        for(rootengine::HUDSprite *hs : hudElements) {
            hs->update();
            hs->draw();
        }
    }

    HUD::~HUD() {
        for(rootengine::HUDSprite *hs : hudElements)
            delete hs;
    }

    HUD::HUD(Player *player) {
        rootengine::HUDSprite* scoreSprite = rootengine::HUDSprite::getInstance(0,0,200,20, "SCORE: ");
        std::string test = "LIVES: ";
        typedef rootengine::ObservingHUDSprite<Player> hudPlayer;
        hudPlayer *testSprite = hudPlayer::getInstance(0, 20, 200, 20, test, player, &Player::getLifesLeft);
        rootengine::HUDSprite* enemyLeft = rootengine::HUDSprite::getInstance(500,0,200,20, "ENEMIES LEFT: ");
        addHUDElement(scoreSprite);
        addHUDElement(testSprite);
        addHUDElement(enemyLeft);
    }
}

