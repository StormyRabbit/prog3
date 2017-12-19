//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
using namespace rootengine;
HUD *createHUD(GameEngine* game);
LevelManager *createLvlMgr();
Player *createPlayer();
Level *createFirstLevel();
Level *createSecondLevel();


int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(createHUD(ge));
    ge->setPlayer(createPlayer());
    ge->setFPS(60, 1000);
    ge->run();
    return 0;
}
Player *createPlayer() {
    return Player::getInstance(100,430,50,70, "assets/sprites/Player/p1_front.png");
}

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    lvlMgr->addLevel(createFirstLevel());
    lvlMgr->addLevel(createSecondLevel());
    return lvlMgr;
}

Level *createFirstLevel() {
    Level* aLvl = Level::getInstance();
    aLvl->addCollEnv(EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/grassMid.png"));
    aLvl->setBackGround(EnvironmentSprite::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));
    return aLvl;
}

Level *createSecondLevel() {
    Level* aLvl = Level::getInstance();
    aLvl->addCollEnv(EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/sand.png"));
    aLvl->setBackGround(   EnvironmentSprite::getInstance(0, 0, 1200, 600, "assets/sprites/i-know-c.jpg"));
    return aLvl;
}

HUD *createHUD(GameEngine* game) {
    // TODO: lägg till restsen av hud
    HUD* hud = HUD::getInstance();
    HUDSprite* lasse = HUDSprite::getInstance(500,280,200,20, "LASSE > osCar");
    HUDSprite* scoreSprite = HUDSprite::getInstance(0,0,200,20, "SCORE: ");
    scoreSprite->setValueToObserver(game, &GameEngine::getScore);
    HUDSprite* lifeSprite = HUDSprite::getInstance(0,20,200,20, "CURRENT LIFE: ");
    HUDSprite* enemyLeft = HUDSprite::getInstance(500,0,200,20, "ENEMIES LEFT: ");
    hud->addHUDElement(scoreSprite);
    hud->addHUDElement(lifeSprite);
    hud->addHUDElement(lasse);
    hud->addHUDElement(enemyLeft);

    return hud;
}

