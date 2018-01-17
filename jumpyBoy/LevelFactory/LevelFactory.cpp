//
// Created by lasse on 1/3/18.
//

#include "LevelFactory.h"
#include "../CollisionStrategies/GroundBehavior.h"
#include "../enemy/EnemyFactory.h"

namespace jumpyboy {

Level *jumpyboy::LevelFactory::firstLvl() {
    Level* aLvl = Level::getInstance();
    aLvl->textinput = rootengine::TextInputSprite::getInstance(100,100,50, 200, "Enter Name:");

    std::vector<rootengine::EnvironmentSprite*> collSprites;
    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/sprites/Tiles/grassMid.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(500, 400, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(300, 300, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(700, 200, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));

    for (rootengine::EnvironmentSprite* sprite : collSprites){
        sprite->setCollisionStrategy(new jumpyboy::GroundBehavior());
        aLvl->addCollEnv(sprite);
    }
    aLvl->setBackGround(rootengine::NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));
    typedef jumpyboy::EnemyFactory getEnemy;
    aLvl->addEnemy(getEnemy::fly(-150, 200, 50, 40, 500, 200, 3));
    aLvl->addEnemy(getEnemy::fly(-200, 300, 50, 40, 600, 300, 3));
    aLvl->addEnemy(getEnemy::fly(-100, 400, 50, 40, 700, 400, 3));
    return aLvl;
}

Level *jumpyboy::LevelFactory::secondLvl() {
    Level* aLvl = Level::getInstance();
    std::vector<rootengine::EnvironmentSprite*> collSprites;
    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/Ice expansion/Tiles/tundraMid.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(500, 400, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(300, 300, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(700, 200, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));
    for (rootengine::EnvironmentSprite* sprite : collSprites){
        sprite->setCollisionStrategy(new jumpyboy::GroundBehavior());
        aLvl->addCollEnv(sprite);
    }
    aLvl->setBackGround(rootengine::NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/Ice expansion/Tiles/iceWaterDeepAlt.png"));
    typedef jumpyboy::EnemyFactory getEnemy;
    aLvl->addEnemy(getEnemy::fly(-150, 200, 50, 40, 500, 200, 3));
    aLvl->addEnemy(getEnemy::fly(-200, 300, 50, 40, 600, 300, 3));
    aLvl->addEnemy(getEnemy::fly(-100, 400, 50, 40, 700, 400, 3));
    aLvl->addEnemy(getEnemy::fly(-50, 400, 50, 40, 500, 100, 3));
    return aLvl;
}
};
