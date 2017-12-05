//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
#include "System.h"
#include "HUDSprite.h"

using namespace rootengine;

int main(int, char **) {

    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(200,200,200,20, "GIT GOD LASSE");
    hud->addHUDElement(lasse);
    auto* ge = new GameEngine();
    ge->setHUD(hud);
    ge->run();
    return 0;
}

