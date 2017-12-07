//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
#include "System.h"
rootengine::HUD *createHUD();
rootengine::LevelManager *createLvlMgr();
rootengine::Player *createPlayer();
std::vector<rootengine::Level *> createLvlColl();
using namespace rootengine;

int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(createHUD());
    ge->setPlayer(createPlayer());
    ge->run();
    return 0;
}

Player *createPlayer() {
    // TODO: lägg till så sprite URL används i konstruktorn
    return Player::getInstance(100,450,50,50);
}

LevelManager *createLvlMgr() {
    // TODO: dra ut lvlSkapandet
    LevelManager* lvlMgr = LevelManager::getInstance();
    std::vector<Level*> lvlColl = createLvlColl();
    lvlMgr->setLevelCollection(lvlColl);
    return lvlMgr;
}

std::vector<Level *> createLvlColl() {
    std::vector<Level *> lvlColl;
    lvlColl.push_back(nullptr); // INSERTLVL
    return lvlColl;
}

HUD *createHUD() {
    // TODO: lägg till restsen av hud
    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(200,200,200,20, "LASSE > osCar");
    hud->addHUDElement(lasse);
    return hud;
}

