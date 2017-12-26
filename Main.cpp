//
// Created by lasse on 11/16/17.
//
#include <iostream>
#include "GameEngine.h"
#include "freeFuncCallback.h"
#include "MemberFuncCallback.h"

using namespace rootengine;
HUD *createHUD(GameEngine* game);
LevelManager *createLvlMgr();
Player *createPlayer();
Level *createFirstLevel();
Level *createSecondLevel();
UserInputMgr *createUIM(GameEngine *);

void testFunc(UserInput *) {
    std::cout << "TEST FUNC";
}

int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(createHUD(ge));
    ge->setPlayer(createPlayer());
    ge->setFPS(60);
    ge->setUsrInMgr(createUIM(ge));
    ge->run();
    return 0;
}

UserInputMgr *createUIM(GameEngine *ge) {
    UserInputMgr *uimgr = UserInputMgr::getInstance();
    UserInput *ui = UserInput::getInstance(SDLK_t, true);
    rootengine::freeFuncCallback *asd = freeFuncCallback::getInstance(ui, testFunc);
    UserInput *mUI = UserInput::getInstance(SDLK_g, true);
    rootengine::MemberFuncCallback<GameEngine> *test = MemberFuncCallback<GameEngine>::getInstance(mUI, ge, &GameEngine::printScore);
    uimgr->addEvent(test);
    uimgr->addEvent(asd);
    return uimgr;
}

Player *createPlayer() {

    std::vector<SDL_Rect> runningFrames{{0,0,67,92},{67,0,66,93},{133,0,67,92},{0,93,67,93},{133,93,71,92},{133,93,71,92},{0,186,71,93},{71,186,71,93},{142,186,70,93},{0,279,71,93},{71,279,67,92}};
    std::vector<SDL_Rect> standingFrames{{0,0,66,92}};
    std::vector<SDL_Rect> dodgingFrames{{0,0,69,71}};
    std::vector<SDL_Rect> jumpingFrames{{0,0,67,94}};
    std::vector<SDL_Rect> fallingFrames{{0,0,67,94}};

    std::map<std::string, std::vector<SDL_Rect>> frameRects;
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("running", runningFrames));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("standing", standingFrames));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("dodging", dodgingFrames));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("jumping", jumpingFrames));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("falling", fallingFrames));

    std::map<std::string, std::string> playerSprites;
    playerSprites.insert(std::pair<std::string, std::string>("standing", "assets/sprites/Player/p1_front.png"));
    playerSprites.insert(std::pair<std::string, std::string>("running", "assets/sprites/Player/p1_walk/p1_walk.png"));
    playerSprites.insert(std::pair<std::string, std::string>("dodging", "assets/sprites/Player/p1_duck.png"));
    playerSprites.insert(std::pair<std::string, std::string>("jumping", "assets/sprites/Player/p1_jump.png"));
    playerSprites.insert(std::pair<std::string, std::string>("falling", "assets/sprites/Player/p1_jump.png"));
    return Player::getInstance(100,430,50,70, playerSprites, frameRects);
}

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    lvlMgr->addLevel(createFirstLevel());
    lvlMgr->addLevel(createSecondLevel());
    return lvlMgr;
}

Level *createFirstLevel() {
    Level* aLvl = Level::getInstance();
    aLvl->addCollEnv(EnvironmentSprite::getInstance(500, 420, 200, 20, "assets/sprites/Tiles/grassMid.png"));
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
    HUD* hud = HUD::getInstance();
    HUDSprite* scoreSprite = HUDSprite::getInstance(0,0,200,20, "SCORE: ");
    scoreSprite->setValueToObserver(game, &GameEngine::getScore);
    HUDSprite* lifeSprite = HUDSprite::getInstance(0,20,200,20, "CURRENT LIFE: ");
    HUDSprite* enemyLeft = HUDSprite::getInstance(500,0,200,20, "ENEMIES LEFT: ");
    hud->addHUDElement(scoreSprite);
    hud->addHUDElement(lifeSprite);
    hud->addHUDElement(enemyLeft);

    return hud;
}

