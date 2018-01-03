//
// Created by lasse on 1/3/18.
//

#include "PlayerFactory.h"
#include "../CollisionStrategies/PlayerCollBehavior.h"

jumpyboy::Player *jumpyboy::PlayerFactory::player() {
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
    jumpyboy::Player *p = jumpyboy::Player::getInstance(100,100,50,70, playerSprites, frameRects, movingVariables);
    p->setCollisionStrategy(new jumpyboy::PlayerCollBehavior());
    return p;
}
