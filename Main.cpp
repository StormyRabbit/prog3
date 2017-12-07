//
// Created by lasse on 11/16/17.
//
#include <assert.h>
#include "GameEngine.h"
#include "System.h"
using namespace rootengine;
HUD *createHUD();
LevelManager *createLvlMgr();
Player *createPlayer();
std::vector<Level *> createLvlColl();
Level *createFirstLevel();


int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(createHUD());
    ge->setPlayer(createPlayer());
    ge->setFPS(60, 1000);
    ge->run();
    return 0;
}
Player *createPlayer() {
    // TODO: lägg till så sprite URL används i konstruktorn
    return Player::getInstance(100,450,50,50);
}

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    std::vector<Level*> lvlColl = createLvlColl();
    assert(lvlColl[0]);
    lvlMgr->setLevelCollection(lvlColl);
    return lvlMgr;
}

std::vector<Level *> createLvlColl() {
    std::vector<Level *> lvlColl;
    Level* firstLevel = createFirstLevel();
    lvlColl.push_back(firstLevel);
    return lvlColl;
}

Level *createFirstLevel() {
    std::vector<EnvironmentSprite *> collEnv;
    collEnv.push_back(EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/grassMid.png"));

    std::vector<EnvironmentSprite *> nonCollEnv;
    nonCollEnv.push_back(EnvironmentSprite::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));
    Level* aLvl = Level::getEnemeyFreeLevel(collEnv, nonCollEnv);
    assert(aLvl);
    return aLvl;
}

HUD *createHUD() {
    // TODO: lägg till restsen av hud
    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(200,200,200,20, "LASSE > osCar");
    hud->addHUDElement(lasse);
    return hud;
}

