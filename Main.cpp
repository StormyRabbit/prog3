//
// Created by lasse on 11/16/17.
//
#include "rootEngine/System/GameEngine.h"
#include "jumpyBoy/enemy/FlyingEnemy.h"
#include "jumpyBoy/enemy/WalkingEnemy.h"
#include "jumpyBoy/player/Player.h"
#include "jumpyBoy/hud/HUD.h"
#include "jumpyBoy/player/KeyBindings.h"
#include "jumpyBoy/CollisionStrategies/PlayerCollBehavior.h"
#include "jumpyBoy/CollisionStrategies/GroundBehavior.h"
#include "jumpyBoy/CollisionStrategies/FlyingEnemyBehavior.h"
#include "jumpyBoy/enemy/EnemyFactory.h"
#include "jumpyBoy/player/PlayerFactory.h"
#include "jumpyBoy/LevelFactory/LevelFactory.h"

using namespace rootengine;
LevelManager *createLvlMgr();

int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(jumpyboy::HUD::getInstance(ge));
    jumpyboy::Player *player = jumpyboy::PlayerFactory::player();
    jumpyboy::KeyBindings::bindKeybindings(ge, player);
    ge->setPlayer(player);
    ge->setFPS(60);
    ge->run();
    return 0;
}

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    typedef jumpyboy::LevelFactory getLvl;
    lvlMgr->addLevel(getLvl::firstLvl());
    lvlMgr->addLevel(getLvl::secondLvl());
    return lvlMgr;
}

