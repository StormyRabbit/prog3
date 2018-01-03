//
// Created by lasse on 1/3/18.
//

#include "LevelFactory.h"
#include "../CollisionStrategies/GroundBehavior.h"
#include "../enemy/EnemyFactory.h"

rootengine::Level *jumpyboy::LevelFactory::firstLvl() {
    rootengine::Level* aLvl = rootengine::Level::getInstance();
    std::vector<rootengine::EnvironmentSprite*> collSprites;
    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/sprites/Tiles/grassMid.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(500, 420, 200, 20, spritesMapColl, frameMap));
    collSprites.push_back(rootengine::EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));
    for (rootengine::EnvironmentSprite* sprite : collSprites){
        sprite->setCollisionStrategy(new jumpyboy::GroundBehavior());
        aLvl->addCollEnv(sprite);
    }
    aLvl->setBackGround(rootengine::NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/sprites/bg_castle.png"));
    typedef jumpyboy::EnemyFactory getEnemy;
    aLvl->addEnemy(getEnemy::fly());
    //daLvl->addEnemy(getEnemy::slime());
    return aLvl;
}

rootengine::Level *jumpyboy::LevelFactory::secondLvl() {
    rootengine::Level* aLvl = rootengine::Level::getInstance();
    std::map<std::string, std::string> spritesMapColl;
    spritesMapColl.insert(std::pair<std::string, std::string>("default", "assets/sprites/Tiles/sand.png"));
    std::vector<SDL_Rect> rects{{0,0,70,70}};
    std::map<std::string, std::vector<SDL_Rect>> frameMap;
    frameMap.insert(std::pair<std::string, std::vector<SDL_Rect>>("default", rects ));
    aLvl->addCollEnv(rootengine::EnvironmentSprite::getInstance(0, 500, 1200, 100, spritesMapColl, frameMap));
    aLvl->setBackGround(rootengine::NonCollEnvironment::getInstance(0, 0, 1200, 600, "assets/sprites/i-know-c.jpg"));
    return aLvl;
}
