//
// Created by lasse on 11/16/17.
//
#include <iostream>
#include "rootEngine/System/GameEngine.h"
#include "rootEngine/UserInput/freeFuncCallback.h"
#include "rootEngine/UserInput/MemberFuncCallback.h"
#include "enemy/FlyingEnemy.h"
#include "enemy/WalkingEnemy.h"
#include "jumpyBoy/player/Player.h"
#include "jumpyBoy/hud/HUD.h"
#include "rootEngine/collision/GroundBehaivor.h"

using namespace rootengine;
LevelManager *createLvlMgr();
jumpyboy::Player *createPlayer();
Level *createFirstLevel();
Level *createSecondLevel();
UserInputMgr *createUIM(jumpyboy::Player *);

int main(int, char **) {
    auto* ge = GameEngine::getInstance();
    ge->createWorld();
    ge->setLvlMgr(createLvlMgr());
    ge->setHUD(jumpyboy::HUD::getInstance(ge));
    jumpyboy::Player *player = createPlayer();
    ge->setUsrInMgr(createUIM(player));
    ge->setPlayer(player);
    ge->setFPS(60);
    ge->run();
    return 0;
}

UserInputMgr *createUIM(jumpyboy::Player *p) {
    typedef jumpyboy::Controller contr;
    typedef MemberFuncCallback<jumpyboy::Controller> cb;
    UserInputMgr *uimgr = UserInputMgr::getInstance();
    contr *c = jumpyboy::Controller::getInstance();
    c->setPlayer(p);
    p->setController(c);
    /*rootengine::freeFuncCallback *asd = freeFuncCallback::getInstance(ui, testFunc);*/
    uimgr->addEvent(cb::getInstance(SDLK_w, true, c, &contr::upActionPressed));
    uimgr->addEvent(cb::getInstance(SDLK_w, false, c, &contr::upActionReleased));
    uimgr->addEvent(cb::getInstance(SDLK_a, true, c, &contr::leftActionPressed));
    uimgr->addEvent(cb::getInstance(SDLK_a, false, c, &contr::leftActionReleased));
    uimgr->addEvent(cb::getInstance(SDLK_s, true, c, &contr::downActionPressed));
    uimgr->addEvent(cb::getInstance(SDLK_s, false, c, &contr::downActionReleased));
    uimgr->addEvent(cb::getInstance(SDLK_d, true, c, &contr::rightActionPressed));
    uimgr->addEvent(cb::getInstance(SDLK_d, false, c, &contr::rightActionReleased));
    uimgr->addEvent(cb::getInstance(SDLK_SPACE, true, c, &contr::jumpActionPressed));
    uimgr->addEvent(cb::getInstance(SDLK_SPACE, false, c, &contr::jumpActionReleased));
    return uimgr;
}

jumpyboy::Player *createPlayer() {
    //Changes player moving speed, gravity and fall. MUST HAVE KEYS: gravity, runningSpeed, jumpPower
    std::map<std::string, double> movingVariables;
    movingVariables.insert(std::pair<std::string, double>("gravity", 0.2));
    movingVariables.insert(std::pair<std::string, double>("runningSpeed", 5));
    movingVariables.insert(std::pair<std::string, double>("jumpPower", 7));

    //MUST CONTAIN SAME KEYS AS playerSprites!! Contains all positions there are sprites in spritesheet, if not sprite sheet just use position 0,0,PictureWitdh,PictureHeight.
    std::vector<SDL_Rect> runningFrames{{0,0,67,92},{67,0,66,93},{133,0,67,92},{0,93,67,93},{133,93,71,92}, {133,93,71,92},{0,186,71,93},{71,186,71,93},{142,186,70,93},{0,279,71,93},{71,279,67,92}};
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

    //Path to all sprite sheets. MUST HAVE CORRESPONDING VECTORS IN frameRects WITH SAME KEY!"
    std::map<std::string, std::string> playerSprites;
    playerSprites.insert(std::pair<std::string, std::string>("standing", "assets/sprites/Player/p1_front.png"));
    playerSprites.insert(std::pair<std::string, std::string>("running", "assets/sprites/Player/p1_walk/p1_walk.png"));
    playerSprites.insert(std::pair<std::string, std::string>("dodging", "assets/sprites/Player/p1_duck.png"));
    playerSprites.insert(std::pair<std::string, std::string>("jumping", "assets/sprites/Player/p1_jump.png"));
    playerSprites.insert(std::pair<std::string, std::string>("falling", "assets/sprites/Player/p1_jump.png"));
    return jumpyboy::Player::getInstance(100,100,50,70, playerSprites, frameRects, movingVariables);
}

Enemy* createFlyingEnemy(){
    //MUST CONTAIN DEAD! Path to all sprite sheets. MUST HAVE CORRESPONDING VECTORS IN frameRects WITH SAME KEY!"
    std::map<std::string, std::string> sprites;
    sprites.insert(std::pair<std::string, std::string>("moving", "assets/sprites/Enemies/enemies_spritesheet.png"));
    sprites.insert(std::pair<std::string, std::string>("dead", "assets/sprites/Enemies/enemies_spritesheet.png"));

    //MUST CONTAIN SAME KEYS AS sprites!! Contains all positions there are sprites in spritesheet, if not sprite sheet just use position 0,0,PictureWitdh,PictureHeight.
    std::vector<SDL_Rect> movingFrame{{0,32,72,36},{0,32,72,36},{0,32,72,36},{0,32,72,36},{0,32,72,36},{0,32,72,36},{0,0,75,31},{0,0,75,31},{0,0,75,31},{0,0,75,31},{0,0,75,31},{0,0,75,31}};
    std::vector<SDL_Rect> deadFrame{{143,0,59,33}};
    std::map<std::string, std::vector<SDL_Rect>> frameRects;
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("moving", movingFrame));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("dead", deadFrame));


    std::map<std::string, double> movingVariables;
    movingVariables.insert(std::pair<std::string, double>("speed", 3));
    movingVariables.insert(std::pair<std::string, double>("maxX", 1000));
    movingVariables.insert(std::pair<std::string, double>("minX", 300));
    movingVariables.insert(std::pair<std::string, double>("gravity", 0.2));
    movingVariables.insert(std::pair<std::string, double>("fallPower", 7));
    return FlyingEnemy::getInstance(30, 350, 50, 40, sprites, frameRects, movingVariables);
    //return
};

Enemy* createWalkingEnemy(){
    //MUST CONTAIN DEAD! Path to all sprite sheets. MUST HAVE CORRESPONDING VECTORS IN frameRects WITH SAME KEY!"
    std::map<std::string, std::string> sprites;
    sprites.insert(std::pair<std::string, std::string>("moving", "assets/sprites/Enemies/enemies_spritesheet.png"));
    sprites.insert(std::pair<std::string, std::string>("dead", "assets/sprites/Enemies/enemies_spritesheet.png"));

    //MUST CONTAIN SAME KEYS AS sprites!! Contains all positions there are sprites in spritesheet, if not sprite sheet just use position 0,0,PictureWitdh,PictureHeight.
    std::vector<SDL_Rect> movingFrame{{52,125,50,28},{52,125,50,28},{52,125,50,28},{52,125,50,28},{52,125,50,28},{0,125,51,26},{0,125,51,26},{0,125,51,26},{0,125,51,26},{0,125,51,26}};
    std::vector<SDL_Rect> deadFrame{{0,112,59,12}};
    std::map<std::string, std::vector<SDL_Rect>> frameRects;
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("moving", movingFrame));
    frameRects.insert(std::pair<std::string, std::vector<SDL_Rect>>("dead", deadFrame));


    std::map<std::string, double> movingVariables;
    movingVariables.insert(std::pair<std::string, double>("speed", 2));
    movingVariables.insert(std::pair<std::string, double>("gravity", 0.2));
    movingVariables.insert(std::pair<std::string, double>("fallPower", 7));
    movingVariables.insert(std::pair<std::string, double>("squishFactor", 0.35));
    return WalkingEnemy::getInstance(520, 300, 50, 40, sprites, frameRects, movingVariables);
    //return
};

LevelManager *createLvlMgr() {
    LevelManager* lvlMgr = LevelManager::getInstance();
    lvlMgr->addLevel(createFirstLevel());
    lvlMgr->addLevel(createSecondLevel());
    return lvlMgr;
}

Level *createFirstLevel() {
    Level* aLvl = Level::getInstance();
    std::vector<EnvironmentSprite*> collSprites;

    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/sprites/Tiles/grassMid.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));

    collSprites.push_back(EnvironmentSprite::getInstance(500, 420, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));

    for (EnvironmentSprite* sprite : collSprites){
        sprite->setCollisionStrategy(new GroundBehaivor());
        aLvl->addCollEnv(sprite);
    }

    aLvl->setBackGround(NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));

    aLvl->addEnemy(createFlyingEnemy());
    aLvl->addEnemy(createWalkingEnemy());

    return aLvl;
}

Level *createSecondLevel() {
    Level* aLvl = Level::getInstance();
    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/sprites/Tiles/sand.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));
    aLvl->addCollEnv(EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));
    aLvl->setBackGround(NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/sprites/i-know-c.jpg"));
    return aLvl;
}
