//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
#include "System.h"
using namespace rootengine;
HUD *createHUD();
LevelManager *createLvlMgr();
Player *createPlayer();
std::vector<Level *> createLvlColl();
Level *createFirstLevel();
Level *createSecondLevel();


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
    return Player::getInstance(100,450,50,50, "assets/sprites/Player/p1_front.png");
}

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    std::vector<Level*> lvlColl = createLvlColl();
    lvlMgr->setLevelCollection(lvlColl);
    return lvlMgr;
}

std::vector<Level *> createLvlColl() {
    std::vector<Level *> lvlColl;
    Level* firstLevel = createFirstLevel();
    lvlColl.push_back(firstLevel);
    lvlColl.push_back(createSecondLevel());

    return lvlColl;
}

Level *createFirstLevel() {
    std::vector<EnvironmentSprite *> collEnv;
    collEnv.push_back(EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/grassMid.png"));

    std::vector<EnvironmentSprite *> nonCollEnv;
    nonCollEnv.push_back(EnvironmentSprite::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));
    Level* aLvl = Level::getEnemeyFreeLevel(collEnv, nonCollEnv);
    return aLvl;
}

Level *createSecondLevel() {
    std::vector<EnvironmentSprite *> collEnv;
    collEnv.push_back(EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/sand.png"));

    std::vector<EnvironmentSprite *> nonCollEnv;
    nonCollEnv.push_back(EnvironmentSprite::getInstance(0, 0, 1200, 600, "assets/sprites/i-know-c.jpg"));
    Level* aLvl = Level::getEnemeyFreeLevel(collEnv, nonCollEnv);
    return aLvl;
}

HUD *createHUD() {
    // TODO: lägg till restsen av hud
    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(500,280,200,20, "LASSE > osCar");
    HUDSprite* scoreSprite = HUDSprite::getInstance(0,0,200,20, "SCORE: ");
    HUDSprite* lifeSprite = HUDSprite::getInstance(0,20,200,20, "CURRENT LIFE: ");
    HUDSprite* enemyLeft = HUDSprite::getInstance(500,0,200,20, "ENEMIES LEFT: ");
    hud->addHUDElement(scoreSprite);
    hud->addHUDElement(lifeSprite);
    hud->addHUDElement(lasse);
    hud->addHUDElement(enemyLeft);

    return hud;
}

