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
    HUD* hud = createHUD();
    LevelManager* lvlMgr = createLvlMgr();
    Player* player = createPlayer();
    auto* ge = new GameEngine();
    ge->setLvlMgr(lvlMgr);
    ge->setHUD(hud);
    ge->run();
    return 0;
}

rootengine::Player *createPlayer() {
    // TODO: dra ut skapandet av spelarobjektet
    return nullptr;
}

rootengine::LevelManager *createLvlMgr() {
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

rootengine::HUD *createHUD() {
    // TODO: lägg till restsen av hud
    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(200,200,200,20, "LASSE > osCar");
    hud->addHUDElement(lasse);
    return hud;
}

