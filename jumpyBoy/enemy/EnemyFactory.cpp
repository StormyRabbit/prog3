//
// Created by lasse on 1/3/18.
//

#include "EnemyFactory.h"
#include "../CollisionStrategies/FlyingEnemyBehavior.h"

jumpyboy::FlyingEnemy *jumpyboy::EnemyFactory::fly(int x, int y, int w, int h, int maxX, int mixX, int speed) {
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
    movingVariables.insert(std::pair<std::string, double>("speed", speed));
    movingVariables.insert(std::pair<std::string, double>("maxX", maxX));
    movingVariables.insert(std::pair<std::string, double>("minX", mixX));
    movingVariables.insert(std::pair<std::string, double>("gravity", 0.2));
    movingVariables.insert(std::pair<std::string, double>("fallPower", 7));
    movingVariables.insert(std::pair<std::string, double>("bouncyPower", 9));
    jumpyboy::FlyingEnemy *fe = jumpyboy::FlyingEnemy::getInstance(x, y, w, h, sprites, frameRects, movingVariables);
    fe->setCollisionStrategy(new jumpyboy::FlyingEnemyBehavior());
    return fe;
}

jumpyboy::WalkingEnemy *jumpyboy::EnemyFactory::slime() {
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
    return jumpyboy::WalkingEnemy::getInstance(520, 300, 50, 40, sprites, frameRects, movingVariables);
}
